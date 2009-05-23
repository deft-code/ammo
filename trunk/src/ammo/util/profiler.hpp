#ifndef PROFILER_HPP
#define PROFILER_HPP

// Comment out this line to disable profiling
//#define PROFILINGENABLED

#ifdef PROFILINGENABLED

#include <string>
#include <assert.h>
#include <fstream>
#include <SFML/System.hpp>
#include <iostream>
namespace ammo
{
  // Profile Data struct, holds profiling data, should
  // never need these outside of the profiler and autotimer
  struct ProfileData
  {
    float totalTime;
    float minTime;
    float maxTime;
    int numCalls;
  };

  class Profiler
  {
  public:    

    // Writes data to the exe directory in a csv file.
    static void WriteData()
    {
      std::ofstream file;
      std::cout<<"Writing profiling data to profileData.csv"<<std::endl;

      file.open("profileData.csv");
      file << "Category Name,# of Calls,# Calls/Frame,Total Time,% of Total,Mean Time,Min Time,Max Time" << std::endl;
      
      float totalFrameTime = 0.f;
      for (int i = 0;  i < Max_Frames; i++)
      {
        totalFrameTime += _timeSteps[i];
      }

      // Write one line for each category
      for (int category = 0; category < _numCategories; category++)
      {
        float numCalls = 0.f;
        float callsPerFrame = 0.f;
        float totalTime = 0.f;
        float meanTime = 0.f;
        float minTime = (float)INT_MAX;
        float maxTime = 0.f;

        // Sum up the information for that category
        for (int frame = 0; (frame <= _currentFrame) || (_isFull && frame < Max_Frames); frame++)
        {
          numCalls += _data[category][frame].numCalls;  
          totalTime += _data[category][frame].totalTime;  
          maxTime = std::max(maxTime, _data[category][frame].maxTime);  
          minTime = std::min(minTime, _data[category][frame].minTime);  
        }

        if (!_isFull)
        {
          callsPerFrame = numCalls / (float)(_currentFrame+1);
          meanTime = totalTime / (float)(_currentFrame+1);
        }
        else
        {
        callsPerFrame = numCalls / (float)Max_Frames;
        meanTime = totalTime / (float)Max_Frames;
        }
        file << _categories[category] <<","<<numCalls <<","<<callsPerFrame<<","<<totalTime<<","<<100.f*(totalTime/totalFrameTime)<<"%,"<<meanTime<<","<<minTime<<","<<maxTime<<std::endl;
      }
      file.close();

    }
    
    // Gets the profile data for a category for the last frame
    // useful for displaying information to the screen, perhaps?
    static ProfileData GetProfileData(int category)
    {
      return  _data[category][_currentFrame];
    }

    // Registers a new category to the profiler. Use the 
    // macro PROFILE_TIMER(categoryname) to automatically
    // register a category and start a timer.
    static int RegisterCategory(std::string name)
    {
      assert(_numCategories < Max_Categories);
      int category = _numCategories++;
      _categories[category] = name;
      return category;
    }

    // Advance the profiler one frame. Currently the profiler
    // watches 600 frames of activity.
    static void NextFrame(float deltaTime)
    {     
      _currentFrame++;
      
      if (_currentFrame >= Max_Frames)
      {
        _isFull = true;
        _currentFrame = 0;
      }

      _timeSteps[_currentFrame] = deltaTime;
      for (int i = 0; i < Max_Categories; i++)
      {        
        _data[i][_currentFrame].totalTime = 0;
        _data[i][_currentFrame].maxTime = 0;
        _data[i][_currentFrame].minTime = (float)INT_MAX;
        _data[i][_currentFrame].numCalls = 0;
      }
    }

    // Called by the autotimer class to store information about a
    // category. Use PROFILE_TIMER(category) instead.
    static void Profile(int category, float time)
    {
      assert(category >= 0 && category < _numCategories);

      _data[category][_currentFrame].numCalls++;
      _data[category][_currentFrame].totalTime += time;
      _data[category][_currentFrame].maxTime = std::max( _data[category][_currentFrame].maxTime, time);
      _data[category][_currentFrame].minTime = std::min(_data[category][_currentFrame].minTime, time);
    }

  private:
    enum
    {
      // The maximum number of categories we can profile
      Max_Categories = 24,
      // The maximum number of frames we store profil info about
      Max_Frames = 600
    };

    static std::string _categories[Max_Categories];
    static ProfileData _data[Max_Categories][Max_Frames];
    static int _numCategories;
    static int _currentFrame;
    static bool _isFull;
    static float _timeSteps[Max_Frames];
  };

  

  // Simple automatic timer class, don't instantiate these directly.
  // use PROFILE_TIMER(category) instead.
  class AutoTimer
  {
  public:
    // Start our time when we create the object
    AutoTimer(int category) : _category(category)
    {
      _clock.Reset();

    }
    // Get the time and register it when we destroy our timer
    ~AutoTimer()
    {
      float elapsedTime = _clock.GetElapsedTime();
      Profiler::Profile(_category, elapsedTime);
    }
  private:
    int _category;
    sf::Clock _clock;
  };
}

// Creates a category, and starts an autotimer. When the timer goes out of
// scope, profiler information is saved. Correct usage is: PROFILE_TIMER(name)
// Do not use quotes, this is WRONG: PROFILE_TIMER("name")
#define PROFILE_TIMER(category)\
  static int myCategory_ ## category = ammo::Profiler::RegisterCategory( #category  ); \
  ammo::AutoTimer _timer_ ## category (myCategory_ ## category);

#define PROFILE_NEXT_FRAME(dt) ammo::Profiler::NextFrame(dt)

#define PROFILE_WRITE_DATA() ammo::Profiler::WriteData()

#else 
// If we haven't enabled profiling, define this macro as empty
// so we can keep our profiler macros in the code safely.
#define PROFILE_TIMER(category)
#define PROFILE_NEXT_FRAME( dt )
#define PROFILE_WRITE_DATA()
#endif // PROFILINGENABLED

#endif // PROFILER_HPP



#include "ammo/util/profiler.hpp"
#ifdef PROFILINGENABLED

namespace ammo
{
  float Profiler::_timeSteps[Profiler::Max_Frames] = {0.f};
  std::string Profiler::_categories[Profiler::Max_Categories];
  ProfileData Profiler::_data[Profiler::Max_Categories][Profiler::Max_Frames];
  int Profiler::_numCategories = 0;
  int Profiler::_currentFrame = -1;
  bool Profiler::_isFull = false;  
}

#endif


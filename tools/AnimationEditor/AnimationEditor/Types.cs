using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AnimationEditor
{
    public class SpriteSheet
    {
        public String Name {
            get { return this.m_name; }
            set { this.m_name = value; } }

        public String Path {
            get { return this.m_path; }
            set { this.m_path = value; } }

        public Texture2D Image {
            get { return this.m_image; }
            set { this.m_image = value; } }

        private String m_name;
        private String m_path;
        private Texture2D m_image;
    }

    public class Sprite
    {
        public String Name {
            get { return this.m_name; }
            set { this.m_name = value; } }

        public String SpriteSheetName {
            get { return this.m_spriteSheetName; }
            set { this.m_spriteSheetName = value; } }

        public Point Location {
            get { return this.m_location; }
            set { this.m_location = value; } }

        public Int32 Width {
            get { return this.m_width; }
            set { this.m_width = value; } }

        public Int32 Height {
            get { return this.m_height; }
            set { this.m_height = value; } }

        public Int32 ActualWidth {
            get { return this.m_actWidth; }
            set { this.m_actWidth = value; } }

        public Int32 ActualHeight {
            get { return this.m_actHeight; }
            set { this.m_actHeight = value; } }

        private String m_spriteSheetName;
        private String m_name;
        private Point m_location;
        private Int32 m_width, m_height;
        private Int32 m_actWidth, m_actHeight;
    }
}
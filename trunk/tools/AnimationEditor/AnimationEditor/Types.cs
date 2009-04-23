using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AnimationEditor
{
    public class SpriteSheet
    {
        public SpriteSheet() {
            this.m_zoom = 1.0f;
            this.m_location = new Vector2(0, 0); }

        public String Name {
            get { return this.m_name; }
            set { this.m_name = value; } }

        public String Path {
            get { return this.m_path; }
            set { this.m_path = value; } }

        public Texture2D Image {
            get { return this.m_image; }
            set { this.m_image = value; } }

        public Single Zoom {
            get { return this.m_zoom; } }

        public Vector2 Location {
            get { return this.m_location; }
            set { this.m_location = value; } }

        public Vector2 Center {
            get { return new Vector2(this.m_image.Width / 2, this.m_image.Height / 2); } }

        public void ZoomIn() {
            if (this.m_zoom < 10.00f)
                this.m_zoom += 0.25f; }

        public void ZoomOut() {
            if (this.m_zoom > 0.25f)
                this.m_zoom -= 0.25f; }

        private String m_name;
        private String m_path;
        private Texture2D m_image;
        private Single m_zoom;
        private Vector2 m_location;
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

        public Point DrawLocation {
            get { return this.m_drawLocation; }
            set { this.m_drawLocation = value; } }

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
        private Point m_drawLocation;
        private Int32 m_width, m_height;
        private Int32 m_actWidth, m_actHeight;
    }
}
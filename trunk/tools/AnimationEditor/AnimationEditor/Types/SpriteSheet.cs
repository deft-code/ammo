using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AnimationEditor
{
    public class SpriteSheet
    {
        private String m_name;
        private String m_path;
        private Texture2D m_image;
        private Single m_zoom;
        private Vector2 m_location;

        public SpriteSheet() {
            this.m_zoom = 1.0f;
            this.m_location = Vector2.Zero; }

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
    }
}
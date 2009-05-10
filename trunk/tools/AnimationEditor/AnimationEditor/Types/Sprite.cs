using System;
using System.Drawing;

namespace AnimationEditor
{
    public class Sprite
    {
        private String imageName;
        private String spriteName;
        private Rectangle dimensions;
        private Rectangle actualDimensions;

        public Sprite(String imageName, String spriteName, Rectangle dimensions)
        {
            this.imageName = imageName;
            this.spriteName = spriteName;
            this.dimensions = dimensions;
            this.actualDimensions = dimensions;
        }

        public String ImageName {
            get { return this.imageName; }
            set { this.imageName = value; } }

        public String SpriteName {
            get { return this.spriteName; }
            set { this.spriteName = value; } }

        public Rectangle Dimensions {
            get { return this.dimensions; }
            set { this.dimensions = value; } }

        public Rectangle ActualDimensions {
            get { return this.actualDimensions; }
            set { this.actualDimensions = value; } }
    }
}
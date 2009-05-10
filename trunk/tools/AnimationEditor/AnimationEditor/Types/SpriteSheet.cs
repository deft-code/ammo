using System;
using System.Drawing;
using System.Collections.Generic;
using Microsoft.Xna.Framework.Graphics;

namespace AnimationEditor
{
    public class SpriteSheet
    {
        private const Single MAX_ZOOM = 10.0f;
        private const Single MIN_ZOOM = 0.25f;
        private const Single ZOOM_TICK = 0.25f;

        private Texture2D image;
        private Single zoom;
        private Microsoft.Xna.Framework.Vector2 origin;
        private Microsoft.Xna.Framework.Vector2 location;
        private Viewport viewPort;
        private List<Sprite> spriteList;
        private Int32 spriteCount;

        public SpriteSheet(Texture2D image, Viewport viewPort)
        {
            this.image = image;
            this.viewPort = viewPort;

            this.origin = new Microsoft.Xna.Framework.Vector2(this.image.Width / 2, this.image.Height / 2);
            this.location = this.origin;
            this.spriteList = new List<Sprite>();
            this.spriteCount = 0;

            this.zoom = 1.0f;
        }

        public void Draw(SpriteBatch sb)
        {
            sb.Draw(this.image, this.location, null,
                Microsoft.Xna.Framework.Graphics.Color.White,
                0.0f, this.origin, this.zoom, SpriteEffects.None, 1.0f);
        }

        public void Move(Point curMousePos, Point prvMousePos)
        {
            this.location.X -= (prvMousePos.X - curMousePos.X);
            this.location.Y -= (prvMousePos.Y - curMousePos.Y);
        }

        public void ZoomIn()
        {
            if (this.zoom < MAX_ZOOM)
            {
                this.zoom += ZOOM_TICK;
            }
        }

        public void ZoomOut()
        {
            if (this.zoom > MIN_ZOOM)
            {
                this.zoom -= ZOOM_TICK;
            }
        }

        public void AddSprite(Rectangle sprite, String imageName, String spriteName)
        {
            if (spriteName == null)
            {
                this.spriteList.Add(new Sprite(imageName, "sprite" + this.spriteCount, sprite));
            }
            else
            {
                this.spriteList.Add(new Sprite(imageName, spriteName, sprite));
            }
        }

        public void DeleteSprite(Int32 index)
        {
            this.spriteList.RemoveAt(index);
        }

        public Point MousePositionRelativeToImage(Point mousePos)
        {
            Point relativeLocation = this.RelativeLocation;
            return new Point(((Int32)(mousePos.X / this.zoom)) - relativeLocation.X,
                             ((Int32)(mousePos.Y / this.zoom)) - relativeLocation.Y);
        }

        public Point AbsoluteLocation
        {
            get
            {
                return new Point((Int32)(this.location.X - this.origin.X),
                                 (Int32)(this.location.Y - this.origin.Y));
            }
        }

        public Point RelativeLocation
        {
            get
            {
                Viewport newView = this.viewPort;
                newView.Width = (Int32)(newView.Width / this.zoom);
                newView.Height = (Int32)(newView.Height / this.zoom);

                Point relativeLocation = this.AbsoluteLocation;
                relativeLocation.X -= (Int32)((this.viewPort.Width - newView.Width) / (this.viewPort.Width / this.location.X));
                relativeLocation.Y -= (Int32)((this.viewPort.Height - newView.Height) / (this.viewPort.Height / this.location.Y));

                return relativeLocation;                 
            }
        }

        public Single Zoom
        {
            get { return this.zoom; }
        }

        public Viewport Viewport
        {
            get { return this.viewPort; }
            set { this.viewPort = value; }
        }
    }
}
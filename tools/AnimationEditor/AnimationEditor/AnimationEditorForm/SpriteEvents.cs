using System;
using System.Drawing;
using System.Windows.Forms;

namespace AnimationEditor
{
    public partial class AnimationEditorForm : Form
    {
        private void SpriteMouseDown(Object sender, MouseEventArgs e)
        {
        }

        private void SpriteMouseUp(Object sender, MouseEventArgs e)
        {
        }

        private void SpriteMouseMove(Object sender, MouseEventArgs e)
        {
            if (this.imageList.Count > 0)
            {
                // Move image
                if ((e.Button == MouseButtons.Left) && (this.imageAdded != true))
                {
                    this.imageList[this.selectedImage].Move(e.Location, this.prvMousePos);
                }
                this.imageAdded = false;

                // Display mouse position relative to image
                Point mousePos = this.imageList[this.selectedImage].MousePositionRelativeToImage(e.Location);
                this.spriteUpdateBar_MousePos.Text = "( " + mousePos.X + ", " + mousePos.Y + " )";
            }
            else
            {
                // No image loaded, just display true mouse coordinates
                this.spriteUpdateBar_MousePos.Text = "( " + e.X + ", " + e.Y + " )";
            }

            // Update the previous mouse position
            this.prvMousePos = e.Location;
        }

        private void SpriteMouseWheel(Object sender, MouseEventArgs e)
        {
            if (this.imageList.Count > 0)
            {
                if (e.Delta > 0)
                {
                    this.imageList[this.selectedImage].ZoomIn();
                }
                else if (e.Delta < 0)
                {
                    this.imageList[this.selectedImage].ZoomOut();
                }

                // Display mouse position relative to image and update the zoom box
                Point mousePos = this.imageList[this.selectedImage].MousePositionRelativeToImage(e.Location);
                this.spriteUpdateBar_MousePos.Text = "( " + mousePos.X + ", " + mousePos.Y + " )";
                this.spriteUpdateBar_Zoom.Text = (this.imageList[this.selectedImage].Zoom * 100) + "%";
            }
        }

        private void SpriteMouseEnter(Object sender, EventArgs e)
        {
            this.panel_SpriteGraphics.Focus();
        }

        private void SpriteMouseLeave(Object sender, EventArgs e)
        {
            this.Focus();
            this.spriteUpdateBar_MousePos.Text = "( 0, 0 )";
        }

        private void SpriteViewportChanged(object sender, EventArgs e)
        {
            Microsoft.Xna.Framework.Graphics.PresentationParameters newPP =
                this.spriteGraphics.Graphics.GraphicsDevice.PresentationParameters;

            newPP.BackBufferWidth = this.panel_SpriteGraphics.Width;
            newPP.BackBufferHeight = this.panel_SpriteGraphics.Height;

            this.spriteGraphics.Graphics.GraphicsDevice.Reset(newPP);

            for (Int32 i = 0; i < this.imageList.Count; i++)
            {
                this.imageList[i].Viewport = this.spriteGraphics.Graphics.GraphicsDevice.Viewport;
            }
        }
    }
}
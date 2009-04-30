using System;
using System.Windows.Forms;
using Microsoft.Xna.Framework;

namespace AnimationEditor
{
    public partial class AnimationEditorForm : Form
    {
        private Boolean leftMouseDown = false;
        private Point correctedMouseCoordinates;
        private Point previousMouseCoordinates;

        private void panel_SpriteGraphics_MouseEnter(object sender, EventArgs e)
        {
            this.panel_SpriteGraphics.Focus();
        }

        private void panel_SpriteGraphics_MouseLeave(object sender, EventArgs e)
        {
            this.correctedMouseCoordinates = Point.Zero;
            this.spriteUpdateBar_MousePos.Text = "( 0, 0 )";
            this.Focus();
        }

        private void panel_SpriteGraphics_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
                this.leftMouseDown = true;
        }

        private void panel_SpriteGraphics_MouseUp(object sender, MouseEventArgs e)
        {
            this.leftMouseDown = false;
        }

        private void panel_SpriteGraphics_MouseWheel(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            if (this.imageList.Count > 0)
            {
                if (e.Delta > 0)
                    this.imageList[this.listBox_LoadedImages.SelectedIndex].ZoomIn();
                else if (e.Delta < 0)
                    this.imageList[this.listBox_LoadedImages.SelectedIndex].ZoomOut();

                this.spriteUpdateBar_Zoom.Text = (this.imageList[this.listBox_LoadedImages.SelectedIndex].Zoom * 100.0f) + "%";
                this.spriteUpdateBar_MousePos.Text = "( " + this.correctedMouseCoordinates.X +
                                                     ", " + this.correctedMouseCoordinates.Y + " )";
            }
        }

        private void panel_SpriteGraphics_MouseMove(object sender, MouseEventArgs e)
        {
            if (this.imageList.Count > 0)
            {
                Single correction = 1.0f / this.imageList[this.listBox_LoadedImages.SelectedIndex].Zoom;
                this.correctedMouseCoordinates.X = (Int32)((Single)e.X * correction);
                this.correctedMouseCoordinates.Y = (Int32)((Single)e.Y * correction);

                if (this.leftMouseDown == true)
                {
                    int xDelta = this.previousMouseCoordinates.X - e.X;
                    int yDelta = this.previousMouseCoordinates.Y - e.Y;
                    this.imageList[this.listBox_LoadedImages.SelectedIndex].Location = new Vector2(
                        this.imageList[this.listBox_LoadedImages.SelectedIndex].Location.X - xDelta,
                        this.imageList[this.listBox_LoadedImages.SelectedIndex].Location.Y - yDelta);
                }
            }
            else
            {
                this.correctedMouseCoordinates.X = e.X;
                this.correctedMouseCoordinates.Y = e.Y;
            }
            this.previousMouseCoordinates.X = e.X;
            this.previousMouseCoordinates.Y = e.Y;
            this.spriteUpdateBar_MousePos.Text = "( " + this.correctedMouseCoordinates.X +
                                                 ", " + this.correctedMouseCoordinates.Y + " )";
        }

        private void button_LoadImage_Click(object sender, EventArgs e)
        {
            this.LoadImageEvent();
        }
    }
}
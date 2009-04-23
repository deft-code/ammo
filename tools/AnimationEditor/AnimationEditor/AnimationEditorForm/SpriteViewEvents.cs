using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.Xna.Framework;

namespace AnimationEditor
{
    public partial class AnimationEditorForm : Form
    {
        private Boolean m_shiftClick = false;
        private Boolean m_mouseLeftDown = false;
        private Vector2 m_actualMouseCoordinates = new Vector2(0, 0);
        private Vector2 m_previousMousePos = new Vector2(0, 0);

        private void panel_spriteViewer_MouseLeave(object sender, EventArgs e)
        {
            this.m_actualMouseCoordinates.X = 0;
            this.m_actualMouseCoordinates.Y = 0;
            this.updateBar_MousePos.Text = "( 0, 0 )";
        }

        private void panel_spriteViewer_MouseMove(object sender, MouseEventArgs e)
        {
            if (this.m_images.Count > 0)
            {
                this.m_actualMouseCoordinates.X = (Int32)((Single)e.X * ( 1.0f / this.m_images[this.listBox_LoadedImages.SelectedIndex].Zoom));
                this.m_actualMouseCoordinates.Y = (Int32)((Single)e.Y * ( 1.0f / this.m_images[this.listBox_LoadedImages.SelectedIndex].Zoom));

                if (this.m_shiftClick)
                {
                    int xDelta = (Int32)m_previousMousePos.X - e.X;
                    int yDelta = (Int32)m_previousMousePos.Y - e.Y;
                    this.m_images[this.listBox_LoadedImages.SelectedIndex].Location =
                        new Vector2(this.m_images[this.listBox_LoadedImages.SelectedIndex].Location.X - xDelta,
                                    this.m_images[this.listBox_LoadedImages.SelectedIndex].Location.Y - yDelta);

                    for (int i = 0; i < this.listBox_LoadedSprites.Items.Count; i++)
                    {
                        this.m_sprites[this.listBox_LoadedImages.SelectedIndex][this.listBox_LoadedSprites.SelectedIndex].DrawLocation =
                            new Point(this.m_sprites[this.listBox_LoadedImages.SelectedIndex][this.listBox_LoadedSprites.SelectedIndex].DrawLocation.X - xDelta,
                                      this.m_sprites[this.listBox_LoadedImages.SelectedIndex][this.listBox_LoadedSprites.SelectedIndex].DrawLocation.Y - yDelta);
                    }
                }

                else if ((this.m_mouseLeftDown) && (this.listBox_LoadedSprites.Items.Count > 0))
                {
                    int image = this.listBox_LoadedImages.SelectedIndex;
                    int sprite = this.listBox_LoadedSprites.SelectedIndex;

                    if ((this.m_actualMouseCoordinates.X > this.m_sprites[image][sprite].Location.X) &&
                        (this.m_actualMouseCoordinates.Y > this.m_sprites[image][sprite].Location.Y))
                    {
                        this.m_sprites[image][sprite].Width = (Int32)this.m_actualMouseCoordinates.X - this.m_sprites[image][sprite].Location.X;
                        this.m_sprites[image][sprite].Height = (Int32)this.m_actualMouseCoordinates.Y - this.m_sprites[image][sprite].Location.Y;

                        this.textBox_SpriteInformation_Width.Text = this.m_sprites[image][sprite].Width.ToString();
                        this.textBox_SpriteInformation_Height.Text = this.m_sprites[image][sprite].Height.ToString();
                    }
                }
            }
            else
            {
                this.m_actualMouseCoordinates.X = e.X;
                this.m_actualMouseCoordinates.Y = e.Y;
            }
            m_previousMousePos.X = e.X;
            m_previousMousePos.Y = e.Y;
            this.updateBar_MousePos.Text = "( " + this.m_actualMouseCoordinates.X + ", " + this.m_actualMouseCoordinates.Y + " )";
        }

        private void panel_spriteViewer_MouseEnter(object sender, EventArgs e)
        {
            this.panel_spriteViewer.Focus();
        }

        private void panel_spriteViewer_MouseDown(object sender, MouseEventArgs e)
        {
            if (this.m_images.Count > 0)
            {
                // Ctrl + Click AddSprite() for adding sprites
                if (((Control.ModifierKeys & Keys.Control) == Keys.Control) && (e.Button == MouseButtons.Left))
                    this.AddSprite(new Point((Int32)this.m_actualMouseCoordinates.X, (Int32)this.m_actualMouseCoordinates.Y), new Point(e.X, e.Y));

                // Shift + Click for moving sprite sheet
                else if (((Control.ModifierKeys & Keys.Shift) == Keys.Shift) && (e.Button == MouseButtons.Left))
                    this.m_shiftClick = true;

                else
                {
                    if (e.Button == MouseButtons.Left)
                    {
                    }
                    else if (e.Button == MouseButtons.Right)
                    {
                    }
                }

                this.m_mouseLeftDown = true;
            }
        }

        private void panel_spriteViewer_MouseUp(object sender, MouseEventArgs e)
        {
            this.m_shiftClick = false;
            this.m_mouseLeftDown = false;
        }

        private void panel_spriteViewer_MouseWheel(object sender, MouseEventArgs e)
        {
            if ((this.m_images.Count > 0) && (!this.m_shiftClick))
            {
                if (e.Delta > 0)
                    this.m_images[this.listBox_LoadedImages.SelectedIndex].ZoomIn();
                else if (e.Delta < 0)
                    this.m_images[this.listBox_LoadedImages.SelectedIndex].ZoomOut();

                this.m_actualMouseCoordinates.X = (Int32)((Single)e.X * (1.0f / this.m_images[this.listBox_LoadedImages.SelectedIndex].Zoom));
                this.m_actualMouseCoordinates.Y = (Int32)((Single)e.Y * (1.0f / this.m_images[this.listBox_LoadedImages.SelectedIndex].Zoom));
                this.updateBar_Zoom.Text = (this.m_images[this.listBox_LoadedImages.SelectedIndex].Zoom * 100.0f) + "%";


            }
            else
            {
                this.m_actualMouseCoordinates.X = e.X;
                this.m_actualMouseCoordinates.Y = e.Y;
            }
            this.updateBar_MousePos.Text = "( " + this.m_actualMouseCoordinates.X + ", " + this.m_actualMouseCoordinates.Y + " )";
        }
    }
}
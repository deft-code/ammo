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
                    this.m_images[this.listBox_LoadedImages.SelectedIndex].Location =
                        new Vector2(this.m_images[this.listBox_LoadedImages.SelectedIndex].Location.X - (m_previousMousePos.X - e.X),
                            this.m_images[this.listBox_LoadedImages.SelectedIndex].Location.Y - (m_previousMousePos.Y - e.Y));
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
                    this.AddSprite();

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
            }
        }

        private void panel_spriteViewer_MouseUp(object sender, MouseEventArgs e)
        {
            this.m_shiftClick = false;
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
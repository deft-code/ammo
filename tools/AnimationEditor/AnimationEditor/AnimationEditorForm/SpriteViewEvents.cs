using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace AnimationEditor
{
    public partial class AnimationEditorForm : Form
    {
        private bool m_escDown = false;

        private void panel_spriteViewer_MouseLeave(object sender, EventArgs e)
        {
            this.updateBar_MousePos.Text = "( 0, 0 )";
        }

        private void panel_spriteViewer_MouseMove(object sender, MouseEventArgs e)
        {
            this.updateBar_MousePos.Text = "( " + e.X + ", " + e.Y + " )";
        }

        private void panel_spriteViewer_MouseClick(object sender, MouseEventArgs e)
        {
            // Ctrl + Click AddSprite()
            if ((Control.ModifierKeys & Keys.Control) == Keys.Control)
            {
                this.AddSprite();
            }
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
}
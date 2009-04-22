using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using XNAControl;

namespace AnimationEditor
{
    public partial class AnimationEditorForm : Form
    {
        // Draw event
        private void m_drawTimer_Tick(object sender, EventArgs e)
        {
            // Sprite view
            this.m_spritePanel.Graphics.BeginDraw();
            this.DrawSpritePanel();
            this.m_spritePanel.Graphics.EndDraw();

            // Annimation preview
            this.m_annimationPreviewPanel.Graphics.BeginDraw();
            this.m_annimationPreviewPanel.Graphics.EndDraw();
        }

        private void DrawSpritePanel()
        {
            this.m_spritePanel.SpriteBatch.Begin(SpriteBlendMode.AlphaBlend);

            // Draw currently selected image
            if (this.listBox_LoadedImages.Items.Count != 0)
            {
                this.m_spritePanel.SpriteBatch.Draw(this.m_images[this.listBox_LoadedImages.SelectedIndex].Image,
                    Vector2.Zero, Color.White);
            }

            this.m_spritePanel.SpriteBatch.End();
        }
    }
}
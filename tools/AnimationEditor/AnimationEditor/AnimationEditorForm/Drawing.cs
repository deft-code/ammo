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
            // Draw currently selected image
            if (this.listBox_LoadedImages.Items.Count > 0)
            {
                this.m_spritePanel.SpriteBatch.Begin(SpriteBlendMode.AlphaBlend, SpriteSortMode.Immediate, SaveStateMode.None);

                this.m_spritePanel.SpriteBatch.Draw(this.m_images[this.listBox_LoadedImages.SelectedIndex].Image,
                    this.m_images[this.listBox_LoadedImages.SelectedIndex].Location, null, Color.White, 0.0f,
                    this.m_images[this.listBox_LoadedImages.SelectedIndex].Center,
                    this.m_images[this.listBox_LoadedImages.SelectedIndex].Zoom, SpriteEffects.None, 1.0f);

                this.m_spritePanel.SpriteBatch.End();

                if (this.listBox_LoadedSprites.Items.Count > 0)
                {
                    foreach (Sprite sprite in this.m_sprites[this.listBox_LoadedImages.SelectedIndex])
                    {
                        PrimitiveDrawer.DrawRectangle(new Vector2(sprite.DrawLocation.X, sprite.DrawLocation.Y),
                            sprite.Width * this.m_images[this.listBox_LoadedImages.SelectedIndex].Zoom,
                            sprite.Height * this.m_images[this.listBox_LoadedImages.SelectedIndex].Zoom, Color.Red);
                    }
                }
            }
        }
    }
}
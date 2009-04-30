using System;
using System.Windows.Forms;
using Microsoft.Xna.Framework.Graphics;

namespace AnimationEditor
{
    public partial class AnimationEditorForm : Form
    {
        // Changed active program tab
        private void tabControl_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (this.tabControl.SelectedTab.Text == "Sprites")
                this.mode = ProgramMode.Sprite;
            else if (this.tabControl.SelectedTab.Text == "Animations")
                this.mode = ProgramMode.Animation;
        }

        // Draw event
        private void drawTimer_Tick(object sender, EventArgs e)
        {
            switch (this.mode)
            {
                case ProgramMode.Sprite:
                    {
                        this.spriteGraphics.Graphics.BeginDraw();
                        this.DrawSpritePanel();
                        this.spriteGraphics.Graphics.EndDraw();
                    } break;

                case ProgramMode.Animation:
                    {
                        this.animationGraphics.Graphics.BeginDraw();
                        this.animationGraphics.Graphics.EndDraw();
                    } break;

                default:
                    break;
            }
        }

        // Resize window
        private void AnimationEditorForm_SizeChanged(object sender, EventArgs e)
        {
            PresentationParameters spritePP = this.spriteGraphics.Graphics.GraphicsDevice.PresentationParameters;
            PresentationParameters animationPP = this.animationGraphics.Graphics.GraphicsDevice.PresentationParameters;

            spritePP.BackBufferWidth = this.panel_SpriteGraphics.Width;
            spritePP.BackBufferHeight = this.panel_SpriteGraphics.Height;

            animationPP.BackBufferWidth = this.panel_AnimationGraphics.Width;
            animationPP.BackBufferHeight = this.panel_AnimationGraphics.Height;

            this.spriteGraphics.Graphics.GraphicsDevice.Reset(spritePP);
            this.animationGraphics.Graphics.GraphicsDevice.Reset(animationPP);
        }
    }
}
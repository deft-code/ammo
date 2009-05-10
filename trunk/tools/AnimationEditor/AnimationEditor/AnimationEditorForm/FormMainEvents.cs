using System;
using System.Windows.Forms;
using System.Collections.Generic;

namespace AnimationEditor
{
    public partial class AnimationEditorForm : Form
    {
        private void drawTimer_Tick(Object sender, EventArgs e)
        {
            switch (this.mode)
            {
                case ProgramMode.Sprite:
                    {
                        this.spriteGraphics.Graphics.BeginDraw();
                        this.DrawSpriteSheet();
                        this.spriteGraphics.Graphics.EndDraw();
                    } break;

                case ProgramMode.Animation:
                    {
                    } break;

                default:
                    break;
            }
        }

        private void SelectedImageChanged(Object sender, EventArgs e)
        {
            this.selectedImage = this.listBox_LoadedImages.SelectedIndex;
        }

        private void LoadImageButtonClick(Object sender, EventArgs e)
        {
            this.LoadImage();
        }
    }
}
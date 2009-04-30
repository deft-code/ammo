using System;
using System.Collections.Generic;
using System.Windows.Forms;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace AnimationEditor
{
    public partial class AnimationEditorForm : Form
    {
        private List<SpriteSheet> imageList = new List<SpriteSheet>();

        private bool LoadImageEvent()
        {
            OpenFileDialog ofd = new OpenFileDialog();

            ofd.Filter = "Image (*.png)|*.png";
            ofd.Title = "Load Image...";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    SpriteSheet newSS = new SpriteSheet();

                    newSS.Image = Texture2D.FromFile(this.spriteGraphics.Graphics.GraphicsDevice, ofd.FileName);
                    newSS.Path = ofd.FileName;
                    newSS.Name = ofd.FileName.Substring(ofd.FileName.LastIndexOf('\\') + 1);
                    newSS.Location = newSS.Center;

                    this.imageList.Add(newSS);

                    this.listBox_LoadedImages.Items.Add(newSS.Name);
                    this.listBox_LoadedImages.SelectedIndex = this.imageList.Count - 1;
                }
                catch
                {
                    MessageBox.Show("Unable to load \"" + ofd.FileName + "\"");
                    return false;
                }
            }

            return true;
        }

        private void DrawSpritePanel()
        {
            // Draw currently selected image
            if (this.listBox_LoadedImages.Items.Count > 0)
            {
                Int32 imageIndex = this.listBox_LoadedImages.SelectedIndex;
                this.spriteGraphics.SpriteBatch.Begin(SpriteBlendMode.AlphaBlend, SpriteSortMode.Immediate, SaveStateMode.None);

                this.spriteGraphics.SpriteBatch.Draw(this.imageList[imageIndex].Image,
                    this.imageList[imageIndex].Location, null, Color.White, 0.0f,
                    this.imageList[imageIndex].Center,
                    this.imageList[imageIndex].Zoom, SpriteEffects.None, 1.0f);

                this.spriteGraphics.SpriteBatch.End();
            }
        }
    }
}
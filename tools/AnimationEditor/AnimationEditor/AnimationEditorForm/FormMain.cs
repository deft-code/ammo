using System;
using System.Drawing;
using System.Windows.Forms;
using System.Collections.Generic;
using Microsoft.Xna.Framework.Graphics;
using XNAControl;

namespace AnimationEditor
{
    public enum ProgramMode
    {
        Sprite, Animation
    }

    public partial class AnimationEditorForm : Form
    {
        private ProgramMode mode = ProgramMode.Sprite;

        private XNAGraphicsControl spriteGraphics;
        private Timer drawTimer;

        private List<SpriteSheet> imageList;
        private Int32 selectedImage;

        private Point prvMousePos;
        private Boolean imageAdded;

        public AnimationEditorForm()
        {
            this.InitializeComponent();
            this.InitializeApp();
        }

        private void InitializeApp()
        {
            this.spriteGraphics = new XNAGraphicsControl(this.panel_SpriteGraphics);
            PrimitiveDrawer.Initialize(this.spriteGraphics.Graphics.GraphicsDevice);

            this.imageList = new List<SpriteSheet>();
            this.imageAdded = false;

            this.drawTimer = new Timer();
            this.drawTimer.Tick += new EventHandler(drawTimer_Tick);
            this.drawTimer.Interval = 1000 / 60;
            this.drawTimer.Start();
        }

        private void LoadImage()
        {
            OpenFileDialog ofd = new OpenFileDialog();
            
            ofd.Filter = "Image (*.png)|*.png";
            ofd.Title = "Load Image...";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    Texture2D newImage = Texture2D.FromFile(this.spriteGraphics.Graphics.GraphicsDevice, ofd.FileName);

                    this.imageList.Add(new SpriteSheet(newImage, this.spriteGraphics.Graphics.GraphicsDevice.Viewport));
                    this.selectedImage = (this.imageList.Count - 1);

                    this.listBox_LoadedImages.Items.Add(ofd.FileName.Substring(ofd.FileName.LastIndexOf('\\') + 1));
                    this.listBox_LoadedImages.SelectedIndex = this.selectedImage;
                    this.imageAdded = true;
                }
                catch
                {
                    MessageBox.Show("Unable to open \"" + ofd.FileName + "\"");
                }
            }
        }

        private void DrawSpriteSheet()
        {
            if (this.imageList.Count > 0)
            {
                this.spriteGraphics.SpriteBatch.Begin(SpriteBlendMode.AlphaBlend, SpriteSortMode.Immediate, SaveStateMode.None);
                this.spriteGraphics.Graphics.GraphicsDevice.SamplerStates[0].MagFilter = TextureFilter.None;
                this.imageList[this.selectedImage].Draw(this.spriteGraphics.SpriteBatch);
                this.spriteGraphics.SpriteBatch.End();
            }
        }
    }
}

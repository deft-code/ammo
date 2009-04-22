using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;
using XNAControl;

namespace AnimationEditor
{
    public partial class AnimationEditorForm : Form
    {
        private XNAGraphicsControl m_spritePanel;
        private XNAGraphicsControl m_annimationPreviewPanel;

        private Timer m_drawTimer;

        private List<SpriteSheet> m_images = new List<SpriteSheet>();
        private List<List<Sprite>> m_sprites = new List<List<Sprite>>();

        private UInt32 m_spriteCount = 1;

        public AnimationEditorForm()
        {
            this.InitializeComponent();
            this.InitializeApp();
        }

        public new Object GetService(Type serviceType)
        {
            if (serviceType == typeof(IGraphicsDeviceService))
                return this.m_spritePanel.Graphics;
            else
                return null;
        }

        private void InitializeApp()
        {
            this.m_spritePanel = new XNAGraphicsControl(this.panel_spriteViewer);
            this.m_annimationPreviewPanel = new XNAGraphicsControl(this.panel_annimationPreview);
            PrimitiveDrawer.Initialize(this.m_spritePanel.Graphics.GraphicsDevice);

            this.m_drawTimer = new Timer();
            this.m_drawTimer.Tick += new EventHandler(m_drawTimer_Tick);
            this.m_drawTimer.Interval = 1000 / 60;
            this.m_drawTimer.Start();
        }

        private void EnableSpriteInformation()
        {
            this.listBox_LoadedSprites.Enabled = true;
            this.button_CreateNewSprite.Enabled = true;
            this.button_DeleteSprite.Enabled = true;
            this.groupBox_SpriteInformation.Enabled = true;
        }

        private void EnableAnimation()
        {
            this.button_AddAnimation.Enabled = true;
            this.button_DeleteAnimation.Enabled = true;
            this.listBox_Animations.Enabled = true;
            this.groupBox_AnimationInformation.Enabled = true;
        }

        private void DisableSpriteInformation()
        {
            this.listBox_LoadedSprites.Enabled = false;
            this.button_CreateNewSprite.Enabled = false;
            this.button_DeleteSprite.Enabled = false;
            this.groupBox_SpriteInformation.Enabled = false;
        }

        private void DisableAnimation()
        {
            this.button_AddAnimation.Enabled = false;
            this.button_DeleteAnimation.Enabled = false;
            this.listBox_Animations.Enabled = false;
            this.groupBox_AnimationInformation.Enabled = false;
        }

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

                    newSS.Image = Texture2D.FromFile(this.m_spritePanel.Graphics.GraphicsDevice, ofd.FileName);
                    newSS.Path = ofd.FileName;
                    newSS.Name = ofd.FileName.Substring(ofd.FileName.LastIndexOf('\\') + 1);
                    newSS.Location = newSS.Center;

                    this.m_images.Add(newSS);
                    this.m_sprites.Add(new List<Sprite>());

                    this.listBox_LoadedImages.Items.Add(newSS.Name);
                    this.listBox_LoadedImages.SelectedIndex = this.m_images.Count - 1;

                    this.EnableSpriteInformation();
                }
                catch
                {
                    MessageBox.Show("Unable to load \"" + ofd.FileName + "\"");
                    return false;
                }
            }

            return true;
        }

        private void RemoveImageEvent()
        {
            if ((this.m_images.Count != 0) && (this.listBox_LoadedImages.Items.Count != 0))
            {
                int index = this.listBox_LoadedImages.SelectedIndex;

                this.m_images.Remove(this.m_images[index]);
                this.m_sprites.Remove(this.m_sprites[index]);
                this.listBox_LoadedSprites.Items.Clear();
                this.listBox_LoadedImages.Items.Remove(this.listBox_LoadedImages.Items[index]);

                if (index >= this.listBox_LoadedImages.Items.Count)
                    this.listBox_LoadedImages.SelectedIndex = this.listBox_LoadedImages.Items.Count - 1;
                else
                    this.listBox_LoadedImages.SelectedIndex = index;

                if (this.m_images.Count == 0)
                {
                    this.DisableSpriteInformation();
                    this.updateBar_Zoom.Text = "100%";
                }
            }
        }

        private void AddSprite()
        {
            if (this.m_images.Count != 0)
            {
                int imgIndex = this.listBox_LoadedImages.SelectedIndex;
                int spriteIndex = 0;

                this.m_sprites[imgIndex].Add(new Sprite());
                spriteIndex = this.m_sprites[imgIndex].Count - 1;

                this.m_sprites[imgIndex][spriteIndex].SpriteSheetName = this.m_images[imgIndex].Name;
                this.m_sprites[imgIndex][spriteIndex].Name = "Sprite" + m_spriteCount++;
                this.m_sprites[imgIndex][spriteIndex].Location = new Point(0, 0);
                this.m_sprites[imgIndex][spriteIndex].Width = 0;
                this.m_sprites[imgIndex][spriteIndex].Height = 0;
                this.m_sprites[imgIndex][spriteIndex].ActualWidth = 0;
                this.m_sprites[imgIndex][spriteIndex].ActualHeight = 0;

                this.listBox_LoadedSprites.Items.Add(this.m_sprites[imgIndex][spriteIndex].Name);
                this.listBox_LoadedSprites.SelectedIndex = spriteIndex;

                this.textBox_SpriteInformation_Name.Text = this.m_sprites[imgIndex][spriteIndex].Name;
                this.textBox_SpriteInformation_X.Text = "0";
                this.textBox_SpriteInformation_Y.Text = "0";
                this.textBox_SpriteInformation_Width.Text = "0";
                this.textBox_SpriteInformation_Height.Text = "0";
                this.textBox_SpriteInformation_AWidth.Text = "0";
                this.textBox_SpriteInformation_AHeight.Text = "0";
            }
        }

        private void panel_spriteViewer_SizeChanged(object sender, EventArgs e)
        {
            PresentationParameters newPP = this.m_spritePanel.Graphics.GraphicsDevice.PresentationParameters;
            newPP.BackBufferWidth = this.panel_spriteViewer.Width;
            newPP.BackBufferHeight = this.panel_spriteViewer.Height;
            this.m_spritePanel.Graphics.GraphicsDevice.Reset(newPP);
        }
    }
}

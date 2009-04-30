using System;
using System.Windows.Forms;
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
        private XNAGraphicsControl animationGraphics;

        private Timer drawTimer;

        public AnimationEditorForm()
        {
            this.InitializeComponent();
            this.InitializeApp();
        }

        private void InitializeApp()
        {
            this.spriteGraphics = new XNAGraphicsControl(this.panel_SpriteGraphics);
            this.animationGraphics = new XNAGraphicsControl(this.panel_AnimationGraphics);
            PrimitiveDrawer.Initialize(this.spriteGraphics.Graphics.GraphicsDevice);

            this.drawTimer = new Timer();
            this.drawTimer.Tick += new EventHandler(drawTimer_Tick);
            this.drawTimer.Interval = 1000 / 60;
            this.drawTimer.Start();
        }
    }
}

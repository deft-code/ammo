using System;
using System.Windows.Forms;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Design;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Storage;

namespace XNAControl
{
    public class XNAGraphicsService : IGraphicsDeviceService, IGraphicsDeviceManager
    {
        ///////////////
        // Variables //
        ///////////////
        private Control drawControl;
        private GraphicsDevice graphicsDevice;
        private Color clearColor;

        //Events
        public event EventHandler DeviceCreated;
        public event EventHandler DeviceDisposing;
        public event EventHandler DeviceReset;
        public event EventHandler DeviceResetting;

        //Constructor(s)
        public XNAGraphicsService(Control drawArea)
        {
            this.clearColor = Color.CornflowerBlue;
            this.drawControl = drawArea;
            this.InitializeGraphicsDevice();
        }

        //////////////////////
        // Public Functions //
        //////////////////////
        public void CreateDevice()
        {
            this.InitializeGraphicsDevice();
        }

        public bool BeginDraw()
        {
            this.graphicsDevice.Clear(ClearOptions.DepthBuffer, this.clearColor, 1.0f, 1);
            this.graphicsDevice.Clear(ClearOptions.Target, this.clearColor, 1.0f, 1);
            return true;
        }

        public void EndDraw()
        {
            this.graphicsDevice.Present();
        }

        ///////////////////////
        // Private Functions //
        ///////////////////////
        private void InitializeGraphicsDevice()
        {
            PresentationParameters pParams = new PresentationParameters();

            pParams.AutoDepthStencilFormat = DepthFormat.Depth24;
            pParams.BackBufferCount = 1;
            pParams.BackBufferFormat = SurfaceFormat.Color;
            pParams.BackBufferWidth = this.drawControl.Width;
            pParams.BackBufferHeight = this.drawControl.Height;
            pParams.DeviceWindowHandle = this.drawControl.Handle;
            pParams.EnableAutoDepthStencil = true;
            pParams.FullScreenRefreshRateInHz = 0;
            pParams.IsFullScreen = false;
            pParams.MultiSampleQuality = 0;
            pParams.MultiSampleType = MultiSampleType.None;
            pParams.PresentationInterval = PresentInterval.One;
            pParams.PresentOptions = PresentOptions.None;
            pParams.SwapEffect = SwapEffect.Discard;
            pParams.RenderTargetUsage = RenderTargetUsage.DiscardContents;

            this.graphicsDevice = new GraphicsDevice(GraphicsAdapter.DefaultAdapter,
                DeviceType.Hardware, this.drawControl.Handle, pParams);
        }

        ///////////////
        // Accessors //
        ///////////////
        public GraphicsDevice GraphicsDevice
        {
            get { return this.graphicsDevice; }
        }

        public Color ClearColor
        {
            get { return this.clearColor; }
            set { this.clearColor = value; }
        }
    }
}
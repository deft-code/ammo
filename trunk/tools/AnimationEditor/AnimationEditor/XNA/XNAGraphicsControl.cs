using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.Xna.Framework.Graphics;

namespace XNAControl
{
    public class XNAGraphicsControl
    {
        private XNAGraphicsService m_graphics;
        private SpriteBatch m_spriteBatch;

        public XNAGraphicsControl(Control drawControl)
        {
            this.m_graphics = new XNAGraphicsService(drawControl);
            this.m_spriteBatch = new SpriteBatch(this.m_graphics.GraphicsDevice);
        }

        public SpriteBatch SpriteBatch
        {
            get { return this.m_spriteBatch; }
        }

        public XNAGraphicsService Graphics
        {
            get { return this.m_graphics; }
        }
    }
}
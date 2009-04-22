using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace AnimationEditor
{
    public partial class AnimationEditorForm : Form
    {
        private void button_LoadImage_Click(object sender, EventArgs e)
        {
            LoadImageEvent();
        }

        private void button_RemoveImage_Click(object sender, EventArgs e)
        {
            RemoveImageEvent();
        }
    }
}
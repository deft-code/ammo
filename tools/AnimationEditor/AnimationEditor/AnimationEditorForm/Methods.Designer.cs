namespace AnimationEditor
{
    partial class AnimationEditorForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AnimationEditorForm));
            this.mainMenu = new System.Windows.Forms.MenuStrip();
            this.mainMenu_File = new System.Windows.Forms.ToolStripMenuItem();
            this.mainMenu_Images = new System.Windows.Forms.ToolStripMenuItem();
            this.mainMenu_Sprites = new System.Windows.Forms.ToolStripMenuItem();
            this.mainMenu_Animations = new System.Windows.Forms.ToolStripMenuItem();
            this.panel_spriteViewer = new System.Windows.Forms.Panel();
            this.listBox_LoadedImages = new System.Windows.Forms.ListBox();
            this.label_LoadedImages = new System.Windows.Forms.Label();
            this.label_LoadedSprites = new System.Windows.Forms.Label();
            this.listBox_LoadedSprites = new System.Windows.Forms.ListBox();
            this.groupBox_SpriteInformation = new System.Windows.Forms.GroupBox();
            this.label9 = new System.Windows.Forms.Label();
            this.textBox_SpriteInformation_AWidth = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.textBox_SpriteInformation_AHeight = new System.Windows.Forms.TextBox();
            this.label_SpriteInformation_ActualDimensions = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.textBox_SpriteInformation_Width = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.textBox_SpriteInformation_Height = new System.Windows.Forms.TextBox();
            this.label_SpriteInformation_Dimensions = new System.Windows.Forms.Label();
            this.label_SpriteInformation_Position = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox_SpriteInformation_Y = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox_SpriteInformation_X = new System.Windows.Forms.TextBox();
            this.comboBox_SpriteInformation_Image = new System.Windows.Forms.ComboBox();
            this.label_SpriteInformation_Image = new System.Windows.Forms.Label();
            this.label_SpriteInformation_Name = new System.Windows.Forms.Label();
            this.textBox_SpriteInformation_Name = new System.Windows.Forms.TextBox();
            this.updateBar = new System.Windows.Forms.ToolStrip();
            this.updateBar_Label_MousePos = new System.Windows.Forms.ToolStripLabel();
            this.updateBar_MousePos = new System.Windows.Forms.ToolStripLabel();
            this.button_CreateNewSprite = new System.Windows.Forms.Button();
            this.button_DeleteSprite = new System.Windows.Forms.Button();
            this.button_RemoveImage = new System.Windows.Forms.Button();
            this.button_LoadImage = new System.Windows.Forms.Button();
            this.panel_annimationPreview = new System.Windows.Forms.Panel();
            this.label_AnimationPreview = new System.Windows.Forms.Label();
            this.label_Animations = new System.Windows.Forms.Label();
            this.listBox_Animations = new System.Windows.Forms.ListBox();
            this.groupBox_AnimationInformation = new System.Windows.Forms.GroupBox();
            this.button_AnimationInformation_FramesEditor = new System.Windows.Forms.Button();
            this.label_AnimationInformation_Frames = new System.Windows.Forms.Label();
            this.listBox_AnimationInformation_Frames = new System.Windows.Forms.ListBox();
            this.label_AnimationInformation_Name = new System.Windows.Forms.Label();
            this.textBox_AnimationInformation_Name = new System.Windows.Forms.TextBox();
            this.button_AddAnimation = new System.Windows.Forms.Button();
            this.button_DeleteAnimation = new System.Windows.Forms.Button();
            this.button_Play = new System.Windows.Forms.Button();
            this.button_Stop = new System.Windows.Forms.Button();
            this.updateBar_Seperator1 = new System.Windows.Forms.ToolStripSeparator();
            this.updateBar_Label_Zoom = new System.Windows.Forms.ToolStripLabel();
            this.updateBar_Zoom = new System.Windows.Forms.ToolStripLabel();
            this.mainMenu.SuspendLayout();
            this.groupBox_SpriteInformation.SuspendLayout();
            this.updateBar.SuspendLayout();
            this.groupBox_AnimationInformation.SuspendLayout();
            this.SuspendLayout();
            // 
            // mainMenu
            // 
            this.mainMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mainMenu_File,
            this.mainMenu_Images,
            this.mainMenu_Sprites,
            this.mainMenu_Animations});
            this.mainMenu.Location = new System.Drawing.Point(0, 0);
            this.mainMenu.Name = "mainMenu";
            this.mainMenu.Size = new System.Drawing.Size(1016, 24);
            this.mainMenu.TabIndex = 0;
            this.mainMenu.Text = "mainMenu";
            // 
            // mainMenu_File
            // 
            this.mainMenu_File.Name = "mainMenu_File";
            this.mainMenu_File.Size = new System.Drawing.Size(37, 20);
            this.mainMenu_File.Text = "&File";
            // 
            // mainMenu_Images
            // 
            this.mainMenu_Images.Name = "mainMenu_Images";
            this.mainMenu_Images.Size = new System.Drawing.Size(57, 20);
            this.mainMenu_Images.Text = "&Images";
            // 
            // mainMenu_Sprites
            // 
            this.mainMenu_Sprites.Name = "mainMenu_Sprites";
            this.mainMenu_Sprites.Size = new System.Drawing.Size(54, 20);
            this.mainMenu_Sprites.Text = "&Sprites";
            // 
            // mainMenu_Animations
            // 
            this.mainMenu_Animations.Name = "mainMenu_Animations";
            this.mainMenu_Animations.Size = new System.Drawing.Size(80, 20);
            this.mainMenu_Animations.Text = "&Animations";
            // 
            // panel_spriteViewer
            // 
            this.panel_spriteViewer.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.panel_spriteViewer.BackColor = System.Drawing.SystemColors.Control;
            this.panel_spriteViewer.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel_spriteViewer.Location = new System.Drawing.Point(290, 27);
            this.panel_spriteViewer.Name = "panel_spriteViewer";
            this.panel_spriteViewer.Size = new System.Drawing.Size(714, 475);
            this.panel_spriteViewer.TabIndex = 1;
            this.panel_spriteViewer.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.panel_spriteViewer_MouseWheel);
            this.panel_spriteViewer.MouseLeave += new System.EventHandler(this.panel_spriteViewer_MouseLeave);
            this.panel_spriteViewer.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel_spriteViewer_MouseMove);
            this.panel_spriteViewer.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel_spriteViewer_MouseDown);
            this.panel_spriteViewer.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panel_spriteViewer_MouseUp);
            this.panel_spriteViewer.SizeChanged += new System.EventHandler(this.panel_spriteViewer_SizeChanged);
            this.panel_spriteViewer.MouseEnter += new System.EventHandler(this.panel_spriteViewer_MouseEnter);
            // 
            // listBox_LoadedImages
            // 
            this.listBox_LoadedImages.FormattingEnabled = true;
            this.listBox_LoadedImages.Location = new System.Drawing.Point(12, 59);
            this.listBox_LoadedImages.Name = "listBox_LoadedImages";
            this.listBox_LoadedImages.ScrollAlwaysVisible = true;
            this.listBox_LoadedImages.Size = new System.Drawing.Size(272, 95);
            this.listBox_LoadedImages.TabIndex = 2;
            // 
            // label_LoadedImages
            // 
            this.label_LoadedImages.AutoSize = true;
            this.label_LoadedImages.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_LoadedImages.Location = new System.Drawing.Point(12, 40);
            this.label_LoadedImages.Name = "label_LoadedImages";
            this.label_LoadedImages.Size = new System.Drawing.Size(116, 16);
            this.label_LoadedImages.TabIndex = 3;
            this.label_LoadedImages.Text = "Loaded Images";
            // 
            // label_LoadedSprites
            // 
            this.label_LoadedSprites.AutoSize = true;
            this.label_LoadedSprites.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_LoadedSprites.Location = new System.Drawing.Point(12, 205);
            this.label_LoadedSprites.Name = "label_LoadedSprites";
            this.label_LoadedSprites.Size = new System.Drawing.Size(114, 16);
            this.label_LoadedSprites.TabIndex = 5;
            this.label_LoadedSprites.Text = "Loaded Sprites";
            // 
            // listBox_LoadedSprites
            // 
            this.listBox_LoadedSprites.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.listBox_LoadedSprites.Enabled = false;
            this.listBox_LoadedSprites.FormattingEnabled = true;
            this.listBox_LoadedSprites.Location = new System.Drawing.Point(12, 224);
            this.listBox_LoadedSprites.Name = "listBox_LoadedSprites";
            this.listBox_LoadedSprites.ScrollAlwaysVisible = true;
            this.listBox_LoadedSprites.Size = new System.Drawing.Size(272, 95);
            this.listBox_LoadedSprites.TabIndex = 4;
            // 
            // groupBox_SpriteInformation
            // 
            this.groupBox_SpriteInformation.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox_SpriteInformation.Controls.Add(this.label9);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_AWidth);
            this.groupBox_SpriteInformation.Controls.Add(this.label10);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_AHeight);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_ActualDimensions);
            this.groupBox_SpriteInformation.Controls.Add(this.label7);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_Width);
            this.groupBox_SpriteInformation.Controls.Add(this.label8);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_Height);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_Dimensions);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_Position);
            this.groupBox_SpriteInformation.Controls.Add(this.label4);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_Y);
            this.groupBox_SpriteInformation.Controls.Add(this.label3);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_X);
            this.groupBox_SpriteInformation.Controls.Add(this.comboBox_SpriteInformation_Image);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_Image);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_Name);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_Name);
            this.groupBox_SpriteInformation.Enabled = false;
            this.groupBox_SpriteInformation.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox_SpriteInformation.Location = new System.Drawing.Point(12, 369);
            this.groupBox_SpriteInformation.Name = "groupBox_SpriteInformation";
            this.groupBox_SpriteInformation.Size = new System.Drawing.Size(269, 344);
            this.groupBox_SpriteInformation.TabIndex = 6;
            this.groupBox_SpriteInformation.TabStop = false;
            this.groupBox_SpriteInformation.Text = "Sprite Information";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.Location = new System.Drawing.Point(146, 303);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(38, 13);
            this.label9.TabIndex = 18;
            this.label9.Text = "Width:";
            // 
            // textBox_SpriteInformation_AWidth
            // 
            this.textBox_SpriteInformation_AWidth.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_AWidth.Location = new System.Drawing.Point(190, 298);
            this.textBox_SpriteInformation_AWidth.Name = "textBox_SpriteInformation_AWidth";
            this.textBox_SpriteInformation_AWidth.Size = new System.Drawing.Size(73, 20);
            this.textBox_SpriteInformation_AWidth.TabIndex = 17;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(14, 303);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(41, 13);
            this.label10.TabIndex = 16;
            this.label10.Text = "Height:";
            // 
            // textBox_SpriteInformation_AHeight
            // 
            this.textBox_SpriteInformation_AHeight.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_AHeight.Location = new System.Drawing.Point(61, 298);
            this.textBox_SpriteInformation_AHeight.Name = "textBox_SpriteInformation_AHeight";
            this.textBox_SpriteInformation_AHeight.Size = new System.Drawing.Size(73, 20);
            this.textBox_SpriteInformation_AHeight.TabIndex = 15;
            // 
            // label_SpriteInformation_ActualDimensions
            // 
            this.label_SpriteInformation_ActualDimensions.AutoSize = true;
            this.label_SpriteInformation_ActualDimensions.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_ActualDimensions.Location = new System.Drawing.Point(6, 282);
            this.label_SpriteInformation_ActualDimensions.Name = "label_SpriteInformation_ActualDimensions";
            this.label_SpriteInformation_ActualDimensions.Size = new System.Drawing.Size(115, 13);
            this.label_SpriteInformation_ActualDimensions.TabIndex = 14;
            this.label_SpriteInformation_ActualDimensions.Text = "Actual Dimensions:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(146, 241);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(38, 13);
            this.label7.TabIndex = 13;
            this.label7.Text = "Width:";
            // 
            // textBox_SpriteInformation_Width
            // 
            this.textBox_SpriteInformation_Width.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_Width.Location = new System.Drawing.Point(190, 236);
            this.textBox_SpriteInformation_Width.Name = "textBox_SpriteInformation_Width";
            this.textBox_SpriteInformation_Width.Size = new System.Drawing.Size(73, 20);
            this.textBox_SpriteInformation_Width.TabIndex = 12;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(14, 241);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(41, 13);
            this.label8.TabIndex = 11;
            this.label8.Text = "Height:";
            // 
            // textBox_SpriteInformation_Height
            // 
            this.textBox_SpriteInformation_Height.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_Height.Location = new System.Drawing.Point(61, 236);
            this.textBox_SpriteInformation_Height.Name = "textBox_SpriteInformation_Height";
            this.textBox_SpriteInformation_Height.Size = new System.Drawing.Size(73, 20);
            this.textBox_SpriteInformation_Height.TabIndex = 10;
            // 
            // label_SpriteInformation_Dimensions
            // 
            this.label_SpriteInformation_Dimensions.AutoSize = true;
            this.label_SpriteInformation_Dimensions.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_Dimensions.Location = new System.Drawing.Point(6, 220);
            this.label_SpriteInformation_Dimensions.Name = "label_SpriteInformation_Dimensions";
            this.label_SpriteInformation_Dimensions.Size = new System.Drawing.Size(75, 13);
            this.label_SpriteInformation_Dimensions.TabIndex = 9;
            this.label_SpriteInformation_Dimensions.Text = "Dimensions:";
            // 
            // label_SpriteInformation_Position
            // 
            this.label_SpriteInformation_Position.AutoSize = true;
            this.label_SpriteInformation_Position.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_Position.Location = new System.Drawing.Point(6, 161);
            this.label_SpriteInformation_Position.Name = "label_SpriteInformation_Position";
            this.label_SpriteInformation_Position.Size = new System.Drawing.Size(56, 13);
            this.label_SpriteInformation_Position.TabIndex = 8;
            this.label_SpriteInformation_Position.Text = "Position:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(167, 182);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(17, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Y:";
            // 
            // textBox_SpriteInformation_Y
            // 
            this.textBox_SpriteInformation_Y.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_Y.Location = new System.Drawing.Point(190, 177);
            this.textBox_SpriteInformation_Y.Name = "textBox_SpriteInformation_Y";
            this.textBox_SpriteInformation_Y.Size = new System.Drawing.Size(73, 20);
            this.textBox_SpriteInformation_Y.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(38, 182);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(17, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "X:";
            // 
            // textBox_SpriteInformation_X
            // 
            this.textBox_SpriteInformation_X.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_X.Location = new System.Drawing.Point(61, 177);
            this.textBox_SpriteInformation_X.Name = "textBox_SpriteInformation_X";
            this.textBox_SpriteInformation_X.Size = new System.Drawing.Size(73, 20);
            this.textBox_SpriteInformation_X.TabIndex = 4;
            // 
            // comboBox_SpriteInformation_Image
            // 
            this.comboBox_SpriteInformation_Image.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBox_SpriteInformation_Image.FormattingEnabled = true;
            this.comboBox_SpriteInformation_Image.Location = new System.Drawing.Point(6, 109);
            this.comboBox_SpriteInformation_Image.Name = "comboBox_SpriteInformation_Image";
            this.comboBox_SpriteInformation_Image.Size = new System.Drawing.Size(257, 21);
            this.comboBox_SpriteInformation_Image.TabIndex = 3;
            // 
            // label_SpriteInformation_Image
            // 
            this.label_SpriteInformation_Image.AutoSize = true;
            this.label_SpriteInformation_Image.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_Image.Location = new System.Drawing.Point(7, 93);
            this.label_SpriteInformation_Image.Name = "label_SpriteInformation_Image";
            this.label_SpriteInformation_Image.Size = new System.Drawing.Size(45, 13);
            this.label_SpriteInformation_Image.TabIndex = 2;
            this.label_SpriteInformation_Image.Text = "Image:";
            // 
            // label_SpriteInformation_Name
            // 
            this.label_SpriteInformation_Name.AutoSize = true;
            this.label_SpriteInformation_Name.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_Name.Location = new System.Drawing.Point(7, 28);
            this.label_SpriteInformation_Name.Name = "label_SpriteInformation_Name";
            this.label_SpriteInformation_Name.Size = new System.Drawing.Size(43, 13);
            this.label_SpriteInformation_Name.TabIndex = 1;
            this.label_SpriteInformation_Name.Text = "Name:";
            // 
            // textBox_SpriteInformation_Name
            // 
            this.textBox_SpriteInformation_Name.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_Name.Location = new System.Drawing.Point(6, 44);
            this.textBox_SpriteInformation_Name.Name = "textBox_SpriteInformation_Name";
            this.textBox_SpriteInformation_Name.Size = new System.Drawing.Size(257, 20);
            this.textBox_SpriteInformation_Name.TabIndex = 0;
            // 
            // updateBar
            // 
            this.updateBar.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.updateBar.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.updateBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.updateBar_Label_MousePos,
            this.updateBar_MousePos,
            this.updateBar_Seperator1,
            this.updateBar_Label_Zoom,
            this.updateBar_Zoom});
            this.updateBar.Location = new System.Drawing.Point(0, 716);
            this.updateBar.Name = "updateBar";
            this.updateBar.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.updateBar.Size = new System.Drawing.Size(1016, 25);
            this.updateBar.TabIndex = 7;
            this.updateBar.Text = "toolStrip1";
            // 
            // updateBar_Label_MousePos
            // 
            this.updateBar_Label_MousePos.Name = "updateBar_Label_MousePos";
            this.updateBar_Label_MousePos.Size = new System.Drawing.Size(68, 22);
            this.updateBar_Label_MousePos.Text = "Mouse Pos:";
            // 
            // updateBar_MousePos
            // 
            this.updateBar_MousePos.Name = "updateBar_MousePos";
            this.updateBar_MousePos.Size = new System.Drawing.Size(42, 22);
            this.updateBar_MousePos.Text = "( 0 , 0 )";
            // 
            // button_CreateNewSprite
            // 
            this.button_CreateNewSprite.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button_CreateNewSprite.Enabled = false;
            this.button_CreateNewSprite.Location = new System.Drawing.Point(74, 325);
            this.button_CreateNewSprite.Name = "button_CreateNewSprite";
            this.button_CreateNewSprite.Size = new System.Drawing.Size(102, 23);
            this.button_CreateNewSprite.TabIndex = 8;
            this.button_CreateNewSprite.Text = "Create New Sprite";
            this.button_CreateNewSprite.UseVisualStyleBackColor = true;
            // 
            // button_DeleteSprite
            // 
            this.button_DeleteSprite.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button_DeleteSprite.Enabled = false;
            this.button_DeleteSprite.Location = new System.Drawing.Point(182, 325);
            this.button_DeleteSprite.Name = "button_DeleteSprite";
            this.button_DeleteSprite.Size = new System.Drawing.Size(102, 23);
            this.button_DeleteSprite.TabIndex = 9;
            this.button_DeleteSprite.Text = "Delete Sprite";
            this.button_DeleteSprite.UseVisualStyleBackColor = true;
            // 
            // button_RemoveImage
            // 
            this.button_RemoveImage.Location = new System.Drawing.Point(182, 160);
            this.button_RemoveImage.Name = "button_RemoveImage";
            this.button_RemoveImage.Size = new System.Drawing.Size(102, 23);
            this.button_RemoveImage.TabIndex = 11;
            this.button_RemoveImage.Text = "Remove Image";
            this.button_RemoveImage.UseVisualStyleBackColor = true;
            this.button_RemoveImage.Click += new System.EventHandler(this.button_RemoveImage_Click);
            // 
            // button_LoadImage
            // 
            this.button_LoadImage.Location = new System.Drawing.Point(74, 160);
            this.button_LoadImage.Name = "button_LoadImage";
            this.button_LoadImage.Size = new System.Drawing.Size(102, 23);
            this.button_LoadImage.TabIndex = 10;
            this.button_LoadImage.Text = "Load Image...";
            this.button_LoadImage.UseVisualStyleBackColor = true;
            this.button_LoadImage.Click += new System.EventHandler(this.button_LoadImage_Click);
            // 
            // panel_annimationPreview
            // 
            this.panel_annimationPreview.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.panel_annimationPreview.BackColor = System.Drawing.SystemColors.Control;
            this.panel_annimationPreview.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel_annimationPreview.Location = new System.Drawing.Point(816, 525);
            this.panel_annimationPreview.Name = "panel_annimationPreview";
            this.panel_annimationPreview.Size = new System.Drawing.Size(188, 188);
            this.panel_annimationPreview.TabIndex = 2;
            // 
            // label_AnimationPreview
            // 
            this.label_AnimationPreview.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.label_AnimationPreview.AutoSize = true;
            this.label_AnimationPreview.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_AnimationPreview.Location = new System.Drawing.Point(813, 509);
            this.label_AnimationPreview.Name = "label_AnimationPreview";
            this.label_AnimationPreview.Size = new System.Drawing.Size(111, 13);
            this.label_AnimationPreview.TabIndex = 19;
            this.label_AnimationPreview.Text = "Animation Preview";
            // 
            // label_Animations
            // 
            this.label_Animations.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label_Animations.AutoSize = true;
            this.label_Animations.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_Animations.Location = new System.Drawing.Point(287, 509);
            this.label_Animations.Name = "label_Animations";
            this.label_Animations.Size = new System.Drawing.Size(84, 16);
            this.label_Animations.TabIndex = 21;
            this.label_Animations.Text = "Animations";
            // 
            // listBox_Animations
            // 
            this.listBox_Animations.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.listBox_Animations.Enabled = false;
            this.listBox_Animations.FormattingEnabled = true;
            this.listBox_Animations.Location = new System.Drawing.Point(290, 528);
            this.listBox_Animations.Name = "listBox_Animations";
            this.listBox_Animations.ScrollAlwaysVisible = true;
            this.listBox_Animations.Size = new System.Drawing.Size(232, 147);
            this.listBox_Animations.TabIndex = 20;
            // 
            // groupBox_AnimationInformation
            // 
            this.groupBox_AnimationInformation.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox_AnimationInformation.Controls.Add(this.button_AnimationInformation_FramesEditor);
            this.groupBox_AnimationInformation.Controls.Add(this.label_AnimationInformation_Frames);
            this.groupBox_AnimationInformation.Controls.Add(this.listBox_AnimationInformation_Frames);
            this.groupBox_AnimationInformation.Controls.Add(this.label_AnimationInformation_Name);
            this.groupBox_AnimationInformation.Controls.Add(this.textBox_AnimationInformation_Name);
            this.groupBox_AnimationInformation.Enabled = false;
            this.groupBox_AnimationInformation.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox_AnimationInformation.Location = new System.Drawing.Point(528, 509);
            this.groupBox_AnimationInformation.Name = "groupBox_AnimationInformation";
            this.groupBox_AnimationInformation.Size = new System.Drawing.Size(279, 204);
            this.groupBox_AnimationInformation.TabIndex = 22;
            this.groupBox_AnimationInformation.TabStop = false;
            this.groupBox_AnimationInformation.Text = "Animation Information";
            // 
            // button_AnimationInformation_FramesEditor
            // 
            this.button_AnimationInformation_FramesEditor.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button_AnimationInformation_FramesEditor.Location = new System.Drawing.Point(171, 174);
            this.button_AnimationInformation_FramesEditor.Name = "button_AnimationInformation_FramesEditor";
            this.button_AnimationInformation_FramesEditor.Size = new System.Drawing.Size(102, 23);
            this.button_AnimationInformation_FramesEditor.TabIndex = 23;
            this.button_AnimationInformation_FramesEditor.Text = "Frames Editor...";
            this.button_AnimationInformation_FramesEditor.UseVisualStyleBackColor = true;
            // 
            // label_AnimationInformation_Frames
            // 
            this.label_AnimationInformation_Frames.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.label_AnimationInformation_Frames.AutoSize = true;
            this.label_AnimationInformation_Frames.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_AnimationInformation_Frames.Location = new System.Drawing.Point(6, 70);
            this.label_AnimationInformation_Frames.Name = "label_AnimationInformation_Frames";
            this.label_AnimationInformation_Frames.Size = new System.Drawing.Size(51, 13);
            this.label_AnimationInformation_Frames.TabIndex = 24;
            this.label_AnimationInformation_Frames.Text = "Frames:";
            // 
            // listBox_AnimationInformation_Frames
            // 
            this.listBox_AnimationInformation_Frames.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.listBox_AnimationInformation_Frames.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listBox_AnimationInformation_Frames.FormattingEnabled = true;
            this.listBox_AnimationInformation_Frames.Location = new System.Drawing.Point(6, 86);
            this.listBox_AnimationInformation_Frames.Name = "listBox_AnimationInformation_Frames";
            this.listBox_AnimationInformation_Frames.ScrollAlwaysVisible = true;
            this.listBox_AnimationInformation_Frames.Size = new System.Drawing.Size(267, 82);
            this.listBox_AnimationInformation_Frames.TabIndex = 23;
            // 
            // label_AnimationInformation_Name
            // 
            this.label_AnimationInformation_Name.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.label_AnimationInformation_Name.AutoSize = true;
            this.label_AnimationInformation_Name.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_AnimationInformation_Name.Location = new System.Drawing.Point(6, 24);
            this.label_AnimationInformation_Name.Name = "label_AnimationInformation_Name";
            this.label_AnimationInformation_Name.Size = new System.Drawing.Size(43, 13);
            this.label_AnimationInformation_Name.TabIndex = 20;
            this.label_AnimationInformation_Name.Text = "Name:";
            // 
            // textBox_AnimationInformation_Name
            // 
            this.textBox_AnimationInformation_Name.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.textBox_AnimationInformation_Name.Location = new System.Drawing.Point(6, 40);
            this.textBox_AnimationInformation_Name.Name = "textBox_AnimationInformation_Name";
            this.textBox_AnimationInformation_Name.Size = new System.Drawing.Size(267, 22);
            this.textBox_AnimationInformation_Name.TabIndex = 19;
            // 
            // button_AddAnimation
            // 
            this.button_AddAnimation.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button_AddAnimation.Enabled = false;
            this.button_AddAnimation.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button_AddAnimation.Location = new System.Drawing.Point(312, 683);
            this.button_AddAnimation.Name = "button_AddAnimation";
            this.button_AddAnimation.Size = new System.Drawing.Size(102, 23);
            this.button_AddAnimation.TabIndex = 25;
            this.button_AddAnimation.Text = "Add Animation";
            this.button_AddAnimation.UseVisualStyleBackColor = true;
            // 
            // button_DeleteAnimation
            // 
            this.button_DeleteAnimation.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button_DeleteAnimation.Enabled = false;
            this.button_DeleteAnimation.Location = new System.Drawing.Point(420, 683);
            this.button_DeleteAnimation.Name = "button_DeleteAnimation";
            this.button_DeleteAnimation.Size = new System.Drawing.Size(102, 23);
            this.button_DeleteAnimation.TabIndex = 26;
            this.button_DeleteAnimation.Text = "Delete Animation";
            this.button_DeleteAnimation.UseVisualStyleBackColor = true;
            // 
            // button_Play
            // 
            this.button_Play.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button_Play.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_Play.BackgroundImage")));
            this.button_Play.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.button_Play.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button_Play.Location = new System.Drawing.Point(948, 507);
            this.button_Play.Name = "button_Play";
            this.button_Play.Size = new System.Drawing.Size(25, 16);
            this.button_Play.TabIndex = 25;
            this.button_Play.UseVisualStyleBackColor = true;
            // 
            // button_Stop
            // 
            this.button_Stop.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button_Stop.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_Stop.BackgroundImage")));
            this.button_Stop.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.button_Stop.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button_Stop.Location = new System.Drawing.Point(979, 507);
            this.button_Stop.Name = "button_Stop";
            this.button_Stop.Size = new System.Drawing.Size(25, 16);
            this.button_Stop.TabIndex = 27;
            this.button_Stop.UseVisualStyleBackColor = true;
            // 
            // updateBar_Seperator1
            // 
            this.updateBar_Seperator1.Name = "updateBar_Seperator1";
            this.updateBar_Seperator1.Size = new System.Drawing.Size(6, 25);
            // 
            // updateBar_Label_Zoom
            // 
            this.updateBar_Label_Zoom.Name = "updateBar_Label_Zoom";
            this.updateBar_Label_Zoom.Size = new System.Drawing.Size(42, 22);
            this.updateBar_Label_Zoom.Text = "Zoom:";
            // 
            // updateBar_Zoom
            // 
            this.updateBar_Zoom.Name = "updateBar_Zoom";
            this.updateBar_Zoom.Size = new System.Drawing.Size(35, 22);
            this.updateBar_Zoom.Text = "100%";
            // 
            // AnimationEditorForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1016, 741);
            this.Controls.Add(this.button_Stop);
            this.Controls.Add(this.button_Play);
            this.Controls.Add(this.button_DeleteAnimation);
            this.Controls.Add(this.button_AddAnimation);
            this.Controls.Add(this.groupBox_AnimationInformation);
            this.Controls.Add(this.label_Animations);
            this.Controls.Add(this.listBox_Animations);
            this.Controls.Add(this.label_AnimationPreview);
            this.Controls.Add(this.panel_annimationPreview);
            this.Controls.Add(this.button_RemoveImage);
            this.Controls.Add(this.button_LoadImage);
            this.Controls.Add(this.button_DeleteSprite);
            this.Controls.Add(this.button_CreateNewSprite);
            this.Controls.Add(this.updateBar);
            this.Controls.Add(this.groupBox_SpriteInformation);
            this.Controls.Add(this.label_LoadedSprites);
            this.Controls.Add(this.listBox_LoadedSprites);
            this.Controls.Add(this.label_LoadedImages);
            this.Controls.Add(this.listBox_LoadedImages);
            this.Controls.Add(this.panel_spriteViewer);
            this.Controls.Add(this.mainMenu);
            this.MainMenuStrip = this.mainMenu;
            this.MinimumSize = new System.Drawing.Size(1024, 768);
            this.Name = "AnimationEditorForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Animation Editor";
            this.mainMenu.ResumeLayout(false);
            this.mainMenu.PerformLayout();
            this.groupBox_SpriteInformation.ResumeLayout(false);
            this.groupBox_SpriteInformation.PerformLayout();
            this.updateBar.ResumeLayout(false);
            this.updateBar.PerformLayout();
            this.groupBox_AnimationInformation.ResumeLayout(false);
            this.groupBox_AnimationInformation.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip mainMenu;
        private System.Windows.Forms.ToolStripMenuItem mainMenu_File;
        private System.Windows.Forms.ToolStripMenuItem mainMenu_Images;
        private System.Windows.Forms.ToolStripMenuItem mainMenu_Sprites;
        private System.Windows.Forms.ToolStripMenuItem mainMenu_Animations;
        private System.Windows.Forms.Panel panel_spriteViewer;
        private System.Windows.Forms.ListBox listBox_LoadedImages;
        private System.Windows.Forms.Label label_LoadedImages;
        private System.Windows.Forms.Label label_LoadedSprites;
        private System.Windows.Forms.ListBox listBox_LoadedSprites;
        private System.Windows.Forms.GroupBox groupBox_SpriteInformation;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_Y;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_X;
        private System.Windows.Forms.ComboBox comboBox_SpriteInformation_Image;
        private System.Windows.Forms.Label label_SpriteInformation_Image;
        private System.Windows.Forms.Label label_SpriteInformation_Name;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_Name;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_AWidth;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_AHeight;
        private System.Windows.Forms.Label label_SpriteInformation_ActualDimensions;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_Width;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_Height;
        private System.Windows.Forms.Label label_SpriteInformation_Dimensions;
        private System.Windows.Forms.Label label_SpriteInformation_Position;
        private System.Windows.Forms.ToolStrip updateBar;
        private System.Windows.Forms.Button button_CreateNewSprite;
        private System.Windows.Forms.Button button_DeleteSprite;
        private System.Windows.Forms.Button button_RemoveImage;
        private System.Windows.Forms.Button button_LoadImage;
        private System.Windows.Forms.Panel panel_annimationPreview;
        private System.Windows.Forms.Label label_AnimationPreview;
        private System.Windows.Forms.Label label_Animations;
        private System.Windows.Forms.ListBox listBox_Animations;
        private System.Windows.Forms.GroupBox groupBox_AnimationInformation;
        private System.Windows.Forms.Label label_AnimationInformation_Frames;
        private System.Windows.Forms.ListBox listBox_AnimationInformation_Frames;
        private System.Windows.Forms.Label label_AnimationInformation_Name;
        private System.Windows.Forms.TextBox textBox_AnimationInformation_Name;
        private System.Windows.Forms.Button button_AnimationInformation_FramesEditor;
        private System.Windows.Forms.Button button_AddAnimation;
        private System.Windows.Forms.Button button_DeleteAnimation;
        private System.Windows.Forms.Button button_Play;
        private System.Windows.Forms.Button button_Stop;
        private System.Windows.Forms.ToolStripLabel updateBar_Label_MousePos;
        private System.Windows.Forms.ToolStripLabel updateBar_MousePos;
        private System.Windows.Forms.ToolStripSeparator updateBar_Seperator1;
        private System.Windows.Forms.ToolStripLabel updateBar_Label_Zoom;
        private System.Windows.Forms.ToolStripLabel updateBar_Zoom;
    }
}


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
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.menuStrip_File = new System.Windows.Forms.ToolStripMenuItem();
            this.tabControl = new System.Windows.Forms.TabControl();
            this.spritesPage = new System.Windows.Forms.TabPage();
            this.groupBox_SpriteInformation = new System.Windows.Forms.GroupBox();
            this.textBox_SpriteInformation_Height = new System.Windows.Forms.TextBox();
            this.textBox_SpriteInformation_Width = new System.Windows.Forms.TextBox();
            this.label_SpriteInformation_Height = new System.Windows.Forms.Label();
            this.label_SpriteInformation_Width = new System.Windows.Forms.Label();
            this.label_SpriteInformation_Dimensions = new System.Windows.Forms.Label();
            this.label_SpriteInformation_Y = new System.Windows.Forms.Label();
            this.textBox_SpriteInformation_Y = new System.Windows.Forms.TextBox();
            this.label_SpriteInformation_X = new System.Windows.Forms.Label();
            this.textBox_SpriteInformation_X = new System.Windows.Forms.TextBox();
            this.label_SpriteInformation_Position = new System.Windows.Forms.Label();
            this.label_SpriteInformation_Name = new System.Windows.Forms.Label();
            this.textBox_SpriteInformation_Name = new System.Windows.Forms.TextBox();
            this.spriteUpdateBar = new System.Windows.Forms.ToolStrip();
            this.spriteUpdateBar_Label_MousePos = new System.Windows.Forms.ToolStripLabel();
            this.spriteUpdateBar_MousePos = new System.Windows.Forms.ToolStripLabel();
            this.spriteUpdateBar_Seperator1 = new System.Windows.Forms.ToolStripSeparator();
            this.spriteUpdateBar_Label_Zoom = new System.Windows.Forms.ToolStripLabel();
            this.spriteUpdateBar_Zoom = new System.Windows.Forms.ToolStripLabel();
            this.button_RemoveImage = new System.Windows.Forms.Button();
            this.button_LoadImage = new System.Windows.Forms.Button();
            this.button_DeleteSprite = new System.Windows.Forms.Button();
            this.button_CreateNewSprite = new System.Windows.Forms.Button();
            this.label_LoadedSprites = new System.Windows.Forms.Label();
            this.listBox_LoadedSprites = new System.Windows.Forms.ListBox();
            this.label_LoadedImages = new System.Windows.Forms.Label();
            this.listBox_LoadedImages = new System.Windows.Forms.ListBox();
            this.panel_SpriteGraphics = new System.Windows.Forms.Panel();
            this.animationsPage = new System.Windows.Forms.TabPage();
            this.menuStrip.SuspendLayout();
            this.tabControl.SuspendLayout();
            this.spritesPage.SuspendLayout();
            this.groupBox_SpriteInformation.SuspendLayout();
            this.spriteUpdateBar.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip
            // 
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuStrip_File});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(859, 24);
            this.menuStrip.TabIndex = 0;
            this.menuStrip.Text = "menuStrip1";
            // 
            // menuStrip_File
            // 
            this.menuStrip_File.Name = "menuStrip_File";
            this.menuStrip_File.Size = new System.Drawing.Size(37, 20);
            this.menuStrip_File.Text = "&File";
            // 
            // tabControl
            // 
            this.tabControl.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.tabControl.Controls.Add(this.spritesPage);
            this.tabControl.Controls.Add(this.animationsPage);
            this.tabControl.Location = new System.Drawing.Point(0, 27);
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            this.tabControl.Size = new System.Drawing.Size(862, 604);
            this.tabControl.TabIndex = 1;
            // 
            // spritesPage
            // 
            this.spritesPage.BackColor = System.Drawing.SystemColors.Control;
            this.spritesPage.Controls.Add(this.groupBox_SpriteInformation);
            this.spritesPage.Controls.Add(this.spriteUpdateBar);
            this.spritesPage.Controls.Add(this.button_RemoveImage);
            this.spritesPage.Controls.Add(this.button_LoadImage);
            this.spritesPage.Controls.Add(this.button_DeleteSprite);
            this.spritesPage.Controls.Add(this.button_CreateNewSprite);
            this.spritesPage.Controls.Add(this.label_LoadedSprites);
            this.spritesPage.Controls.Add(this.listBox_LoadedSprites);
            this.spritesPage.Controls.Add(this.label_LoadedImages);
            this.spritesPage.Controls.Add(this.listBox_LoadedImages);
            this.spritesPage.Controls.Add(this.panel_SpriteGraphics);
            this.spritesPage.Location = new System.Drawing.Point(4, 22);
            this.spritesPage.Name = "spritesPage";
            this.spritesPage.Padding = new System.Windows.Forms.Padding(3);
            this.spritesPage.Size = new System.Drawing.Size(854, 578);
            this.spritesPage.TabIndex = 0;
            this.spritesPage.Text = "Sprites";
            // 
            // groupBox_SpriteInformation
            // 
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_Height);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_Width);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_Height);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_Width);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_Dimensions);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_Y);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_Y);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_X);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_X);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_Position);
            this.groupBox_SpriteInformation.Controls.Add(this.label_SpriteInformation_Name);
            this.groupBox_SpriteInformation.Controls.Add(this.textBox_SpriteInformation_Name);
            this.groupBox_SpriteInformation.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox_SpriteInformation.Location = new System.Drawing.Point(8, 348);
            this.groupBox_SpriteInformation.Name = "groupBox_SpriteInformation";
            this.groupBox_SpriteInformation.Size = new System.Drawing.Size(288, 199);
            this.groupBox_SpriteInformation.TabIndex = 19;
            this.groupBox_SpriteInformation.TabStop = false;
            this.groupBox_SpriteInformation.Text = "Sprite Information";
            // 
            // textBox_SpriteInformation_Height
            // 
            this.textBox_SpriteInformation_Height.BackColor = System.Drawing.SystemColors.Control;
            this.textBox_SpriteInformation_Height.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox_SpriteInformation_Height.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_Height.Location = new System.Drawing.Point(121, 166);
            this.textBox_SpriteInformation_Height.MaxLength = 8;
            this.textBox_SpriteInformation_Height.Name = "textBox_SpriteInformation_Height";
            this.textBox_SpriteInformation_Height.Size = new System.Drawing.Size(41, 13);
            this.textBox_SpriteInformation_Height.TabIndex = 15;
            this.textBox_SpriteInformation_Height.Text = "0";
            this.textBox_SpriteInformation_Height.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox_SpriteInformation_Width
            // 
            this.textBox_SpriteInformation_Width.BackColor = System.Drawing.SystemColors.Control;
            this.textBox_SpriteInformation_Width.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox_SpriteInformation_Width.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_Width.Location = new System.Drawing.Point(53, 166);
            this.textBox_SpriteInformation_Width.MaxLength = 8;
            this.textBox_SpriteInformation_Width.Name = "textBox_SpriteInformation_Width";
            this.textBox_SpriteInformation_Width.Size = new System.Drawing.Size(41, 13);
            this.textBox_SpriteInformation_Width.TabIndex = 17;
            this.textBox_SpriteInformation_Width.Text = "0";
            this.textBox_SpriteInformation_Width.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label_SpriteInformation_Height
            // 
            this.label_SpriteInformation_Height.AutoSize = true;
            this.label_SpriteInformation_Height.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_Height.Location = new System.Drawing.Point(100, 166);
            this.label_SpriteInformation_Height.Name = "label_SpriteInformation_Height";
            this.label_SpriteInformation_Height.Size = new System.Drawing.Size(21, 13);
            this.label_SpriteInformation_Height.TabIndex = 13;
            this.label_SpriteInformation_Height.Text = "H=";
            // 
            // label_SpriteInformation_Width
            // 
            this.label_SpriteInformation_Width.AutoSize = true;
            this.label_SpriteInformation_Width.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_Width.Location = new System.Drawing.Point(26, 166);
            this.label_SpriteInformation_Width.Name = "label_SpriteInformation_Width";
            this.label_SpriteInformation_Width.Size = new System.Drawing.Size(24, 13);
            this.label_SpriteInformation_Width.TabIndex = 16;
            this.label_SpriteInformation_Width.Text = "W=";
            // 
            // label_SpriteInformation_Dimensions
            // 
            this.label_SpriteInformation_Dimensions.AutoSize = true;
            this.label_SpriteInformation_Dimensions.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_Dimensions.Location = new System.Drawing.Point(6, 141);
            this.label_SpriteInformation_Dimensions.Name = "label_SpriteInformation_Dimensions";
            this.label_SpriteInformation_Dimensions.Size = new System.Drawing.Size(75, 13);
            this.label_SpriteInformation_Dimensions.TabIndex = 14;
            this.label_SpriteInformation_Dimensions.Text = "Dimensions:";
            // 
            // label_SpriteInformation_Y
            // 
            this.label_SpriteInformation_Y.AutoSize = true;
            this.label_SpriteInformation_Y.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_Y.Location = new System.Drawing.Point(100, 108);
            this.label_SpriteInformation_Y.Name = "label_SpriteInformation_Y";
            this.label_SpriteInformation_Y.Size = new System.Drawing.Size(20, 13);
            this.label_SpriteInformation_Y.TabIndex = 12;
            this.label_SpriteInformation_Y.Text = "Y=";
            // 
            // textBox_SpriteInformation_Y
            // 
            this.textBox_SpriteInformation_Y.BackColor = System.Drawing.SystemColors.Control;
            this.textBox_SpriteInformation_Y.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox_SpriteInformation_Y.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_Y.Location = new System.Drawing.Point(121, 108);
            this.textBox_SpriteInformation_Y.MaxLength = 5;
            this.textBox_SpriteInformation_Y.Name = "textBox_SpriteInformation_Y";
            this.textBox_SpriteInformation_Y.Size = new System.Drawing.Size(41, 13);
            this.textBox_SpriteInformation_Y.TabIndex = 11;
            this.textBox_SpriteInformation_Y.Text = "0";
            this.textBox_SpriteInformation_Y.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label_SpriteInformation_X
            // 
            this.label_SpriteInformation_X.AutoSize = true;
            this.label_SpriteInformation_X.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_X.Location = new System.Drawing.Point(30, 108);
            this.label_SpriteInformation_X.Name = "label_SpriteInformation_X";
            this.label_SpriteInformation_X.Size = new System.Drawing.Size(20, 13);
            this.label_SpriteInformation_X.TabIndex = 10;
            this.label_SpriteInformation_X.Text = "X=";
            // 
            // textBox_SpriteInformation_X
            // 
            this.textBox_SpriteInformation_X.BackColor = System.Drawing.SystemColors.Control;
            this.textBox_SpriteInformation_X.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox_SpriteInformation_X.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_X.Location = new System.Drawing.Point(53, 108);
            this.textBox_SpriteInformation_X.MaxLength = 5;
            this.textBox_SpriteInformation_X.Name = "textBox_SpriteInformation_X";
            this.textBox_SpriteInformation_X.Size = new System.Drawing.Size(41, 13);
            this.textBox_SpriteInformation_X.TabIndex = 9;
            this.textBox_SpriteInformation_X.Text = "0";
            this.textBox_SpriteInformation_X.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label_SpriteInformation_Position
            // 
            this.label_SpriteInformation_Position.AutoSize = true;
            this.label_SpriteInformation_Position.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_Position.Location = new System.Drawing.Point(6, 89);
            this.label_SpriteInformation_Position.Name = "label_SpriteInformation_Position";
            this.label_SpriteInformation_Position.Size = new System.Drawing.Size(56, 13);
            this.label_SpriteInformation_Position.TabIndex = 8;
            this.label_SpriteInformation_Position.Text = "Position:";
            // 
            // label_SpriteInformation_Name
            // 
            this.label_SpriteInformation_Name.AutoSize = true;
            this.label_SpriteInformation_Name.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_SpriteInformation_Name.Location = new System.Drawing.Point(6, 30);
            this.label_SpriteInformation_Name.Name = "label_SpriteInformation_Name";
            this.label_SpriteInformation_Name.Size = new System.Drawing.Size(43, 13);
            this.label_SpriteInformation_Name.TabIndex = 1;
            this.label_SpriteInformation_Name.Text = "Name:";
            // 
            // textBox_SpriteInformation_Name
            // 
            this.textBox_SpriteInformation_Name.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox_SpriteInformation_Name.Location = new System.Drawing.Point(6, 46);
            this.textBox_SpriteInformation_Name.Name = "textBox_SpriteInformation_Name";
            this.textBox_SpriteInformation_Name.Size = new System.Drawing.Size(276, 20);
            this.textBox_SpriteInformation_Name.TabIndex = 0;
            this.textBox_SpriteInformation_Name.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // spriteUpdateBar
            // 
            this.spriteUpdateBar.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.spriteUpdateBar.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.spriteUpdateBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.spriteUpdateBar_Label_MousePos,
            this.spriteUpdateBar_MousePos,
            this.spriteUpdateBar_Seperator1,
            this.spriteUpdateBar_Label_Zoom,
            this.spriteUpdateBar_Zoom});
            this.spriteUpdateBar.Location = new System.Drawing.Point(3, 550);
            this.spriteUpdateBar.Name = "spriteUpdateBar";
            this.spriteUpdateBar.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            this.spriteUpdateBar.Size = new System.Drawing.Size(848, 25);
            this.spriteUpdateBar.TabIndex = 18;
            this.spriteUpdateBar.Text = "toolStrip1";
            // 
            // spriteUpdateBar_Label_MousePos
            // 
            this.spriteUpdateBar_Label_MousePos.Name = "spriteUpdateBar_Label_MousePos";
            this.spriteUpdateBar_Label_MousePos.Size = new System.Drawing.Size(68, 22);
            this.spriteUpdateBar_Label_MousePos.Text = "Mouse Pos:";
            // 
            // spriteUpdateBar_MousePos
            // 
            this.spriteUpdateBar_MousePos.Name = "spriteUpdateBar_MousePos";
            this.spriteUpdateBar_MousePos.Size = new System.Drawing.Size(42, 22);
            this.spriteUpdateBar_MousePos.Text = "( 0 , 0 )";
            // 
            // spriteUpdateBar_Seperator1
            // 
            this.spriteUpdateBar_Seperator1.Name = "spriteUpdateBar_Seperator1";
            this.spriteUpdateBar_Seperator1.Size = new System.Drawing.Size(6, 25);
            // 
            // spriteUpdateBar_Label_Zoom
            // 
            this.spriteUpdateBar_Label_Zoom.Name = "spriteUpdateBar_Label_Zoom";
            this.spriteUpdateBar_Label_Zoom.Size = new System.Drawing.Size(42, 22);
            this.spriteUpdateBar_Label_Zoom.Text = "Zoom:";
            // 
            // spriteUpdateBar_Zoom
            // 
            this.spriteUpdateBar_Zoom.Name = "spriteUpdateBar_Zoom";
            this.spriteUpdateBar_Zoom.Size = new System.Drawing.Size(35, 22);
            this.spriteUpdateBar_Zoom.Text = "100%";
            // 
            // button_RemoveImage
            // 
            this.button_RemoveImage.Location = new System.Drawing.Point(194, 140);
            this.button_RemoveImage.Name = "button_RemoveImage";
            this.button_RemoveImage.Size = new System.Drawing.Size(102, 23);
            this.button_RemoveImage.TabIndex = 17;
            this.button_RemoveImage.Text = "Remove Image";
            this.button_RemoveImage.UseVisualStyleBackColor = true;
            // 
            // button_LoadImage
            // 
            this.button_LoadImage.Location = new System.Drawing.Point(86, 140);
            this.button_LoadImage.Name = "button_LoadImage";
            this.button_LoadImage.Size = new System.Drawing.Size(102, 23);
            this.button_LoadImage.TabIndex = 16;
            this.button_LoadImage.Text = "Load Image...";
            this.button_LoadImage.UseVisualStyleBackColor = true;
            this.button_LoadImage.Click += new System.EventHandler(this.LoadImageButtonClick);
            // 
            // button_DeleteSprite
            // 
            this.button_DeleteSprite.Location = new System.Drawing.Point(194, 305);
            this.button_DeleteSprite.Name = "button_DeleteSprite";
            this.button_DeleteSprite.Size = new System.Drawing.Size(102, 23);
            this.button_DeleteSprite.TabIndex = 15;
            this.button_DeleteSprite.Text = "Delete Sprite";
            this.button_DeleteSprite.UseVisualStyleBackColor = true;
            // 
            // button_CreateNewSprite
            // 
            this.button_CreateNewSprite.Location = new System.Drawing.Point(86, 305);
            this.button_CreateNewSprite.Name = "button_CreateNewSprite";
            this.button_CreateNewSprite.Size = new System.Drawing.Size(102, 23);
            this.button_CreateNewSprite.TabIndex = 14;
            this.button_CreateNewSprite.Text = "Create New Sprite";
            this.button_CreateNewSprite.UseVisualStyleBackColor = true;
            // 
            // label_LoadedSprites
            // 
            this.label_LoadedSprites.AutoSize = true;
            this.label_LoadedSprites.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_LoadedSprites.Location = new System.Drawing.Point(10, 185);
            this.label_LoadedSprites.Name = "label_LoadedSprites";
            this.label_LoadedSprites.Size = new System.Drawing.Size(114, 16);
            this.label_LoadedSprites.TabIndex = 13;
            this.label_LoadedSprites.Text = "Loaded Sprites";
            // 
            // listBox_LoadedSprites
            // 
            this.listBox_LoadedSprites.FormattingEnabled = true;
            this.listBox_LoadedSprites.Location = new System.Drawing.Point(11, 204);
            this.listBox_LoadedSprites.Name = "listBox_LoadedSprites";
            this.listBox_LoadedSprites.ScrollAlwaysVisible = true;
            this.listBox_LoadedSprites.Size = new System.Drawing.Size(285, 95);
            this.listBox_LoadedSprites.TabIndex = 12;
            // 
            // label_LoadedImages
            // 
            this.label_LoadedImages.AutoSize = true;
            this.label_LoadedImages.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_LoadedImages.Location = new System.Drawing.Point(8, 20);
            this.label_LoadedImages.Name = "label_LoadedImages";
            this.label_LoadedImages.Size = new System.Drawing.Size(116, 16);
            this.label_LoadedImages.TabIndex = 4;
            this.label_LoadedImages.Text = "Loaded Images";
            // 
            // listBox_LoadedImages
            // 
            this.listBox_LoadedImages.FormattingEnabled = true;
            this.listBox_LoadedImages.Location = new System.Drawing.Point(8, 39);
            this.listBox_LoadedImages.Name = "listBox_LoadedImages";
            this.listBox_LoadedImages.ScrollAlwaysVisible = true;
            this.listBox_LoadedImages.Size = new System.Drawing.Size(288, 95);
            this.listBox_LoadedImages.TabIndex = 1;
            this.listBox_LoadedImages.SelectedIndexChanged += new System.EventHandler(this.SelectedImageChanged);
            // 
            // panel_SpriteGraphics
            // 
            this.panel_SpriteGraphics.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.panel_SpriteGraphics.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel_SpriteGraphics.Location = new System.Drawing.Point(302, 6);
            this.panel_SpriteGraphics.Name = "panel_SpriteGraphics";
            this.panel_SpriteGraphics.Size = new System.Drawing.Size(541, 541);
            this.panel_SpriteGraphics.TabIndex = 0;
            this.panel_SpriteGraphics.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.SpriteMouseWheel);
            this.panel_SpriteGraphics.MouseLeave += new System.EventHandler(this.SpriteMouseLeave);
            this.panel_SpriteGraphics.MouseMove += new System.Windows.Forms.MouseEventHandler(this.SpriteMouseMove);
            this.panel_SpriteGraphics.MouseDown += new System.Windows.Forms.MouseEventHandler(this.SpriteMouseDown);
            this.panel_SpriteGraphics.MouseUp += new System.Windows.Forms.MouseEventHandler(this.SpriteMouseUp);
            this.panel_SpriteGraphics.SizeChanged += new System.EventHandler(this.SpriteViewportChanged);
            this.panel_SpriteGraphics.MouseEnter += new System.EventHandler(this.SpriteMouseEnter);
            // 
            // animationsPage
            // 
            this.animationsPage.BackColor = System.Drawing.SystemColors.Control;
            this.animationsPage.Location = new System.Drawing.Point(4, 22);
            this.animationsPage.Name = "animationsPage";
            this.animationsPage.Padding = new System.Windows.Forms.Padding(3);
            this.animationsPage.Size = new System.Drawing.Size(854, 578);
            this.animationsPage.TabIndex = 1;
            this.animationsPage.Text = "Animations";
            // 
            // AnimationEditorForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(859, 629);
            this.Controls.Add(this.tabControl);
            this.Controls.Add(this.menuStrip);
            this.MainMenuStrip = this.menuStrip;
            this.MinimumSize = new System.Drawing.Size(875, 667);
            this.Name = "AnimationEditorForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Animation Editor";
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.tabControl.ResumeLayout(false);
            this.spritesPage.ResumeLayout(false);
            this.spritesPage.PerformLayout();
            this.groupBox_SpriteInformation.ResumeLayout(false);
            this.groupBox_SpriteInformation.PerformLayout();
            this.spriteUpdateBar.ResumeLayout(false);
            this.spriteUpdateBar.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem menuStrip_File;
        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.TabPage spritesPage;
        private System.Windows.Forms.TabPage animationsPage;
        private System.Windows.Forms.Panel panel_SpriteGraphics;
        private System.Windows.Forms.ToolStrip spriteUpdateBar;
        private System.Windows.Forms.ToolStripLabel spriteUpdateBar_Label_MousePos;
        private System.Windows.Forms.ToolStripLabel spriteUpdateBar_MousePos;
        private System.Windows.Forms.Button button_RemoveImage;
        private System.Windows.Forms.Button button_LoadImage;
        private System.Windows.Forms.Button button_DeleteSprite;
        private System.Windows.Forms.Button button_CreateNewSprite;
        private System.Windows.Forms.Label label_LoadedSprites;
        private System.Windows.Forms.ListBox listBox_LoadedSprites;
        private System.Windows.Forms.Label label_LoadedImages;
        private System.Windows.Forms.ListBox listBox_LoadedImages;
        private System.Windows.Forms.ToolStripSeparator spriteUpdateBar_Seperator1;
        private System.Windows.Forms.ToolStripLabel spriteUpdateBar_Label_Zoom;
        private System.Windows.Forms.ToolStripLabel spriteUpdateBar_Zoom;
        private System.Windows.Forms.GroupBox groupBox_SpriteInformation;
        private System.Windows.Forms.Label label_SpriteInformation_Position;
        private System.Windows.Forms.Label label_SpriteInformation_Name;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_Name;
        private System.Windows.Forms.Label label_SpriteInformation_Y;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_Y;
        private System.Windows.Forms.Label label_SpriteInformation_X;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_X;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_Width;
        private System.Windows.Forms.Label label_SpriteInformation_Width;
        private System.Windows.Forms.TextBox textBox_SpriteInformation_Height;
        private System.Windows.Forms.Label label_SpriteInformation_Dimensions;
        private System.Windows.Forms.Label label_SpriteInformation_Height;
    }
}


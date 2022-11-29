namespace Grafos_Redes_Sociais
{
    partial class FormPrincipal
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.adicionarpessoa = new System.Windows.Forms.Button();
            this.carregarrede = new System.Windows.Forms.Button();
            this.cancelar = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.analisarrede = new System.Windows.Forms.Button();
            this.salvarrede = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // adicionarpessoa
            // 
            this.adicionarpessoa.Location = new System.Drawing.Point(44, 120);
            this.adicionarpessoa.Name = "adicionarpessoa";
            this.adicionarpessoa.Size = new System.Drawing.Size(116, 31);
            this.adicionarpessoa.TabIndex = 0;
            this.adicionarpessoa.Text = "Adicionar pessoa";
            this.adicionarpessoa.UseVisualStyleBackColor = true;
            this.adicionarpessoa.Click += new System.EventHandler(this.Button1_Click);
            // 
            // carregarrede
            // 
            this.carregarrede.Location = new System.Drawing.Point(44, 194);
            this.carregarrede.Name = "carregarrede";
            this.carregarrede.Size = new System.Drawing.Size(116, 31);
            this.carregarrede.TabIndex = 2;
            this.carregarrede.Text = "Carregar Grafo";
            this.carregarrede.UseVisualStyleBackColor = true;
            this.carregarrede.Click += new System.EventHandler(this.Button3_Click);
            // 
            // cancelar
            // 
            this.cancelar.Location = new System.Drawing.Point(44, 317);
            this.cancelar.Name = "cancelar";
            this.cancelar.Size = new System.Drawing.Size(116, 31);
            this.cancelar.TabIndex = 3;
            this.cancelar.Text = "Cancelar Operação";
            this.cancelar.UseVisualStyleBackColor = true;
            this.cancelar.Click += new System.EventHandler(this.Button4_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Location = new System.Drawing.Point(211, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(577, 426);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Usuários do Arara Azul";
            // 
            // analisarrede
            // 
            this.analisarrede.Location = new System.Drawing.Point(44, 231);
            this.analisarrede.Name = "analisarrede";
            this.analisarrede.Size = new System.Drawing.Size(116, 31);
            this.analisarrede.TabIndex = 0;
            this.analisarrede.Text = "Analisar a Rede";
            this.analisarrede.UseVisualStyleBackColor = true;
            this.analisarrede.Click += new System.EventHandler(this.Button5_Click);
            // 
            // salvarrede
            // 
            this.salvarrede.Location = new System.Drawing.Point(44, 157);
            this.salvarrede.Name = "salvarrede";
            this.salvarrede.Size = new System.Drawing.Size(116, 31);
            this.salvarrede.TabIndex = 1;
            this.salvarrede.Text = "Salvar Grafo";
            this.salvarrede.UseVisualStyleBackColor = true;
            this.salvarrede.Click += new System.EventHandler(this.Button2_Click);
            // 
            // FormPrincipal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.analisarrede);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.cancelar);
            this.Controls.Add(this.carregarrede);
            this.Controls.Add(this.salvarrede);
            this.Controls.Add(this.adicionarpessoa);
            this.Name = "FormPrincipal";
            this.Text = "Análise de Redes Sociais e Complexas";
            this.ResumeLayout(false);

        }

        #endregion

        private Button adicionarpessoa;
        private Button carregarrede;
        private Button cancelar;
        private GroupBox groupBox1;
        private Button analisarrede;
        private Button salvarrede;
    }
}
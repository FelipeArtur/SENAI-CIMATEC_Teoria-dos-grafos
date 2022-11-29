namespace Grafos_Redes_Sociais
{
    public partial class FormPrincipal : Form
    {
        Thread form;
        public FormPrincipal()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            this.Close();
            form = new Thread(novoForm1);
            form.SetApartmentState(ApartmentState.STA);
            form.Start();
        }

        private void novoForm1(object? obj)
        {
            Application.Run(new FormCriarPessoa());
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            this.Close();
            form = new Thread(NovoForm2);
            form.SetApartmentState(ApartmentState.STA);
            form.Start();
        }
        private void NovoForm2(object? obj)
        {
            Application.Run(new FormSalvarGrafo());
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            this.Close();
            form = new Thread(NovoForm3);
            form.SetApartmentState(ApartmentState.STA);
            form.Start();
        }
        private void NovoForm3(object? obj)
        {
            Application.Run(new FormCarregarGrafo());
        }

        private void Button4_Click(object sender, EventArgs e)
        {

        }

        private void Button5_Click(object sender, EventArgs e)
        {
            this.Close();
            form = new Thread(NovoForm4);
            form.SetApartmentState(ApartmentState.STA);
            form.Start();
        }

        private void NovoForm4(object? obj)
        {
            Application.Run(new FormAnalisarRede());
        }
    }
}
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditQuantidadeMaxClientes->setFocus();


    ui->lineEditQuantidadeMaxClientes->setValidator(new QIntValidator(1,100));
    ui->lineEditNumConta->setValidator(new QIntValidator(1,100));

    ui->lineEditPosicao->setValidator(new QIntValidator(1,999));


    ui->lineEditNumConta->setEnabled(false);
    ui->lineEditNome->setEnabled(false);
    ui->lineEditSaldo->setEnabled(false);
    ui->lineEditCPF->setEnabled(false);
    ui->lineEditPosicao->setEnabled(false);
    ui->lineEditValor->setEnabled(false);

    ui->pushButtonCadastrar->setEnabled(false);
    ui->pushButtonDepositar->setEnabled(false);
    ui->pushButtonExcluir->setEnabled(false);
    ui->pushButtonMostrarCliente->setEnabled(false);
    ui->pushButtonMostrarClientes->setEnabled(false);
    ui->pushButtonSacar->setEnabled(false);
    ui->pushButtonLimpar->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonExecutar_clicked()
{
    try
    {
        if(ui->lineEditQuantidadeMaxClientes->text()==""||ui->lineEditQuantidadeMaxClientes->text().toInt()==0)
        {
            throw QString("Inválido");
        }

        int maxClientes=ui->lineEditQuantidadeMaxClientes->text().toInt();

        banco=new Banco(maxClientes);

        ui->lineEditQuantidadeMaxClientes->setEnabled(false);
        ui->pushButtonExecutar->setEnabled(false);

        ui->lineEditNumConta->setEnabled(true);
        ui->lineEditNome->setEnabled(true);
        ui->lineEditSaldo->setEnabled(true);
        ui->lineEditCPF->setEnabled(true);
        ui->lineEditPosicao->setEnabled(false);
        ui->lineEditValor->setEnabled(false);

        ui->pushButtonCadastrar->setEnabled(true);
        ui->pushButtonDepositar->setEnabled(true);
        ui->pushButtonExcluir->setEnabled(true);
        ui->pushButtonMostrarCliente->setEnabled(false);
        ui->pushButtonMostrarClientes->setEnabled(false);
        ui->pushButtonSacar->setEnabled(true);
        ui->pushButtonLimpar->setEnabled(true);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditQuantidadeMaxClientes->clear();
        ui->lineEditQuantidadeMaxClientes->setFocus();
    }
}


void MainWindow::on_pushButtonLimpar_clicked()
{
    delete banco;
    ui->lineEditQuantidadeMaxClientes->setEnabled(true);
    ui->pushButtonExecutar->setEnabled(true);

    ui->lineEditNumConta->setEnabled(false);
    ui->lineEditNome->setEnabled(false);
    ui->lineEditSaldo->setEnabled(false);
    ui->lineEditCPF->setEnabled(false);
    ui->lineEditPosicao->setEnabled(false);
    ui->lineEditValor->setEnabled(false);

    ui->pushButtonCadastrar->setEnabled(false);
    ui->pushButtonDepositar->setEnabled(false);
    ui->pushButtonExcluir->setEnabled(false);
    ui->pushButtonMostrarCliente->setEnabled(false);
    ui->pushButtonMostrarClientes->setEnabled(false);
    ui->pushButtonSacar->setEnabled(false);
    ui->pushButtonLimpar->setEnabled(false);

    ui->lineEditQuantidadeMaxClientes->clear();

    ui->lineEditNumConta->clear();
    ui->lineEditNome->clear();
    ui->lineEditSaldo->clear();
    ui->lineEditCPF->clear();
    ui->lineEditPosicao->clear();
    ui->lineEditValor->clear();
    ui->textEditResultado->clear();
}

void MainWindow::on_pushButtonCadastrar_clicked()
{
    try
    {
        if(ui->lineEditSaldo->text()=="" || ui->lineEditNumConta->text()=="" || ui->lineEditCPF->text()=="" || ui->lineEditNome->text()=="")
        {
            throw QString("Saldo, número da conta, cpf ou nome está vazio.");
        }

        ui->pushButtonMostrarCliente->setEnabled(true);
        ui->pushButtonMostrarClientes->setEnabled(true);
        ui->lineEditPosicao->setEnabled(true);
        ui->lineEditValor->setEnabled(true);

        float saldo=ui->lineEditSaldo->text().toFloat();
        string numConta=ui->lineEditNumConta->text().toStdString();
        string cpf=ui->lineEditCPF->text().toStdString();
        string nome=ui->lineEditNome->text().toStdString();

        banco->cadastrarCliente(saldo,numConta,cpf,nome);
    }

    catch (QString &mensagem)
    {
        QMessageBox::information(this,"Mensagem",mensagem);

        ui->lineEditNumConta->clear();
        ui->lineEditNome->clear();
        ui->lineEditSaldo->clear();
        ui->lineEditCPF->clear();
        ui->lineEditPosicao->clear();
        ui->lineEditValor->clear();
    }
}


void MainWindow::on_pushButtonExcluir_clicked()
{
    try
    {
        if(ui->lineEditCPF->text()=="")
        {
            throw QString("CPF está vazio.");
        }

        string cpf=ui->lineEditCPF->text().toStdString();

        banco->excluirCliente(cpf);
    }

    catch (QString &mensagem)
    {
        QMessageBox::information(this,"Mensagem",mensagem);

        ui->lineEditCPF->clear();
    }
}


void MainWindow::on_pushButtonMostrarClientes_clicked() //Todos
{
    QString saida;

    saida=banco->mostrarClientes();
    ui->textEditResultado->setText(saida);
}


void MainWindow::on_pushButtonMostrarCliente_clicked() //Só um
{
    QString saida;
    int posicao;

    try
    {
        if(ui->lineEditPosicao->text()=="")
        {
            throw QString("Posição inválida");
        }

        posicao=ui->lineEditPosicao->text().toInt();
        saida=banco->getCliente(posicao);

        ui->textEditResultado->setText(saida);
    }

    catch (QString &mensagem)
    {
        QMessageBox::information(this,"Mensagem",mensagem);

        ui->lineEditPosicao->clear();
        ui->lineEditPosicao->setFocus();
    }
}


void MainWindow::on_pushButtonDepositar_clicked()
{
    float valor = 0.0;
    string cpf;

    try
    {
        if(ui->lineEditValor->text()==""||ui->lineEditValor->text()=="0"||ui->lineEditCPF->text()=="")
        {
            throw QString("CPF ou valor vazio.");
        }

        cpf=ui->lineEditCPF->text().toStdString();
        valor=ui->lineEditValor->text().toFloat();

        banco->depositar(cpf,valor);
    }

    catch (QString &mensagem)
    {
        QMessageBox::information(this,"Mensagem",mensagem);

        ui->lineEditCPF->clear();
        ui->lineEditValor->clear();
        ui->lineEditCPF->setFocus();
    }
}


void MainWindow::on_pushButtonSacar_clicked()
{
    float valor = 0.0;
    string cpf;

    try
    {
        if(ui->lineEditValor->text()==""||ui->lineEditValor->text()=="0"||ui->lineEditCPF->text()=="")
        {
            throw QString("CPF ou valor vazio.");
        }

        cpf=ui->lineEditCPF->text().toStdString();
        valor=ui->lineEditValor->text().toFloat();

        banco->sacar(cpf,valor);
    }

    catch (QString &mensagem)
    {
        QMessageBox::information(this,"Mensagem",mensagem);

        ui->lineEditCPF->clear();
        ui->lineEditValor->clear();
        ui->lineEditCPF->setFocus();
    }
}

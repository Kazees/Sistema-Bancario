#include "Banco.h"

Banco::Banco(int quantidadeMaximaClientes):clientes(nullptr),quantidadeClientes(0) //ou 0
{

    try
    {
        setQuantidadeMaximaClientes(quantidadeMaximaClientes);
        clientes=new Cliente[quantidadeMaximaClientes];
    }

    catch (bad_alloc &)
    {
        throw QString("Memória insuficiente.");
    }
}

void Banco::setQuantidadeMaximaClientes(int quantidadeMaximaClientes)
{
    this->quantidadeMaximaClientes=quantidadeMaximaClientes;
}

Banco::~Banco()
{
    delete[] clientes;
}
Cliente* Banco::consultarCliente(string cpf)
{
    for(int i=0;i<quantidadeClientes;i++)
    {
        if(clientes[i].getCpf()==cpf)
        {
            return &clientes[i]; //Cliente encontrado
        }
    }

    return nullptr;// Cliente não encontrado
}

void Banco::excluirCliente(string cpf)
{
    try
    {
        for(int i=0;i<quantidadeClientes;i++)
        {
            if(clientes[i].getCpf()==cpf)
            {
                quantidadeClientes--;

                for(int j=i;j<quantidadeClientes;j++)
                {
                    clientes[j]=clientes[j+1]; // Reorganizar o vetor e impedir o vazio deixado após sua retirada
                }

                throw QString("Cliente excluído com sucesso.");
            }
        }
        throw QString("Cliente não encontrado.");
    }

    catch (bad_alloc &)
    {
        throw QString ("Memória insuficiente");
    }
}

void Banco::cadastrarCliente(float saldo,string numConta,string cpf,string nomeCliente)
{
    if(quantidadeClientes>=quantidadeMaximaClientes)
    {
        throw QString("Quantidade máxima de clientes.");
    }

    for(int i=0,j=0;i<quantidadeClientes&&j<quantidadeClientes;i++,j++)
    {
        if(clientes[i].getConta().getNumConta()==numConta)
        {
            throw QString("Número da conta igual."); //Cliente encontrado
        }

        if(clientes[i].getCpf()==cpf)
        {
            throw QString("CPF é igual."); //Cliente encontrado
        }
    }

    clientes[quantidadeClientes]=Cliente(saldo,numConta,cpf,nomeCliente);
    quantidadeClientes++;

    throw QString("Cliente criado com sucesso");
}

QString Banco::getCliente(int posicao) //Pegar um cliente em especifico
{
    QString saida;

    if(posicao>=0 && posicao<quantidadeClientes)
    {
        saida+="CPF: "+QString::fromStdString(clientes[posicao].getCpf())+'\n';
        saida+="Nome: "+QString::fromStdString(clientes[posicao].getNomeCliente())+'\n';
        saida+="Numero da conta: "+QString::fromStdString(clientes[posicao].getConta().getNumConta())+'\n';
        saida+="Saldo: R$"+QString::number(clientes[posicao].getConta().getSaldo())+'\n';
    }

    else
    {
        throw QString("Cliente não encontrado.");
    }

    return saida;
}

QString Banco::mostrarClientes()const //Mostrar todos os clientes
{
    QString saida;
    saida+="Lista dos clientes: ";

    for(int i=0;i<quantidadeClientes;i++)
    {
        saida+="\nCPF: "+QString::fromStdString(clientes[i].getCpf())+'\n';
        saida+="Nome: "+QString::fromStdString(clientes[i].getNomeCliente())+'\n';
        saida+="Numero da conta: "+QString::fromStdString(clientes[i].getConta().getNumConta())+'\n';
        saida+="Saldo: R$"+QString::number(clientes[i].getConta().getSaldo())+'\n';
    }

    return saida;
}

void Banco::depositar(string cpf,float valor)
{
    Cliente *verifica=consultarCliente(cpf);

    if(verifica)
    {
        verifica->getConta().setSaldo(verifica->getConta().getSaldo()+valor);
        throw QString("Depósito feito com sucesso");
    }

    else
    {
        throw QString("Cliente não encontrado");
    }
}

void Banco::sacar(string cpf,float valor)
{
    Cliente *verifica=consultarCliente(cpf);

    if(verifica) //Verificar se o cliente existe
    {
        if(verifica->getConta().getSaldo()>=valor) // Verificar se o saldo é suficiente
        {
            verifica->getConta().setSaldo(verifica->getConta().getSaldo()-valor);
            throw QString("Saque feito com sucesso");
        }

        else
        {
            throw QString("Saldo insuficiente");

        }

    }

    else
    {
        throw QString("Cliente não encontrado");
    }
}

#ifndef BANCO_H
#define BANCO_H
#include "Cliente.h"
#include <QString>

using namespace std;

class Banco
{
private:
    Cliente *clientes;
    int quantidadeClientes;
    int quantidadeMaximaClientes;

public:
    Banco(int quantidadeMaximaClientes);
    ~Banco();

    void setQuantidadeMaximaClientes(int quantidadeMaximaClientes);

    Cliente* consultarCliente(string cpf);
    void excluirCliente(string cpf);
    void cadastrarCliente(float saldo,string numConta,string cpf,string nomeCliente);

    QString getCliente(int posicao);
    QString mostrarClientes()const;
    void depositar(string cpf,float valor);
    void sacar(string cpf,float valor);
};

#endif

#include "Cliente.h"

Cliente::Cliente(float saldo,string numConta,string cpf,string nomeCliente):conta(saldo,numConta)
{
    this->cpf=cpf;
    this->nomeCliente=nomeCliente;
}

Cliente::Cliente()
{
    cpf="";
    nomeCliente="";
}



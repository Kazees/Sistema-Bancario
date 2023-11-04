#include "Contapoupanca.h"

ContaPoupanca::ContaPoupanca(float saldo, string numConta)
{
    setSaldo(saldo);
    this->numConta=numConta;
}

ContaPoupanca::ContaPoupanca()
{
    saldo=0.0;
    numConta="";
}

void ContaPoupanca::setSaldo(float saldo)
{
    if(saldo<0)
    {
        throw QString("Saldo inválido.");
    }

    this->saldo=saldo;
}

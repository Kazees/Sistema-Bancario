#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include "Contapoupanca.h"
#include <QString>

using namespace std;

class Cliente
{
private:
    ContaPoupanca conta;
    string cpf;
    string nomeCliente;

public:
    Cliente(float saldo,string numConta,string cpf,string nomeCliente);
    Cliente();

    void setCpf(string cpf) {this->cpf=cpf;}
    void setNomeCliente(string nomeCliente) {this->nomeCliente=nomeCliente;}

    string getCpf()const {return cpf;}
    string getNomeCliente()const {return nomeCliente;}
    ContaPoupanca &getConta() {return conta;}
};

#endif

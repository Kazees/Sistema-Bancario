#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include <iostream>
#include <QString>

using namespace std;

class ContaPoupanca
{
private:
    float saldo;
    string numConta;

public:
    ContaPoupanca(float saldo,string numConta);
    ContaPoupanca();

    void setSaldo(float saldo);
    void setNumConta(string numConta) {this->numConta=numConta;}

    float getSaldo()const {return saldo;}
    string getNumConta()const {return numConta;}
};

#endif

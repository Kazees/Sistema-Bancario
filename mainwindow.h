#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>
#include <QMessageBox>
#include "Banco.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonExecutar_clicked();

    void on_pushButtonLimpar_clicked();

    void on_pushButtonCadastrar_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonMostrarClientes_clicked();

    void on_pushButtonMostrarCliente_clicked();

    void on_pushButtonDepositar_clicked();

    void on_pushButtonSacar_clicked();


private:
    Ui::MainWindow *ui;
    Banco *banco;
};
#endif // MAINWINDOW_H

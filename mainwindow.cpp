#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete solverDialog;
    delete game;
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    solverDialog = new SolverDialog(this);
    solverDialog->show();
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    game = new Game(this);
    game->show();
}

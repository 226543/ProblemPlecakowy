#include "game.h"
#include "ui_game.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QTableView>
#include <QPixmap>
#include <QImage>
#include <QString>
#include <string>
#include <vector>
#include <algorithm>

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{

    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

Game::~Game()
{
    delete kp;
    delete ui;
}

void Game::on_pushButton_2_clicked()
{
    parentWidget()->show();
    close();
}

void Game::on_pushButton_3_clicked()
{
    bool piwa = false;
    bool wina = false;
    bool wysoko = false;

    if(ui->checkPiwa_2->isChecked()) {
        piwa = true;
    }
    if(ui->checkWina_2->isChecked()) {
        wina = true;
    }
    if(ui->checkWysoko_2->isChecked()) {
        wysoko = true;
    }

    if(!piwa && !wina && !wysoko) {
        QMessageBox::warning(this,"UWAGA","Musisz wybrać jakąś opcje!");
        return;
    }

    if(budzet == 0) {
        QMessageBox::warning(this,"UWAGA","Musisz podać i zatwierdzić swój budżet!");
        return;
    }

    kp = new Solver(budzet*100);
    kp->preferences(piwa,wina,wysoko);
    bag = kp->DP();

    QStringList header;
    header <<"Nazwa"<<"Zdjecie"<<"Cena" << "ml/zł";
    ui->tableWidget_2->setHorizontalHeaderLabels(header);

    QHeaderView *verticalHeader = ui->tableWidget_2->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader->setDefaultSectionSize(90);

    ui->tableWidget_2->setColumnCount(4);
    ui->tableWidget_2->setRowCount(bag.getCapacity());

    double kwota = 0;
    double alko = 0;

    for(int i = 0; i < bag.getCapacity(); ++i) {
        kwota += bag[i].getWeight()/100.0;
        alko += bag[i].getValue();
        QImage *img = new QImage(bag[i].getPath());
        QTableWidgetItem *pic = new QTableWidgetItem;
        pic->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(90, 90));

        QTableWidgetItem *name = new QTableWidgetItem(QString::fromStdString(bag[i].getName()));
        name->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *price = new QTableWidgetItem(QString::number(bag[i].getWeight()/100.0));
        price->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *profitability = new QTableWidgetItem(QString::number(bag[i].getValue()/(bag[i].getWeight()/100.0)));
        profitability->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget_2->setItem(i, 0, name);
        ui->tableWidget_2->setItem(i, 1, pic);
        ui->tableWidget_2->setItem(i, 2, price);
        ui->tableWidget_2->setItem(i, 3, profitability);
    }

    double kwota1 = 0;
    double alko1 = 0;
    for(int i = 0; i < selected.size(); ++i) {
        kwota1 += selected[i].getWeight()/100.0;
        alko1 += selected[i].getValue();
    }
    QMessageBox::information(this, "Wynik",
        QString("Wybrano elementy o wartości %1 zł z %2 ml alkoholu.\n"
                "Algorytm wybrał elementy o wartości %3 zł z %4 ml alkoholu")
        .arg(kwota1).arg(alko1).arg(kwota).arg(alko));
}


void Game::on_pushButton_clicked()
{
    bool piwa = false;
    bool wina = false;
    bool wysoko = false;


    if((ui->budzet_2->text()).replace(",", ".").toDouble() == 0) {
        QMessageBox::warning(this,"UWAGA","Musisz podać i zatwierdzić swój budżet!");
        return;
    }

    if(ui->checkPiwa_2->isChecked()) {
        piwa = true;
    }
    if(ui->checkWina_2->isChecked()) {
        wina = true;
    }
    if(ui->checkWysoko_2->isChecked()) {
        wysoko = true;
    }

    if(!piwa && !wina && !wysoko) {
        QMessageBox::warning(this,"UWAGA","Musisz wybrać jakąś opcje!");
    return;
    }

    budzet = (ui->budzet_2->text()).replace(",", ".").toDouble();

    QStringList header;
    ui->tableWidget->setColumnCount(1);
    header <<""<<"";
    ui->tableWidget->setVerticalHeaderLabels(header);

    QHeaderView *verticalHeader = ui->tableWidget->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader->setDefaultSectionSize(100);

    bag2.addItems(piwa,wina,wysoko);

    ui->tableWidget->setRowCount(2);
    ui->tableWidget->setColumnCount(bag2.getCapacity());

    verticalHeader->resizeSection(1, 25);

    for(int i = 0; i < bag2.getCapacity(); ++i) {
        QImage *img = new QImage(bag2[i].getPath());
        QTableWidgetItem *pic = new QTableWidgetItem;
        pic->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(100, 100));

        QTableWidgetItem *name = new QTableWidgetItem(QString::fromStdString(bag2[i].getName()));
        name->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(0, i, pic);
        ui->tableWidget->setItem(1, i, name);

        toChoose.push_back(bag2[i]);
    }
}

void Game::on_tableWidget_cellClicked(int row,int column)
{
    if(row == 0 || row == 1) {
        if( !(std::find(selected.begin(), selected.end(), toChoose[column]) != selected.end())) { // nie ma tego elementu w wektorze
            if(checkWeightOfBackpack() + toChoose[column].getWeight()/100.0 > budzet) { // sprawdzenie czy zmiesci sie do plecaka
                QMessageBox::warning(this,"UWAGA!","Ten element nie zmieści się do plecaka.\n");
                return;
            }

            selected.push_back(toChoose[column]);

            QImage *img = new QImage(":/iresource/img/wybrano.jpg");
            QTableWidgetItem *thumbnail = new QTableWidgetItem;
            thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(100, 100));

            ui->tableWidget->setItem(0, column, thumbnail);
        }
        else { // odznacz (usun element)
            selected.erase(std::remove(selected.begin(), selected.end(), toChoose[column]), selected.end());

            QImage *img = new QImage(toChoose[column].getPath());
            QTableWidgetItem *pic = new QTableWidgetItem;
            pic->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(100, 100));

            ui->tableWidget->setItem(0, column, pic);
        }
    }
    ui->label_6->setText(QString::number(checkWeightOfBackpack()));
}

void Game::clearGame()
{
    selected.clear();

    for (int i = 0; i < toChoose.size(); ++i){
        QImage *img = new QImage(toChoose[i].getPath());
        QTableWidgetItem *pic = new QTableWidgetItem;
        pic->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(100, 100));

        ui->tableWidget->setItem(0, i, pic);
    }
    ui->tableWidget_2->clear();
    ui->label_6->setText(QString::number(0));
}


void Game::on_pushButton_4_clicked()
{
    clearGame();
}

double Game::checkWeightOfBackpack()
{
    double result = 0;
    for(int i = 0; i < selected.size(); ++i) {
        result += selected[i].getWeight()/100.0;
    }
    return result;
}

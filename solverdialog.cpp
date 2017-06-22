#include "solverdialog.h"
#include "ui_solverdialog.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QTableView>
#include <QPixmap>
#include <QImage>
#include <QString>
#include <string>
#include <vector>
#include <algorithm>

SolverDialog::SolverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SolverDialog)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

SolverDialog::~SolverDialog()
{
    delete kp;
    delete ui;
}

void SolverDialog::on_pushButton_clicked()
{
    parentWidget()->show();
    close();
}

void SolverDialog::on_pushButton_2_clicked()
{
    bool piwa = false;
    bool wina = false;
    bool wysoko = false;

    if(ui->checkPiwa->isChecked()) {
        piwa = true;
    }
    if(ui->checkWina->isChecked()) {
        wina = true;
    }
    if(ui->checkWysoko->isChecked()) {
        wysoko = true;
    }

    if(!piwa && !wina && !wysoko) {
        QMessageBox::warning(this,"UWAGA","Musisz wybrać jakąś opcje!");
        return;
    }

    double b = (ui->budzet->text()).replace(",", ".").toDouble();

    if(b == 0) {
       QMessageBox::warning(this,"UWAGA","Musisz podać swój budżet!");
       return;
    }

    kp = new Solver(b*100);
    kp->preferences(piwa,wina,wysoko);

    if(ui->radioButtonZachlanny->isChecked()) {
       bag = kp->approx();
    }
    else if (ui->radioButtonDP->isChecked()){
       bag = kp->DP();
    }
    else {
        QMessageBox::warning(this,"UWAGA","Musisz wybrać metodę!");
        return;
    }

    QHeaderView *verticalHeader = ui->tableWidget->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader->setDefaultSectionSize(90);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(bag.getCapacity());

    QStringList header;
    header <<"Nazwa"<<"Zdjecie"<<"Cena" << "ml/zł";
    ui->tableWidget->setHorizontalHeaderLabels(header);

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

        ui->tableWidget->setItem(i, 0, name);
        ui->tableWidget->setItem(i, 1, pic);
        ui->tableWidget->setItem(i, 2, price);
        ui->tableWidget->setItem(i, 3, profitability);
    }

    ui->label_4->setText(QString::number(kwota));
    ui->label_7->setText(QString::number(alko));

}


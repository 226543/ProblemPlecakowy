#ifndef SOLVERDIALOG_H
#define SOLVERDIALOG_H
#include <QTableWidget>
#include <QDialog>
#include <solver.hh>

namespace Ui {
class SolverDialog;
}

class SolverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SolverDialog(QWidget *parent = 0);
    ~SolverDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SolverDialog *ui;
    Solver* kp;
    Backpack bag;
};

#endif // SOLVERDIALOG_H

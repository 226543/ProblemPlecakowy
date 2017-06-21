#ifndef GAME_H
#define GAME_H
#include <QTableWidget>
#include <solver.hh>
#include <QDialog>

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_4_clicked();

private:
    Ui::Game *ui;
    Solver* kp;
    Backpack bag;   // przechowuje elementy wybrane przez algorytm DP
    Backpack bag2;  // przechowuje elementy wybrane przez użytownika
    std::vector<Item> toChoose;  // przechowuje elementy mozliwe do wyboru
    std::vector<Item> selected;  // przechowuje wybrane elementy
    double budzet = 0;
    void clearGame();
    double checkWeightOfBackpack();
};

#endif // GAME_H

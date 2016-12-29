#ifndef SUDOKU_MAIN_H
#define SUDOKU_MAIN_H

#include <QWidget>

namespace Ui {
class sudoku_main;
}

class sudoku_main : public QWidget
{
    Q_OBJECT

public:
    explicit sudoku_main(QWidget *parent = 0);
    ~sudoku_main();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sudoku_main *ui;
};

#endif // SUDOKU_MAIN_H

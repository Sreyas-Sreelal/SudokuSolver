#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <QMainWindow>
#include "sudoku_main.h"
namespace Ui {
class SudokuSolver;
}

class SudokuSolver : public QMainWindow
{
    Q_OBJECT

public:
    explicit SudokuSolver(QWidget *parent = 0);
    ~SudokuSolver();

private slots:
    void on_Start_Button_clicked();

    void on_Quit_Button_clicked();

private:
    Ui::SudokuSolver *ui;
    sudoku_main sudoku_obj;
};

#endif // SUDOKUSOLVER_H

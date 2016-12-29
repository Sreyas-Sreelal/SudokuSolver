#include "sudokusolver.h"
#include "ui_sudokusolver.h"
#include <qmovie.h>
#include <QMediaPlayer>
#include <QMediaPlaylist>

SudokuSolver::SudokuSolver(QWidget *parent) : ui(new Ui::SudokuSolver)
{
    ui->setupUi(this);
    this->setFixedSize(650,500);
    QMovie *movie = new QMovie(":/img/sudoku.gif");
    ui->background->setMovie(movie);
    movie->start();
    QMediaPlayer* player = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    player->setMedia(QUrl("http://sreyas.tk/song.mp3"));
    player->setVolume(80);
    player->play();
}

SudokuSolver::~SudokuSolver()
{
    delete ui;
}

void SudokuSolver::on_Start_Button_clicked()
{
    this->close();
    sudoku_obj.show();
}

void SudokuSolver::on_Quit_Button_clicked()
{
    this->close();
}

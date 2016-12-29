#include "sudoku_main.h"
#include "ui_sudoku_main.h"
#include<qmessagebox.h>
#include "qtextstream.h"
#include "qmovie.h"

int str2int(QString);

int str2int(QString a)
{
     if(a.isNull()||a.isEmpty())
    return 0;
    return a.toInt();
}
QTextStream& qStdOut()
{
    static QTextStream ts( stdout );
    return ts;
}
sudoku_main::sudoku_main(QWidget *parent) : QWidget(parent), ui(new Ui::sudoku_main)
{
    ui->setupUi(this);
    this->setFixedSize(734,603);
    QMovie *movie = new QMovie(":/img/bat.gif");
    ui->background->setMovie(movie);
    movie->start();
}

sudoku_main::~sudoku_main()
{
    delete ui;
}
int  a[9][9]; //=
/*{
    {0,8,0, 7,1,2, 0,9,0},
    {0,0,0, 0,0,0, 7,1,0},
    {0,0,0, 0,9,4, 2,6,0},

    {0,0,0, 3,6,0, 4,0,5},
    {5,0,0, 0,0,0, 0,0,9},
    {7,0,6, 0,2,5, 0,0,0},

    {0,5,8, 2,7,0, 0,0,0},
    {0,1,7, 0,0,0, 0,0,0},
    {0,6,0, 9,4,1, 0,5,7}
};*/
bool ROW(int [][9],int,int);
bool Solve(int [][9]);

void sudoku_main::on_pushButton_clicked()
{


    a[0][0] = str2int(ui->box1->toPlainText());
    a[0][1] = str2int(ui->box2->toPlainText());
    a[0][2] = str2int(ui->box3->toPlainText());
    a[0][3] = str2int(ui->box4->toPlainText());
    a[0][4] = str2int(ui->box5->toPlainText());
    a[0][5] = str2int(ui->box6->toPlainText());
    a[0][6] = str2int(ui->box7->toPlainText());
    a[0][7] = str2int(ui->box8->toPlainText());
    a[0][8] = str2int(ui->box9->toPlainText());

    a[1][0] = str2int(ui->box10->toPlainText());
    a[1][1] = str2int(ui->box11->toPlainText());
    a[1][2] = str2int(ui->box12->toPlainText());
    a[1][3] = str2int(ui->box13->toPlainText());
    a[1][4] = str2int(ui->box14->toPlainText());
    a[1][5] = str2int(ui->box15->toPlainText());
    a[1][6] = str2int(ui->box16->toPlainText());
    a[1][7] = str2int(ui->box17->toPlainText());
    a[1][8] = str2int(ui->box18->toPlainText());

    a[2][0] = str2int(ui->box19->toPlainText());
    a[2][1] = str2int(ui->box20->toPlainText());
    a[2][2] = str2int(ui->box21->toPlainText());
    a[2][3] = str2int(ui->box22->toPlainText());
    a[2][4] = str2int(ui->box23->toPlainText());
    a[2][5] = str2int(ui->box24->toPlainText());
    a[2][6] = str2int(ui->box25->toPlainText());
    a[2][7] = str2int(ui->box26->toPlainText());
    a[2][8] = str2int(ui->box27->toPlainText());

    a[3][0] = str2int(ui->box28->toPlainText());
    a[3][1] = str2int(ui->box29->toPlainText());
    a[3][2] = str2int(ui->box30->toPlainText());
    a[3][3] = str2int(ui->box31->toPlainText());
    a[3][4] = str2int(ui->box32->toPlainText());
    a[3][5] = str2int(ui->box33->toPlainText());
    a[3][6] = str2int(ui->box34->toPlainText());
    a[3][7] = str2int(ui->box35->toPlainText());
    a[3][8] = str2int(ui->box36->toPlainText());

    a[4][0] = str2int(ui->box37->toPlainText());
    a[4][1] = str2int(ui->box38->toPlainText());
    a[4][2] = str2int(ui->box39->toPlainText());
    a[4][3] = str2int(ui->box40->toPlainText());
    a[4][4] = str2int(ui->box41->toPlainText());
    a[4][5] = str2int(ui->box42->toPlainText());
    a[4][6] = str2int(ui->box43->toPlainText());
    a[4][7] = str2int(ui->box44->toPlainText());
    a[4][8] = str2int(ui->box45->toPlainText());

    a[5][0] = str2int(ui->box46->toPlainText());
    a[5][1] = str2int(ui->box47->toPlainText());
    a[5][2] = str2int(ui->box48->toPlainText());
    a[5][3] = str2int(ui->box49->toPlainText());
    a[5][4] = str2int(ui->box50->toPlainText());
    a[5][5] = str2int(ui->box51->toPlainText());
    a[5][6] = str2int(ui->box52->toPlainText());
    a[5][7] = str2int(ui->box53->toPlainText());
    a[5][8] = str2int(ui->box54->toPlainText());

    a[6][0] = str2int(ui->box55->toPlainText());
    a[6][1] = str2int(ui->box56->toPlainText());
    a[6][2] = str2int(ui->box57->toPlainText());
    a[6][3] = str2int(ui->box58->toPlainText());
    a[6][4] = str2int(ui->box59->toPlainText());
    a[6][5] = str2int(ui->box60->toPlainText());
    a[6][6] = str2int(ui->box61->toPlainText());
    a[6][7] = str2int(ui->box62->toPlainText());
    a[6][8] = str2int(ui->box63->toPlainText());

    a[7][0] = str2int(ui->box64->toPlainText());
    a[7][1] = str2int(ui->box65->toPlainText());
    a[7][2] = str2int(ui->box66->toPlainText());
    a[7][3] = str2int(ui->box67->toPlainText());
    a[7][4] = str2int(ui->box68->toPlainText());
    a[7][5] = str2int(ui->box69->toPlainText());
    a[7][6] = str2int(ui->box70->toPlainText());
    a[7][7] = str2int(ui->box71->toPlainText());
    a[7][8] = str2int(ui->box72->toPlainText());

    a[8][0] = str2int(ui->box73->toPlainText());
    a[8][1] = str2int(ui->box74->toPlainText());
    a[8][2] = str2int(ui->box75->toPlainText());
    a[8][3] = str2int(ui->box76->toPlainText());
    a[8][4] = str2int(ui->box77->toPlainText());
    a[8][5] = str2int(ui->box78->toPlainText());
    a[8][6] = str2int(ui->box79->toPlainText());
    a[8][7] = str2int(ui->box80->toPlainText());
    a[8][8] = str2int(ui->box81->toPlainText());

    //debug
    for(int i=0;i<9;i++)
   {
         for(int j=0;j<9;j++)
         {
            qStdOut()<<a[i][j]<<" ";
            if((j+1)%3==0)qStdOut()<<" ";
         }
        qStdOut()<<"\n";
        if((i+1)%3==0)qStdOut()<<"\n";
    }
    if(Solve(a))
    {

       ui->box1->setPlainText(QString::number(a[0][0]));
       ui->box2->setPlainText(QString::number(a[0][1]));
       ui->box3->setPlainText(QString::number(a[0][2]));
       ui->box4->setPlainText(QString::number(a[0][3]));
       ui->box5->setPlainText(QString::number(a[0][4]));
       ui->box6->setPlainText(QString::number(a[0][5]));
       ui->box7->setPlainText(QString::number(a[0][6]));
       ui->box8->setPlainText(QString::number(a[0][7]));
       ui->box9->setPlainText(QString::number(a[0][8]));


       ui->box10->setPlainText(QString::number(a[1][0]));
       ui->box11->setPlainText(QString::number(a[1][1]));
       ui->box12->setPlainText(QString::number(a[1][2]));
       ui->box13->setPlainText(QString::number(a[1][3]));
       ui->box14->setPlainText(QString::number(a[1][4]));
       ui->box15->setPlainText(QString::number(a[1][5]));
       ui->box16->setPlainText(QString::number(a[1][6]));
       ui->box17->setPlainText(QString::number(a[1][7]));
       ui->box18->setPlainText(QString::number(a[1][8]));

       ui->box19->setPlainText(QString::number(a[2][0]));
       ui->box20->setPlainText(QString::number(a[2][1]));
       ui->box21->setPlainText(QString::number(a[2][2]));
       ui->box22->setPlainText(QString::number(a[2][3]));
       ui->box23->setPlainText(QString::number(a[2][4]));
       ui->box24->setPlainText(QString::number(a[2][5]));
       ui->box25->setPlainText(QString::number(a[2][6]));
       ui->box26->setPlainText(QString::number(a[2][7]));
       ui->box27->setPlainText(QString::number(a[2][8]));

       ui->box28->setPlainText(QString::number(a[3][0]));
       ui->box29->setPlainText(QString::number(a[3][1]));
       ui->box30->setPlainText(QString::number(a[3][2]));
       ui->box31->setPlainText(QString::number(a[3][3]));
       ui->box32->setPlainText(QString::number(a[3][4]));
       ui->box33->setPlainText(QString::number(a[3][5]));
       ui->box34->setPlainText(QString::number(a[3][6]));
       ui->box35->setPlainText(QString::number(a[3][7]));
       ui->box36->setPlainText(QString::number(a[3][8]));

       ui->box37->setPlainText(QString::number(a[4][0]));
       ui->box38->setPlainText(QString::number(a[4][1]));
       ui->box39->setPlainText(QString::number(a[4][2]));
       ui->box40->setPlainText(QString::number(a[4][3]));
       ui->box41->setPlainText(QString::number(a[4][4]));
       ui->box42->setPlainText(QString::number(a[4][5]));
       ui->box43->setPlainText(QString::number(a[4][6]));
       ui->box44->setPlainText(QString::number(a[4][7]));
       ui->box45->setPlainText(QString::number(a[4][8]));

       ui->box46->setPlainText(QString::number(a[5][0]));
       ui->box47->setPlainText(QString::number(a[5][1]));
       ui->box48->setPlainText(QString::number(a[5][2]));
       ui->box49->setPlainText(QString::number(a[5][3]));
       ui->box50->setPlainText(QString::number(a[5][4]));
       ui->box51->setPlainText(QString::number(a[5][5]));
       ui->box52->setPlainText(QString::number(a[5][6]));
       ui->box53->setPlainText(QString::number(a[5][7]));
       ui->box54->setPlainText(QString::number(a[5][8]));

       ui->box55->setPlainText(QString::number(a[6][0]));
       ui->box56->setPlainText(QString::number(a[6][1]));
       ui->box57->setPlainText(QString::number(a[6][2]));
       ui->box58->setPlainText(QString::number(a[6][3]));
       ui->box59->setPlainText(QString::number(a[6][4]));
       ui->box60->setPlainText(QString::number(a[6][5]));
       ui->box61->setPlainText(QString::number(a[6][6]));
       ui->box62->setPlainText(QString::number(a[6][7]));
       ui->box63->setPlainText(QString::number(a[6][8]));

       ui->box64->setPlainText(QString::number(a[7][0]));
       ui->box65->setPlainText(QString::number(a[7][1]));
       ui->box66->setPlainText(QString::number(a[7][2]));
       ui->box67->setPlainText(QString::number(a[7][3]));
       ui->box68->setPlainText(QString::number(a[7][4]));
       ui->box69->setPlainText(QString::number(a[7][5]));
       ui->box70->setPlainText(QString::number(a[7][6]));
       ui->box71->setPlainText(QString::number(a[7][7]));
       ui->box72->setPlainText(QString::number(a[7][8]));

       ui->box73->setPlainText(QString::number(a[8][0]));
       ui->box74->setPlainText(QString::number(a[8][1]));
       ui->box75->setPlainText(QString::number(a[8][2]));
       ui->box76->setPlainText(QString::number(a[8][3]));
       ui->box77->setPlainText(QString::number(a[8][4]));
       ui->box78->setPlainText(QString::number(a[8][5]));
       ui->box79->setPlainText(QString::number(a[8][6]));
       ui->box80->setPlainText(QString::number(a[8][7]));
       ui->box81->setPlainText(QString::number(a[8][8]));

    }
    else
    {
        QMessageBox Msgbox;
        Msgbox.setText("Not solvable");
        Msgbox.exec();
    }

 }


bool UnAssigned(int a[][9],int &i,int &j)
{
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            if(a[i][j]==0)
                return true;
    return false;
}

bool ROW(int a[][9],int in,int num)
{
    for(int i=0;i<9;i++)
        if(a[in][i]==num)
            return true;
    return false;
}

bool COLUMN(int a[][9],int in,int num)
{
    for(int i=0;i<9;i++)
        if(a[i][in]==num)
            return true;
    return false;
}

bool GRID(int a[][9],int i,int j,int num)
{
    for(int u=0;u<3;u++)
        for(int y=0;y<3;y++)
            if(a[i+u][j+y]==num)
                return true;
    return false;
}

bool Safe(int a[][9],int i,int j,int num)
{
    if(!ROW(a,i,num)&&!COLUMN(a,j,num)&&!GRID(a,i-i%3,j-j%3,num))
        return 1;
    return 0;
}

bool Solve(int a[][9])
{
    int i,j;
    if(!UnAssigned(a,i,j))
         return true;
    for(int k=1;k<=9;k++)
    {
        if(Safe(a,i,j,k))
        {
            a[i][j] = k;

            if(Solve(a))
                return true;
            a[i][j] = 0;
        }
    }
    return false;
}

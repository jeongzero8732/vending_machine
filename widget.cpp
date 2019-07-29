#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    if(money<150)
        ui->pbTea->setEnabled(false);
    if(money<200)
        ui->pbCoffee->setEnabled(false);
    if(money<200)
        ui->pbCoke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::changeMoney(int n)
{

    money += n;

    ui->lcdNumber->display(money);

    ui->pbTea->setEnabled(money>=150);
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbCoke->setEnabled(money>=200);

}

void Widget::on_pbTea_clicked()
{
    if(money<150)
        ui->pbTea->setEnabled(false);
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbReset_clicked()
{
    int R_500=money/500;
    int R_500_R=money%500;

    int R_100=R_500_R/100;
    int R_100_R=R_500_R%100;

    int R_50=R_100_R/50;
    int R_50_R=R_100_R%50;

    int R_10=R_50_R/10;

    QString str="500원 : "+QString::number(R_500)+"\n100원 : "+QString::number(R_100)+"\n50원 : "+QString::number(R_50)+"\n10원 "+QString::number(R_10);
    QMessageBox msg;
    msg.information(nullptr,"reset",str);




}

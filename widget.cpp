#include "widget.h"
#include "ui_widget.h"
#include<gl11.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    gl11_iodev_open();
    prn_open();
//    QPixmap pix("/home/naresh/Pictures/Wallpapers/Venkateswara.jpg");
//    QPixmap p("");
//    ui->label_pic->setPixmap(p.scaled(100,100,Qt::KeepAspectRatio));


    prn_write_text((unsigned char*)"Hello Keerthi",13,2);
    prn_write_text((unsigned char*)"Hello Visiontek",20,2);
    prn_write_text((unsigned char*)"Hello Vijayawada",15,2);
    prn_write_text((unsigned char*)"Hello Prathyusha",18,2);
    prn_write_text((unsigned char*)"Hello Sanjeet sir",16,2);
    prn_write_text((unsigned char*)"Hello Kerala",15,1);
    prn_write_text((unsigned char*)"Hello Praveen",17,1);
    prn_write_text((unsigned char*)"Hello Tejkiran",13,1);
    prn_write_text((unsigned char*)"Hello Sarath sir",16,1);
    prn_write_text((unsigned char*)"Hello Prasanth",14,1);


}

Widget::~Widget()
{
    delete ui;
}

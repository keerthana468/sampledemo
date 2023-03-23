
/*********************************************************************************
********************************************************************************** 
**
** Copyright (C) 2011 VISIONTEK/Linkwell Telesystem Pvt. Ltd.
** 1-11-252/1/A, Gowra Klassic, Begumpet
** Hyderabad 500016 INDIA
**
**
** This program is free software; you can redistribute it and/or modify it under
** the terms of the GNU General Public License as published by the Free Software
** Foundation; either version 2 of the License, or (at your option) any later
** version.
**
** This program is distributed in the hope that it will be useful, but WITHOUT 
** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
** FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
**
**
* Author : SANJEET K. KARN
** Dept: Research & Development
**
** File : glBattery.cpp 
** Description : This file is a part of SelfDiag Application Project for GL-11.
**		 It includes definition of class "CBattery".
**		 
**
** Modified By :M.Shashidhar.
** Modified Date : 26/06/12
**



***********************************************************************************
***********************************************************************************/
#include <QTimer>
#include <QDebug>
#include "CSBattery.h"

extern int batVolt;

/*! Constructor
 */ 
CBattery::CBattery(QWidget *parent) : QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("background-color:white");

#ifdef GL11_QT
    setGeometry(0,0,320,200);
#endif
#ifdef GL11_GNOME
    setGeometry(0,0,320,200);
#endif

//    QMovie *movie = new QMovie(":/images/battery_bg.gif");

//    imageDispLabel = new QLabel(this);

//    imageDispLabel->setMovie(movie);
//    imageDispLabel->setGeometry(20,10,320,220);
//    imageDispLabel->show();
//    movie->start();

    QFont buttonFont("Times", 11, QFont::Bold);

    batteryLabel=new QLabel(this);

    batteryLabel->setText("<h3>Battery Test</h3>");
    batteryLabel->setGeometry(0,0,320,17);
    batteryLabel->setAlignment(Qt::AlignHCenter);
    batteryLabel->setStyleSheet("background-color:gray");

    button=new QPushButton(this);

#ifdef GL11_QT
    button->setGeometry(0,33,150,25);
#endif
#ifdef GL11_GNOME
    button->setGeometry(0,83,155,25);
#endif
    button->setFlat(true);
    button->setText("  Battery Test");
    button->setFont(buttonFont);

    connect(button,SIGNAL(clicked()),this,SLOT(BattaryTest()));
}

/*! give the current voltage value of battery
 */
void CBattery::BattaryTest()
{
#ifdef GL11_DEBUG
    qDebug("showing Battery value...");
#endif
    double stripBatVolt = ((8.4)*batVolt)/1024;

    QString batValue = QString::number(stripBatVolt, 'g', 3);//bat value in 2 digits.
    QString valInd="VOLTAGE = ";
    QString volt=" V";
    QString valuemessage=valInd+batValue+volt;

    QMessageBox mesgBoxI;
    mesgBoxI.setWindowFlags(Qt::FramelessWindowHint);
    mesgBoxI.setStyleSheet("background-image: url(:/images/menu_bg.jpg)");
    mesgBoxI.setIcon(QMessageBox::Information);
    mesgBoxI.setText(valuemessage);
    mesgBoxI.setParent(this);
    mesgBoxI.setStyle(new QCleanlooksStyle);
    QTimer::singleShot(4000, &mesgBoxI, SLOT(close()));
    mesgBoxI.exec();




}


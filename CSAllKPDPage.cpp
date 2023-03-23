

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
** Author : SANJEET K. KARN
** Dept: Research & Development
**
** File : glAllKPDPage.cpp 
** Description : This file is a part of SelfDiag Application Project for GL-11.
**		 It includes definition of class "QKpd".
**		 
** Modified By :
** Modified Date :
**
***********************************************************************************
***********************************************************************************/


#include "CSAllKPDPage.h"


/*! Constructor
 */ 
QKpd::QKpd(QWidget *parent):QDialog(parent)
{
	showkeyboard=1;
	//physicalKbdstatus=1;
	#ifdef GL11_QT
	setGeometry(0,0,320,200);
	#endif
	#ifdef GL11_GNOME
//	setGeometry(0,0,320,160);
	setGeometry(0,0,316,160);
	#endif
	setStyleSheet("background-color:rgb(191,255,187)");

	labelName = new QLabel(this);

	labelName->setText("Physical+Virtual Kepad Write Test");
	labelName->setGeometry(0,0,320,15);
	labelName->setAlignment(Qt::AlignHCenter);
	labelName->setStyleSheet("background-color:gray");

	txtEdit = new QTextEdit(this);

#ifdef GL11_QT
	txtEdit->setGeometry(1,16,318,70);
#endif
#ifdef GL11_GNOME
    txtEdit->setGeometry(1,18,315,36);
#endif
    	txtEdit->setStyleSheet("color: black;""border: 1px solid #222222;""border-radius: 12px;""background-color:lightyellow;"
                           "selection-color: yellow;""selection-background-color: black;");
}

//This function will create the virtual keyboard  and it will show it.
void QKpd::keyboard()
{
    txtEdit->setFocus();
    if(showkeyboard==0)
    {    hideKeyboard();
         return;
    }
    Akpd=new qAkpd;
    Akpd->setParent(this);
    #ifdef GL11_QT
    Akpd->setGeometry(0,95,320,104);
    #endif
    #ifdef GL11_GNOME
    Akpd->setGeometry(0,55,316,100);
    #endif 
   connect(Akpd, SIGNAL(keyChar(char)),this,SLOT(receiveKeyboardChar(char)));
    Akpd->show();
    showkeyboard=0;
}
//This function will hide the virtual keyboard if it is visible.
void QKpd::hideKeyboard()
{
    Akpd->close();
    showkeyboard=1;
}
//This function will receive key-character from virtual keyboard and write it, into text area. 
void QKpd::receiveKeyboardChar(char keyevent)
{
  txtEdit->setFocus();

  switch(keyevent)
  {
        case 'a':
              txtEdit->insertPlainText("a");
              break;
        case 'A':
              txtEdit->insertPlainText("A");
              break;
        case 'b':
              txtEdit->insertPlainText("b");
              break;
        case 'B':
              txtEdit->insertPlainText("B");
              break;
        case 'c':
              txtEdit->insertPlainText("c");
              break;
        case 'C':
              txtEdit->insertPlainText("C");
              break;
        case 'd':
              txtEdit->insertPlainText("d");
              break;
        case 'D':
              txtEdit->insertPlainText("D");
              break;
        case 'e':
              txtEdit->insertPlainText("e");
              break;
        case 'E':
              txtEdit->insertPlainText("E");
              break;
        case 'f':
              txtEdit->insertPlainText("f");
              break;
        case 'F':
              txtEdit->insertPlainText("F");
              break;
        case 'g':
              txtEdit->insertPlainText("g");
              break;
        case 'G':
              txtEdit->insertPlainText("G");
              break;
        case 'h':
              txtEdit->insertPlainText("h");
              break;
        case 'H':
              txtEdit->insertPlainText("H");
              break;
        case 'i':
              txtEdit->insertPlainText("i");
              break;
        case 'I':
              txtEdit->insertPlainText("I");
              break;
        case 'j':
              txtEdit->insertPlainText("j");
              break;
        case 'J':
              txtEdit->insertPlainText("J");
              break;
        case 'k':
              txtEdit->insertPlainText("k");
              break;
        case 'K':
              txtEdit->insertPlainText("K");
              break;
        case 'l':
              txtEdit->insertPlainText("l");
              break;
        case 'L':
               txtEdit->insertPlainText("L");
               break;
        case 'm':
               txtEdit->insertPlainText("m");
               break;
        case 'M':
               txtEdit->insertPlainText("M");
               break;
        case 'n':
               txtEdit->insertPlainText("n");
               break;
        case 'N':
               txtEdit->insertPlainText("N");
               break;
        case 'o':
               txtEdit->insertPlainText("o");
               break;
        case 'O':
               txtEdit->insertPlainText("O");
               break;
        case 'p':
               txtEdit->insertPlainText("p");
               break;
        case 'P':
               txtEdit->insertPlainText("P");
               break;
        case 'q':
               txtEdit->insertPlainText("q");
               break;
        case 'Q':
               txtEdit->insertPlainText("Q");
               break;
        case 'r':
               txtEdit->insertPlainText("r");
               break;
        case 'R':
               txtEdit->insertPlainText("R");
               break;
        case 's':
               txtEdit->insertPlainText("s");
               break;
        case 'S':
               txtEdit->insertPlainText("S");
               break;
        case 't':
               txtEdit->insertPlainText("t");
               break;
        case 'T':
               txtEdit->insertPlainText("T");
               break;
        case 'u':
               txtEdit->insertPlainText("u");
               break;
        case 'U':
               txtEdit->insertPlainText("U");
               break;
        case 'v':
               txtEdit->insertPlainText("v");
               break;
        case 'V':
               txtEdit->insertPlainText("V");
               break;
        case 'w':
               txtEdit->insertPlainText("w");
               break;
        case 'W':
               txtEdit->insertPlainText("W");
               break;
        case 'x':
               txtEdit->insertPlainText("x");
               break;
        case 'X':
               txtEdit->insertPlainText("X");
               break;
        case 'y':
               txtEdit->insertPlainText("y");
               break;
        case 'Y':
               txtEdit->insertPlainText("Y");
               break;
        case 'z':
               txtEdit->insertPlainText("z");
               break;
        case 'Z':
               txtEdit->insertPlainText("Z");
               break;
        case '~':
               txtEdit->insertPlainText("~");
               break;
        case '`':
               txtEdit->insertPlainText("`");
               break;
        case '!':
               txtEdit->insertPlainText("!");
                 break;
        case '@':
               txtEdit->insertPlainText("@");
               break;
        case '#':
               txtEdit->insertPlainText("#");
               break;
        case '$':
               txtEdit->insertPlainText("$");
               break;
        case '%':
               txtEdit->insertPlainText("%");
               break;
        case '^':
               txtEdit->insertPlainText("^");
               break;
        case '&':
               txtEdit->insertPlainText("&");
               break;
        case '*':
               txtEdit->insertPlainText("*");
               break;
        case '(':
               txtEdit->insertPlainText("(");
               break;
        case ')':
               txtEdit->insertPlainText(")");
               break;
        case '-':
               txtEdit->insertPlainText("-");
               break;
        case '_':
               txtEdit->insertPlainText("_");
               break;
        case '+':
               txtEdit->insertPlainText("+");
               break;
        case '=':
               txtEdit->insertPlainText("=");
               break;
        case '{':
               txtEdit->insertPlainText("{");
               break;
        case '}':
               txtEdit->insertPlainText("}");
               break;
        case '[':
               txtEdit->insertPlainText("[");
               break;
        case ']':
               txtEdit->insertPlainText("]");
               break;
        case '\\':
               txtEdit->insertPlainText("\\");
               break;
        case '|':
               txtEdit->insertPlainText("|");
               break;
        case ';':
               txtEdit->insertPlainText(";");
               break;
        case ':':
               txtEdit->insertPlainText(":");
               break;
        case '\'':
               txtEdit->insertPlainText("'");
               break;
        case '"':
               txtEdit->insertPlainText("\"");
               break;
        case ',':
               txtEdit->insertPlainText(",");
               break;
        case '.':
               txtEdit->insertPlainText(".");
               break;
        case '<':
               txtEdit->insertPlainText("<");
               break;
        case '>':
               txtEdit->insertPlainText(">");
               break;
        case '?':
               txtEdit->insertPlainText("?");
               break;
        case '/':
               txtEdit->insertPlainText("/");
               break;
    }

  switch(keyevent)
  {
    case 10:
            txtEdit->textCursor().deletePreviousChar();
            break;
    case 11:
            txtEdit->insertPlainText(" ");
            break;
    case 12:
            txtEdit->clear();
            break;
    case 13:
            txtEdit->insertPlainText("\n");
            break;
  }

  switch(keyevent)
  {
    case  0:
            txtEdit->insertPlainText("0");
            break;
    case  1:
            txtEdit->insertPlainText("1");
            break;
    case  2:
            txtEdit->insertPlainText("2");
            break;
    case  3:
            txtEdit->insertPlainText("3");
            break;
    case  4:
            txtEdit->insertPlainText("4");
            break;
    case  5:
            txtEdit->insertPlainText("5");
            break;
    case  6:
            txtEdit->insertPlainText("6");
            break;
    case  7:
            txtEdit->insertPlainText("7");
            break;
    case  8:
            txtEdit->insertPlainText("8");
            break;
    case  9:
            txtEdit->insertPlainText("9");
            break;
  }

}



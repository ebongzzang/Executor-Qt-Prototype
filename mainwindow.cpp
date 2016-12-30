#include "mainwindow.h"
#include "stdafx.h"
#include "LoginUi.h"

PlanBUIClass::PlanBUIClass(QWidget *parent) :
	QMainWindow(parent),
	mainLayout(new MainForm(this))
{

}

void PlanBUIClass::execLogin(std::string ID, std::string PW)
{
	login = new LoginUI(myWidget);
	login-> makeLoginForm(); // 버튼 클릭시 LoginCheck 실행
	login->enterCompareAccount(ID, PW); // Compare Id and Password 
}

void PlanBUIClass::popupMsgbox(const char * text)
{
	QMessageBox msgBox;
	msgBox.setText(text);
	msgBox.setStandardButtons(QMessageBox::Ok);
	msgBox.exec();
}


PlanBUIClass::~PlanBUIClass()
{
   
}


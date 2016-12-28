#include "mainwindow.h"
#include "stdafx.h"
#include "LoginUi.h"

PlanBUIClass::PlanBUIClass(QWidget *parent) :
	QMainWindow(parent),
	mainLayout(new MainForm())
{
	
	QWidget* window =  mainLayout->setMainLayout(this); //set Menu, title, etc..
	execLogin(window,"hi","hello"); //login
	// need fix
}

void PlanBUIClass::execLogin(QWidget *belongWidget, std::string ID, std::string PW)
{
	login = new LoginUI(belongWidget);
	login-> makeLoginForm(belongWidget); // 버튼 클릭시 LoginCheck 실행
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


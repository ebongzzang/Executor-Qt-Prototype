#include "mainwindow.h"
#include "stdafx.h"
#include "LoginUi.h"

PlanBUIClass::PlanBUIClass(QWidget *parent) :
	QMainWindow(parent),
	mainLayout(new MainForm())
{
	mainLayout->setMainLayout(this); //set Menu, title, etc..
	centralWidget = new QWidget(this); //mainWidget on mainwindow
	this->setCentralWidget(centralWidget);
	execLogin(centralWidget); //login
	// mainLayout->setBackroundTab
	// need fix
}

void PlanBUIClass::execLogin(QWidget *belongWidget)
{
	login = new LoginUI(belongWidget);
	login-> makeLoginForm(belongWidget); // 버튼 클릭시 LoginCheck 실행
	login->enterCompareAccount("hi", "hello"); // Compare Id and Password 
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


#include "mainwindow.h"
#include "stdafx.h"
#include "LoginUi.h"
//메소드들 페이즈, 기능 별로 분리 필요

PlanBUIClass::PlanBUIClass(QWidget *parent) :
	QMainWindow(parent),
	mainLayout(new MainForm())
{
	mainLayout->setMainLayout(this);

	centralWidget = new QWidget(this);
	centralWidget->setObjectName(QStringLiteral("centralWidget"));
	this->setCentralWidget(centralWidget);

	execLogin(centralWidget);
}

void PlanBUIClass::execLogin(QWidget *belongWidget)
{
	login = new LoginUI(belongWidget);
	login-> makeLoginForm(belongWidget);
	login->enterCompareAccount("hi", "hello");

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


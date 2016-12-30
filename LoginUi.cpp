#include "LoginUi.h"
#include "mainwindow.h"
#include "MainTab.h"
#include <memory>
LoginUI::LoginUI(QWidget *parent)
	: QWidget(parent) ,myWidget(parent)
{

}

void LoginUI::loginCheck()
{
	
	if ((QString::compare(inputID->text(), QString::fromStdString(dbID), Qt::CaseSensitive) == 0) && (QString::compare(inputPW->text(), QString::fromStdString(dbPW), Qt::CaseSensitive)) == 0)
	{
		QMessageBox msgBox;
		msgBox.setText("yeah");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		tempWidget->close();
		MainTab * tab = new MainTab(myWidget);
		tab->setTabWidget();
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("no");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
	}

}

void LoginUI::enterCompareAccount(std::string id, std::string pw) //temporary
{
	dbID = id;
	dbPW = pw;
}



LoginUI::~LoginUI()
{
	delete tempWidget;
	delete submitButton;
	delete inputID;
	delete inputPW;
}
void LoginUI::makeLoginForm()
{
	tempWidget = new QWidget(myWidget);
	QLabel * labelId = new QLabel(tempWidget);
	labelId->setObjectName(QStringLiteral("labelid"));
	labelId->setGeometry(QRect(50, 40, 47, 13));
	labelId->setText(QApplication::translate("LoginUI", "ID", 0));

	QLabel * labelPw = new QLabel(tempWidget);
	labelPw->setObjectName(QStringLiteral("labelPw"));
	labelPw->setGeometry(QRect(30, 70, 47, 13));
	labelPw->setText(QApplication::translate("LoginUI", "PASSWORD", 0));

	submitButton = new QPushButton(tempWidget);
	submitButton->setObjectName(QStringLiteral("pushButton"));
	submitButton->setGeometry(QRect(300, 50, 75, 23));
	submitButton->setText(QApplication::translate("LoginUI", "submitButton", 0));

	inputID = new QLineEdit(tempWidget);
	inputID->setObjectName(QStringLiteral("lineEdit"));
	inputID->setGeometry(QRect(130, 40, 113, 20));

	inputPW = new QLineEdit(tempWidget);
	inputPW->setObjectName(QStringLiteral("lineEdit_2"));
	inputPW->setGeometry(QRect(130, 70, 113, 20));

	connect(submitButton, &QPushButton::clicked, this, [this] {loginCheck(); });
}


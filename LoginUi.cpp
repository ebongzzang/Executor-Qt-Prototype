#include "LoginUi.h"
#include "mainwindow.h"

LoginUI::LoginUI(QWidget *parent)
	: QWidget(parent)
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
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("no");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
	}

}

void LoginUI::enterCompareAccount(std::string id, std::string pw)
{
	dbID = id;
	dbPW = pw;
}

LoginUI::~LoginUI()
{
	delete submitButton;
	delete inputID;
	delete inputPW;
}
void LoginUI::makeLoginForm(QWidget * belongWidget)
{
	
	QLabel * labelId = new QLabel(belongWidget);
	labelId->setObjectName(QStringLiteral("labelid"));
	labelId->setGeometry(QRect(50, 40, 47, 13));
	labelId->setText(QApplication::translate("LoginUI", "ID", 0));

	QLabel * labelPw = new QLabel(belongWidget);
	labelPw->setObjectName(QStringLiteral("labelPw"));
	labelPw->setGeometry(QRect(30, 70, 47, 13));
	labelPw->setText(QApplication::translate("LoginUI", "PASSWORD", 0));

	submitButton = new QPushButton(belongWidget);
	submitButton->setObjectName(QStringLiteral("pushButton"));
	submitButton->setGeometry(QRect(300, 50, 75, 23));
	submitButton->setText(QApplication::translate("LoginUI", "submitButton", 0));

	inputID = new QLineEdit(belongWidget);
	inputID->setObjectName(QStringLiteral("lineEdit"));
	inputID->setGeometry(QRect(130, 40, 113, 20));

	inputPW = new QLineEdit(belongWidget);
	inputPW->setObjectName(QStringLiteral("lineEdit_2"));
	inputPW->setGeometry(QRect(130, 70, 113, 20));

	connect(submitButton, &QPushButton::clicked, this, [this] {loginCheck(); });
}


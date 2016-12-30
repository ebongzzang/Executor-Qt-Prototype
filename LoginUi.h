#ifndef LoginUI_H
#define LoginUI_H

#include "stdafx.h"

class LoginUI : public QWidget
{
	Q_OBJECT

private:

	QLineEdit *inputID;
	QLineEdit *inputPW;
	QPushButton *submitButton;
	QWidget * tempWidget;
	QWidget * myWidget;
	std::string dbID;
	std::string dbPW; //�α��� â�� ���� ���� �޴� ����(ex. sql)
	bool result;

	

private slots:
	void loginCheck();
public:
	void enterCompareAccount(std::string id, std::string pw);
	void makeLoginForm();
	LoginUI(QWidget *parent = 0);
	~LoginUI();

};
#endif // !LoginUI
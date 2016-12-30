#include "MainTab.h"

MainTab::MainTab(QWidget * parent)
	:QTabWidget(parent), parentWidget(parent)
{

}

MainTab::~MainTab()
{

}

QWidget* MainTab::addTabPage(QWidget * belongTab)
{
	QWidget * tabBackup = new QWidget();
	tabBackup->setObjectName(QStringLiteral("tabBackup"));
	tabWidget->addTab(tabBackup, QString());
	return belongTab;
}
QWidget * getTabPage(QWidget *)
{
	QWidget * hi = new QWidget();
	return hi;
}
void MainTab::setTabWidget() //connect�� ���� ���� ��ġ
{
	//�� ���� �߰��ϱ�
	QTabWidget * tabWidget = new QTabWidget(parentWidget);
	tabWidget->setObjectName(QStringLiteral("tabWidget"));
	tabWidget->setGeometry(QRect(30, 100, 391, 171));
	tabWidget->resize(800, 300);

	// �ǿ� �������� �ִ� �κ��̴�. CSS�� ����ؼ� �־���. 
	tabWidget->setStyleSheet(QLatin1String("QTabBar::tab{\n"
		"    height: 30px;\n"
		"    width: 120px;\n"
		"}\n"
		"\n"
		"QTabBar::tab:first {\n"
		"     background: url(c:/backup2.png);\n"
		"}\n"
		"\n"
		"\n"
		" QTabBar::tab:middle{\n"
		"   background: url(backup4.png);\n"
		"}\n"
		"\n"
		"QTabBar::tab:first:selected{\n"
		"     background: url(backup.png);\n"
		"}\n"
		"\n"
		"QTabBar::tab:middle:selected{\n"
		"     background: url(backup3.png);\n"
		"}\n"
		"\n"
		"QTabBar::tab:last{\n"
		"     background: url(backup5.png);\n"
		"}\n"
		"QTabBar::tab:last:selected{\n"
		"     background: url(backup6.png);\n"
		"}\n"
		"\n"
		""));


	//�� 3���� ����� �κ��̴�.
	QWidget * tabBackupSub = new QWidget(tabBackup);

	QWidget *  tabRecovery = new QWidget(tabWidget);
	tabRecovery->setObjectName(QStringLiteral("tabRecovery"));
	tabWidget->addTab(tabRecovery, QString());

	QWidget * tabRecoverySub = new QWidget(tabRecovery);

	QWidget * tabStatus = new QWidget(tabWidget);
	tabStatus->setObjectName(QStringLiteral("tabStatus"));
	tabWidget->addTab(tabStatus, QString());

	QWidget * tabStatusSub = new QWidget(tabStatus);
	tabWidget->show();
}
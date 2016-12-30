#ifndef MainTab_H
#define MainTab_H
#include <stdafx.h>
#include <vector>

class MainTab : QTabWidget
{
	Q_OBJECT

	public:
		void setTabWidget();
		MainTab(QWidget * parent);
		~MainTab();
		QWidget * addTabPage(QWidget * belongTab);

	private:
		QWidget * parentWidget;

		QWidget * tabBackup;
		QWidget * tabBackupSub; //tabBackup

		QWidget * tabRecovery;
		QWidget * tabRecoverySub; //tabBackup

		QWidget * tabStatus;
		QWidget * tabStatusSub; //tabBackup
		QTabWidget *tabWidget;

		std::vector<QWidget *> widgetVector;
};

#endif
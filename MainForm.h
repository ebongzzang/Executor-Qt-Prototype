#ifndef MainForm_H
#define MainForm_H

#include "stdafx.h"

class MainForm
{
public:
	~MainForm();
	void setMainLayout(QMainWindow * belongWindow);
	void setBackroundTab(QWidget *belongWidget);

private:

	QVBoxLayout * mainLayout;

	QMenuBar *menuBar;
	QMenu *menuSetup;
	QMenu *menuHelp;
	QAction *actionNew;
	QToolBar *mainToolBar;
	QStatusBar *statusBar; //MainLayout

	QTabWidget *tabWidget;
	QWidget * tabBackup;
	QWidget * tabBackupSub; //tabBackup

	QWidget * tabRecovery;
	QWidget * tabRecoverySub; //tabBackup

	QWidget * tabStatus;
	QWidget * tabStatusSub; //tabBackup
};


#endif //

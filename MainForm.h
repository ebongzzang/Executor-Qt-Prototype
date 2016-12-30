#ifndef MainForm_H
#define MainForm_H

#include "stdafx.h"

class MainForm
{
public:
	MainForm(QMainWindow * belongWindow);
	~MainForm();
	void setMainLayout(); //Retrun MainWidget
	QWidget* getCentralWidget();
	void setBackroundTab();

private:
	QMainWindow *parentWindow;
	QWidget *centralWidget;

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

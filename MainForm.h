#ifndef MainForm_H
#define MainForm_H

#include "stdafx.h"

class MainForm
{
public:
	~MainForm();
	void setMainLayout(QMainWindow * belongWindow);
	void retranslateUi(QMainWindow *PlanBUIClbeass);

private:

	QMenuBar *menuBar;
	QMenu *menuSetup;
	QMenu *menuHelp;

	QAction *actionNew;

	QToolBar *mainToolBar;
	QStatusBar *statusBar;
	QToolBar *toolBar;
	QToolBar *toolBar_2;
	QVBoxLayout * mainLayout;
};


#endif //

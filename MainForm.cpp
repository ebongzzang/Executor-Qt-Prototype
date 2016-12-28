#include "MainForm.h"

QWidget* MainForm::setMainLayout(QMainWindow * belongWindow)
{
	centralWidget = new QWidget(belongWindow); //mainWidget on mainwindow
	belongWindow->setCentralWidget(centralWidget);
	belongWindow->setWindowTitle(QApplication::translate("PlanBUIClass", "PlanBUIClass", 0));
	belongWindow->setObjectName(QStringLiteral("PlanBUIClass")); //ObjectName 생략 가능
	belongWindow->resize(1057, 634);

	menuBar = new QMenuBar(belongWindow);
	menuBar->setObjectName(QStringLiteral("menuBar"));
	menuBar->setGeometry(QRect(0, 0, 1057, 21));

	menuHelp = new QMenu(menuBar);
	menuHelp->setObjectName(QStringLiteral("menuHelp"));
	menuHelp->setTitle(QApplication::translate("PlanBUIClass", "Help", 0));

	menuSetup = new QMenu(menuBar);
	menuSetup->setObjectName(QStringLiteral("menuSetup"));

	actionNew = new QAction(belongWindow);
	actionNew->setObjectName(QStringLiteral("actionNew"));
	menuSetup->addAction(actionNew);
	menuSetup->addSeparator();
	menuSetup->setTitle(QApplication::translate("PlanBUIClass", "Setup", 0));



	menuBar->addAction(menuSetup->menuAction());
	menuBar->addAction(menuHelp->menuAction());
	
	

	belongWindow->setMenuBar(menuBar);

//	mainToolBar = new QToolBar(belongWindow);
//	mainToolBar->setObjectName(QStringLiteral("mainToolBar"));

//	belongWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
	statusBar = new QStatusBar(belongWindow);
	statusBar->setObjectName(QStringLiteral("statusBar"));
	belongWindow->setStatusBar(statusBar);

//	toolBar = new QToolBar(belongWindow);
//	toolBar->setObjectName(QStringLiteral("toolBar"));
//	belongWindow->addToolBar(Qt::TopToolBarArea, toolBar);

//	toolBar_2 = new QToolBar(belongWindow);
//	toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
//	belongWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

	return centralWidget;
}



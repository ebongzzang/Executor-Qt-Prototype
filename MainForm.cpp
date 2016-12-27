#include "MainForm.h"

void MainForm::setMainLayout(QMainWindow * belongWindow)
{
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


}

void MainForm::setBackroundTab(QWidget *belongWidget)
{
		//탭 위젯 추가하기
		tabWidget = new QTabWidget(belongWidget);
		tabWidget->setObjectName(QStringLiteral("tabWidget"));
		tabWidget->setGeometry(QRect(30, 100, 391, 171));
		tabWidget->resize(800, 300);

		// 탭에 아이콘을 넣는 부분이다. CSS를 사용해서 넣어줌. 
		tabWidget->setStyleSheet(QLatin1String("QTabBar::tab{\n"
			"    height: 30px;\n"
			"    width: 120px;\n"
			"}\n"
			"\n"
			"QTabBar::tab:first {\n"
			"     background: url(backup2.png);\n"
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
		//탭 3개를 만드는 부분이다.
		tabBackup = new QWidget();
		tabBackup->setObjectName(QStringLiteral("tabBackup"));
		tabWidget->addTab(tabBackup, QString());

		tabBackupSub = new QWidget(tabBackup);

		tabRecovery = new QWidget();
		tabRecovery->setObjectName(QStringLiteral("tabRecovery"));
		tabWidget->addTab(tabRecovery, QString());

		tabRecoverySub = new QWidget(tabRecovery);

		tabStatus = new QWidget();
		tabStatus->setObjectName(QStringLiteral("tabStatus"));
		tabWidget->addTab(tabStatus, QString());

		tabStatusSub = new QWidget(tabStatus);

	}

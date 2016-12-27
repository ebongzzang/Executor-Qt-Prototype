#ifndef PlanBUIClass_H
#define PlanBUIClass_H

#include "stdafx.h"
#include "LoginUi.h"
#include "MainForm.h"


class PlanBUIClass : public QMainWindow
{
    Q_OBJECT

public:
    PlanBUIClass(QWidget *parent = 0);
    ~PlanBUIClass();
	void execLogin(QWidget *belongWidget);
	void popupMsgbox(const char * text);

private slots:


private:
	MainForm * mainLayout;
	QWidget *centralWidget;
	LoginUI * login;
	

    QFileSystemModel *dirmodel;
    QStandardItemModel *model;

  
    std::string absPath;

    QWidget *BackupWidget_1; //Login 창 이후 CentralWidget
    QTabWidget *tabWidget; //Backup,Recvoery,Status 가 들어가는 탭 위젯

    //추가 되는 탭들
    QWidget *tabBackup; //BackupPhase1
        QWidget *tabBackupSub;
         QPushButton *pathButton;


         QPushButton *nextButtonBackup;
         QPushButton *prevButtonBackup;

         QDialog *treeDialog;
            QTreeView *treeView;

        QLabel* pathLabel_2;

        QWidget *tabPhase2; //BackupPhase2

         QPushButton *ButtonBakPerio;
         QTableView *recoverytable;

    int tabindex=0;
    int rowindex=0;
    int backupType;
    int backupPeriod;
    int recoverRow;

    QWidget *tabRecovery;
    QWidget *tabRecoverySub;

    QWidget *tabStatus;
    QWidget *tabStatusSub;
    QTableWidget* table = new QTableWidget();
    QTableWidgetItem* tableItem = new QTableWidgetItem();


    QWidget *tabBackupSub2;

    //tray Menu
    QSystemTrayIcon *trayIcon;

       QMenu *trayMenu;
       QAction *showaction;
       QAction *exitaction;

};

#endif // PlanBUIClass_H

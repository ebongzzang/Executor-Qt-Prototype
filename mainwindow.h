#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stdafx.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void viewFilelist(std::string sPath, QWidget * widget, QTreeView *treepath);
    void popupMsgbox(const char * text);
    void makeNextButton(const char * buttonName, const char * belongWidget);
    void recoveryPhase1();
    void addRowToRecoveryTable(const char * title,const char * path, const char * time);
    void delRowToRecvoeryTable(const char * title);
    void closeEvent(QCloseEvent *event);
    void iconSizenActivated(QSystemTrayIcon::ActivationReason reason);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void getPathFromTree();
    void cratePathDialog();
    void convertPathToLabel();
    void backupPhase2();
    void goNextPage(QWidget *currentTab);
    void backBeforePage(QWidget *currentTab);


private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirmodel;
    QStandardItemModel *model;

    std::string dbID = "";
    std::string dbPW = ""; //로그인 창의 비교할 값을 받는 변수(ex. sql)

    QWidget *BackupWidget_1; //Login 창 이후 CentralWidget
    QTabWidget *tabWidget; //Backup,Recvoery,Status 가 들어가는 탭 위젯

    //추가 되는 탭들
    QWidget *tabBackup; //BackupPhase1
        QWidget *tabBackupSub;
        QLabel *pathLabel_1;
         QLabel *pathLabel_2;
         QPushButton *pathButton;
         QCheckBox *checkBoxBakSys ;
         QCheckBox *checkBoxBakVol;
         QCheckBox *checkBoxBakFile;

         QPushButton *nextButtonBackup;
         QPushButton *prevButtonBackup;
         QPushButton *buttonDiaPath;
         QDialog *treeDialog;
            QTreeView *treeView;
            QString absPath;

    QWidget *tabPhase2; //BackupPhase2
        QWidget *tabPhase3; //BackupPhase2
         QWidget *tabPhase4; //BackupPhase2
         QWidget *tabPhase5; //BackupPhase2
         QWidget *tabPhase6; //BackupPhase2
         QCheckBox *checkBoxBakOnce;
         QCheckBox *checkBoxBakOnce2;
         QCheckBox *checkBoxBakOnce3;
         QCheckBox *checkBoxBakOnce4;
         QCheckBox *checkBoxBakOnce5;
         QCheckBox *checkBoxBakPerio;
         QPushButton *ButtonBakPerio;

         QTableView *recoverytable;

    int tabindex=0;
    int rowindex=0;
    QWidget *tabRecovery;
    QWidget *tabRecoverySub;

    QWidget *tabStatus;
    QWidget *tabStatusSub;
    QTableWidget* table = new QTableWidget();
    QTableWidgetItem* tableItem = new QTableWidgetItem();


    QWidget *tabBackupSub2;

    QSystemTrayIcon *trayIcon;
       QMenu *trayIconMenu;




};

#endif // MAINWINDOW_H

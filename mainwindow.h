#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stdafx.h"
#include "ui_mainwindow.h"
namespace Ui {
class MainWindow;

}

namespace Indexes {
enum tabWidgetIndex
{
    tabBackup,
    tabRecovery,
    tabStatus
};
enum tableColumn
{
    Title,
    Path,
    Time,
    Select
};
/*std::map<tableColumn,std::string> column;
column[Title] = "Title";
column[Path] = "Path";
column[Time]= "Time";
column[Select] = "Select";
*/
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool backgroundTab(void);
    bool backupPhase1(void);
    void viewFilelist(std::string sPath, QWidget * widget, QTreeView *treePath);

    void popupMsgbox(const char * text);
    void makeNextButton(const char * buttonName, const char * belongWidget);
    void recoveryPhase1();
    void addRowToRecoveryTable(const char * title,const char * path, const char * time);
    void delRowToRecvoeryTable(const char * title);
    void closeEvent(QCloseEvent *event);
    void execTrayIcon(void);
    bool loginCheck(QString id, QString PW);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void getPathFromTree(); //정해진 트리뷰를 써야함. (람다로 수정 가능)
    void cratePathDialog();
    void convertPathToLabel();
    void backupPhase2();
    void goNextPage(QWidget *currentTab);
    void backBeforePage(QWidget *currentTab);
    void mapNextBackButton(void);


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

         QCheckBox *checkBoxBakOnce;
         QCheckBox *checkBoxBakOnce2;


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

    //tray Menu
    QSystemTrayIcon *trayIcon;

       QMenu *trayMenu;
       QAction *showaction;
       QAction *exitaction;

};

#endif // MAINWINDOW_H

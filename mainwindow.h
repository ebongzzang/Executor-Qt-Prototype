#ifndef PlanBUIClass_H
#define PlanBUIClass_H
#include "stdafx.h"
#include "ui_mainwindow.h"
namespace Ui {
class PlanBUIClass;

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
enum backupType
{
    NOTFOUND=-1,
    SYSTEM=-2,
    VOLUME=-3,
    FILE=-4

};
enum backupPeriod
{
    ONCE=-2,
    Periodic=-3
};


/*std::map<tableColumn,std::string> column;
column[Title] = "Title";
column[Path] = "Path";
column[Time]= "Time";
column[Select] = "Select";
*/
}


class PlanBUIClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlanBUIClass(QWidget *parent = 0);
    bool backgroundTab(void);
    bool backupPhase1(void);
    void viewFilelist(std::string sPath, QWidget * widget, QTreeView *treePath);
    int getValueFromCheckbox(QButtonGroup *buttonGroup);
    void popupMsgbox(const char * text);
    void makeNextButton(const char * buttonName, const char * belongWidget);
    void recoveryPhase1();
    void addRowToRecoveryTable(QTableWidget *tableWidget,const char * title,const char * path, const char * time);
    void delRowToRecvoeryTable(const char * title);
    void closeEvent(QCloseEvent *event);
    void execTrayIcon(void);
    bool loginCheck(QString id, QString PW);
    ~PlanBUIClass();


private slots:
    void on_pushButton_clicked();
    void getPathFromTree(); //정해진 트리뷰를 써야함. (람다로 수정 가능)
    void cratePathDialog();
    void convertPathToLabel();
    bool backupPhase2();
    void goNextPage(QWidget *currentTab);
    void backBeforePage(QWidget *currentTab);
    void mapNextBackButton(void);


private:
    Ui::PlanBUIClass *ui;
    QFileSystemModel *dirmodel;
    QStandardItemModel *model;

    std::string dbID = "";
    std::string dbPW = ""; //로그인 창의 비교할 값을 받는 변수(ex. sql)

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
            QString absPath;

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

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
    void ViewFilelist(std::string sPath, QWidget * widget, QTreeView *treepath);
    void popup_Msgbox(const char * text);
    ~MainWindow();





private slots:
    void on_pushButton_clicked();
    void GetPathFromTree();
    void cratePathDialog();
    void convertPathToLabel();
    void backupPhase2();
   // void GetPathFromTree(QTreeView *treepath);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    std::string dbID = "";
    std::string dbPW = "";
    QWidget *BackupWidget_1;
    QWidget *BackupWidget_2;

    QLabel *pathLabel_1;
    QLabel *pathLabel_2;
    QPushButton *pathButton;

    QLabel *label_2;

    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QTabWidget *tabWidget;

    QCheckBox *checkBox ;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QPushButton *nextButtonBackup;

    QDialog *treeDialog;
    QPushButton *pathDiaButton;


    QTreeView *treeView;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QListWidget *listWidget;


    QString absPath;  
    /*
     *
     * Backup Phase 1
     *
     *
    */

};



/*     label = new QLabel(BackupWidget_1);
     label->setObjectName(QStringLiteral("label"));
     label->setGeometry(QRect(50, 40, 47, 13));

     label_2 = new QLabel(BackupWidget_1);
     label_2->setObjectName(QStringLiteral("label_2"));
     label_2->setGeometry(QRect(30, 70, 47, 13));

     pushButton = new QPushButton(BackupWidget_1);
     pushButton->setObjectName(QStringLiteral("pushButton"));
     pushButton->setGeometry(QRect(300, 50, 75, 23));

     lineEdit = new QLineEdit(BackupWidget_1);
     lineEdit->setObjectName(QStringLiteral("lineEdit"));
     lineEdit->setGeometry(QRect(130, 40, 113, 20));

     lineEdit_2 = new QLineEdit(BackupWidget_1);
     lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
     lineEdit_2->setGeometry(QRect(130, 70, 113, 20));
*/


#endif // MAINWINDOW_H

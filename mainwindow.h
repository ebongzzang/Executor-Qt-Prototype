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
    ~MainWindow();





private slots:
    void on_pushButton_clicked();
    void GetPathFromTree();
    void cratePathDialog();
    void convertPathToLabel();
   // void GetPathFromTree(QTreeView *treepath);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    std::string str1 = "";
    std::string str2 = "";
    QWidget *BackupWidget_1;

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

    QDialog *treeDialog;
    QPushButton *pathDiaButton;

    QTreeView *treeView;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QListWidget *listWidget;


    QString absPath;
};

#endif // MAINWINDOW_H

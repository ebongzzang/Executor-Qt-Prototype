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
   // void GetPathFromTree(QTreeView *treepath);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    std::string str1 = "hi";
    std::string str2 = "hello";
    QWidget *TestWidget;
    QLabel *pathLabel;
    QPushButton *pathButton;
    QLabel *label_2;

    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QTabWidget *tabWidget;

    QCheckBox *checkBox ;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;

    QDialog *treeDialog;

    QTreeView *treeView;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QListWidget *listWidget;



    QString absPath;
};

#endif // MAINWINDOW_H

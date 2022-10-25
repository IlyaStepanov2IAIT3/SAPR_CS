#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QDropEvent>
#include <QModelIndex>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <mytreewidget.h>
#include <mytablewidget.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_createTreeBt_2_clicked();
    void on_nodeBt_2_clicked();
    void on_saveBt_2_clicked();
    void on_addBt_2_clicked();
    void on_delBt_2_clicked();
    void on_treeWidget_2_itemClicked(QTreeWidgetItem *);

private:
    QWidget *widget;

    MyTreeWidget *tree;
    MyTableWidget *table;
    QPushButton *createTreeBt;
    QPushButton *saveBt;
    QPushButton *addToTopBt;
    QPushButton *addBt;
    QPushButton *deleteBt;

    QTreeWidgetItem *selected_item;

    bool isObjTreeCreated = false;

    void addItem(QTreeWidgetItem *);
    void addItem(QTreeWidget *);
};
#endif // MAINWINDOW_H

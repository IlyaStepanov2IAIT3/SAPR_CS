#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QTableWidget>
#include <QHeaderView>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>

class MyTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    explicit MyTableWidget(QWidget *parent = nullptr);
    ~MyTableWidget();

public slots:
    void receiveTableData(QString, QString, QString);
    void openFile(QTableWidgetItem *);
};

#endif // MYTABLEWIDGET_H

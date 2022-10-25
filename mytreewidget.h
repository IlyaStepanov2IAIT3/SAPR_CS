#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QWidget>
#include <QDir>
#include <QModelIndex>
#include <QTreeWidgetItem>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDebug>
#include <QMimeData>
#include <QFileInfo>

class MyTreeWidget : public QTreeWidget
{
    Q_OBJECT
private:
    QString dir = "/Users/hraesvelgr/Projects/SAPR_CS/Tree/";
public:
    explicit MyTreeWidget(QWidget *parent = nullptr);

    void createDir(QString);
    void print(QTreeWidgetItem *);
    QString fullPath(QTreeWidgetItem *);
    int filesCount(QString);
protected:
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    virtual void dropEvent(QDropEvent *event) override;
    virtual void dragMoveEvent(QDragMoveEvent *event) override;


signals:
    void sendTableData(QString, QString, QString);
};

#endif // MYTREEWIDGET_H

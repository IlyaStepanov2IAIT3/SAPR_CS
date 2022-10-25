#include "mytablewidget.h"

MyTableWidget::MyTableWidget(QWidget *parent)
    : QTableWidget{parent}
{
    setColumnCount(3);
    setColumnWidth(2, 560);
    verticalHeader()->hide();
    setHorizontalHeaderLabels(QStringList() << "Номер" << "Струк." << "Путь доступа");
    setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(this, &MyTableWidget::itemDoubleClicked, this, &MyTableWidget::openFile);
}

void MyTableWidget::receiveTableData(QString _number, QString _structure, QString _path)
{
    QTableWidgetItem *number = new QTableWidgetItem(_number);
    QTableWidgetItem *structure = new QTableWidgetItem(_structure);
    QTableWidgetItem *path = new QTableWidgetItem(_path);

    insertRow(rowCount());
    setItem(rowCount() - 1, 0, number);
    setItem(rowCount() - 1, 1, structure);
    setItem(rowCount() - 1, 2, path);

    number->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    structure->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    path->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
}

void MyTableWidget::openFile(QTableWidgetItem *item)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(item->text()));
}

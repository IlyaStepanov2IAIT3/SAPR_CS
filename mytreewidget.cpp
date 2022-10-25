#include "mytreewidget.h"

MyTreeWidget::MyTreeWidget(QWidget *parent)
    : QTreeWidget{parent}
{
    setSelectionMode(QAbstractItemView::SingleSelection);
}

MyTreeWidget::~MyTreeWidget() {}

void MyTreeWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
          event->acceptProposedAction();
    }
}

void MyTreeWidget::dropEvent(QDropEvent *event)
{
    QModelIndex index = indexAt(event->pos());
    if (!index.isValid()) {
         event->setDropAction(Qt::IgnoreAction);
         return;
       }
    QTreeWidgetItem* item = itemFromIndex(index);

    QString number;
    QString structure;
    QString newFilePath;

    for (int i = 0; i < item->text(0).length(); i++) {
        if (!item->text(0)[i].isLetter()) structure += item->text(0)[i];
    }

    foreach (const QUrl &url, event->mimeData()->urls()) {
        QString filePath = url.toLocalFile();
        newFilePath = dir + fullPath(item) + QDir::separator();
        number = '#' + QString::number(filesCount(dir) + 1).rightJustified(3, '0');
        newFilePath += number + ".pdf";
        QFile::copy(filePath, newFilePath);
    }
    event->acceptProposedAction();
    emit sendTableData(number, structure, newFilePath);
}

void MyTreeWidget::dragMoveEvent(QDragMoveEvent *event)
{
    foreach(QTreeWidgetItem* item, this->selectedItems()) item->setSelected(false);

    QModelIndex index = indexAt(event->pos());
    if (index.isValid()) this->itemFromIndex(index)->setSelected(true);
}

void MyTreeWidget::createDir(QString path)
{
    if (!QDir(dir + path).exists()) QDir().mkdir(dir + path);
}

void MyTreeWidget::print(QTreeWidgetItem *item)
{
    createDir(fullPath(item));
    for (int i = 0; i < item->childCount(); i++) print(item->child(i));
}

QString MyTreeWidget::fullPath(QTreeWidgetItem *item)
{
    QString path = item->text(0);
    while(item->parent() != NULL) {
        path = item->parent()->text(0) + QDir::separator() + path;
        item = item->parent();
    }
    return path;
}

int MyTreeWidget::filesCount(QString _dir)
{
    int resultCount = 0;
    QDir newDir(_dir);
    QStringList dirs = newDir.entryList(QDir::Dirs);
    foreach(QString tempDir, dirs) {
        if (tempDir != "." && tempDir != "..") resultCount += filesCount(_dir + tempDir + QDir::separator());
    }
    QStringList files = newDir.entryList(QDir::Files);
    for(int i = 0; i < files.length(); i++) resultCount++;
    return resultCount;
}

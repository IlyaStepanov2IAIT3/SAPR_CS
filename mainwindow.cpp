#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    widget = new QWidget();

    table = new MyTableWidget();
    setMinimumSize(1000, 500);

    tree = new MyTreeWidget();
    connect(tree, &MyTreeWidget::sendTableData, table, &MyTableWidget::receiveTableData);
    connect(tree, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(on_treeWidget_2_itemClicked(QTreeWidgetItem *)));

    tree->setHeaderLabel("Дерево объектов");
    tree->setMaximumSize(200, 800);
    tree->setColumnCount(1);
    tree->setDragEnabled(true);
    tree->setAcceptDrops(true);
    tree->setDropIndicatorShown(true);
    tree->setDragDropMode(QAbstractItemView::InternalMove);

    createTreeBt = new QPushButton("Дерево по умолчанию");
    connect(createTreeBt, SIGNAL(clicked()), this, SLOT(on_createTreeBt_2_clicked()));

    saveBt = new QPushButton("Сохранить");
    connect(saveBt, SIGNAL(clicked()), this, SLOT(on_saveBt_2_clicked()));

    addToTopBt = new QPushButton("Добавить объект");
    connect(addToTopBt, SIGNAL(clicked()), this, SLOT(on_nodeBt_2_clicked()));

    addBt = new QPushButton("Добавить вид");
    connect(addBt, SIGNAL(clicked()), this, SLOT(on_addBt_2_clicked()));

    deleteBt = new QPushButton("Удалить");
    connect(deleteBt, SIGNAL(clicked()), this, SLOT(on_delBt_2_clicked()));

    QGridLayout *layout = new QGridLayout(widget);
    layout->addWidget(tree, 1, 0);
    layout->addWidget(table, 1, 1, 1, 4);
    layout->addWidget(createTreeBt, 2, 0);
    layout->addWidget(saveBt, 2, 1);
    layout->addWidget(addToTopBt, 2, 2);
    layout->addWidget(addBt, 2, 3);
    layout->addWidget(deleteBt, 2, 4);

    setCentralWidget(widget);

    selected_item = NULL;
}

MainWindow::~MainWindow()
{
    delete selected_item;
    delete widget;
}

void MainWindow::addItem(QTreeWidget *treeWidget)
{
    QTreeWidgetItem *newItem = new QTreeWidgetItem(treeWidget);
    newItem->setFlags(newItem->flags() | Qt::ItemIsEditable);
    newItem->setText(0, "Без названия");
    newItem->setExpanded(true);
}

void MainWindow::addItem(QTreeWidgetItem *parent)
{
    QTreeWidgetItem *newItem = new QTreeWidgetItem();
    parent->insertChild(parent->childCount(), newItem);
    newItem->setFlags(newItem->flags() | Qt::ItemIsEditable);
    newItem->setText(0, "Без названия");
    if (parent)
    {
        if (parent->text(0).contains("ИРД")) newItem->setForeground(0, QBrush(QColor(0, 150, 0)));
        else if (parent->text(0).contains("ИИ")) newItem->setForeground(0, QBrush(QColor(0, 0, 255)));
        else if (parent->text(0).contains("ПД")) newItem->setForeground(0, QBrush(Qt::red));
        else if (parent->text(0).contains("РД")) newItem->setForeground(0, QBrush(QColor(255, 165, 0)));
    }
    newItem->setExpanded(true);
}

void MainWindow::on_addBt_2_clicked()
{
    addItem(selected_item);
}

void MainWindow::on_treeWidget_2_itemClicked(QTreeWidgetItem *item)
{
    selected_item = item;
    addBt->setEnabled(true);
    deleteBt->setEnabled(true);
}

void MainWindow::on_nodeBt_2_clicked()
{
    addItem(tree);
    tree->scrollToBottom();
}

void MainWindow::on_delBt_2_clicked()
{
    delete selected_item;
    selected_item = tree->currentItem();
    if (!tree->currentItem())
    {
        addBt->setEnabled(false);
        deleteBt->setEnabled(false);
    }
    isObjTreeCreated = false;
}

void MainWindow::on_saveBt_2_clicked()
{
    tree->print(tree->invisibleRootItem());
    QMessageBox::information(this, "", "Сохранение выполнено успешно");
}

void MainWindow::on_createTreeBt_2_clicked()
{
    if (!isObjTreeCreated)
    {
        tree->clear();
        QTreeWidgetItem *item1 = new QTreeWidgetItem(tree);
        QTreeWidgetItem *item1_1 = new QTreeWidgetItem(item1);
        QTreeWidgetItem *item1_1_1 = new QTreeWidgetItem(item1_1);
        QTreeWidgetItem *item1_1_2 = new QTreeWidgetItem(item1_1);
        QTreeWidgetItem *item1_1_3 = new QTreeWidgetItem(item1_1);
        QTreeWidgetItem *item1_1_4 = new QTreeWidgetItem(item1_1);
        QTreeWidgetItem *item1_1_5 = new QTreeWidgetItem(item1_1);

        QTreeWidgetItem *item1_2 = new QTreeWidgetItem(item1);
        QTreeWidgetItem *item1_2_1 = new QTreeWidgetItem(item1_2);
        QTreeWidgetItem *item1_2_2 = new QTreeWidgetItem(item1_2);
        QTreeWidgetItem *item1_2_3 = new QTreeWidgetItem(item1_2);

        QTreeWidgetItem *item1_3 = new QTreeWidgetItem(item1);
        QTreeWidgetItem *item1_3_1 = new QTreeWidgetItem(item1_3);
        QTreeWidgetItem *item1_3_2 = new QTreeWidgetItem(item1_3);
        QTreeWidgetItem *item1_3_3 = new QTreeWidgetItem(item1_3);
        QTreeWidgetItem *item1_3_4 = new QTreeWidgetItem(item1_3);

        QTreeWidgetItem *item1_4 = new QTreeWidgetItem(item1);
        QTreeWidgetItem *item1_4_1 = new QTreeWidgetItem(item1_4);
        QTreeWidgetItem *item1_4_2 = new QTreeWidgetItem(item1_4);

        QTreeWidgetItem *item2 = new QTreeWidgetItem(tree);
        QTreeWidgetItem *item2_1 = new QTreeWidgetItem(item2);
        QTreeWidgetItem *item2_1_1 = new QTreeWidgetItem(item2_1);
        QTreeWidgetItem *item2_1_2 = new QTreeWidgetItem(item2_1);
        QTreeWidgetItem *item2_1_3 = new QTreeWidgetItem(item2_1);
        QTreeWidgetItem *item2_1_4 = new QTreeWidgetItem(item2_1);
        QTreeWidgetItem *item2_1_5 = new QTreeWidgetItem(item2_1);

        QTreeWidgetItem *item2_2 = new QTreeWidgetItem(item2);
        QTreeWidgetItem *item2_2_1 = new QTreeWidgetItem(item2_2);
        QTreeWidgetItem *item2_2_2 = new QTreeWidgetItem(item2_2);
        QTreeWidgetItem *item2_2_3 = new QTreeWidgetItem(item2_2);

        QTreeWidgetItem *item2_3 = new QTreeWidgetItem(item2);
        QTreeWidgetItem *item2_3_1 = new QTreeWidgetItem(item2_3);
        QTreeWidgetItem *item2_3_2 = new QTreeWidgetItem(item2_3);
        QTreeWidgetItem *item2_3_3 = new QTreeWidgetItem(item2_3);
        QTreeWidgetItem *item2_3_4 = new QTreeWidgetItem(item2_3);

        QTreeWidgetItem *item2_4 = new QTreeWidgetItem(item2);
        QTreeWidgetItem *item2_4_1 = new QTreeWidgetItem(item2_4);
        QTreeWidgetItem *item2_4_2 = new QTreeWidgetItem(item2_4);

        item1->setText(0, "1.  Объект 1");

        item1_1->setText(0, "1.1.  ИРД");
        item1_1_1->setText(0, "1.1.1. ЗУ");
        item1_1_2->setText(0, "1.1.2. ГПЗУ");
        item1_1_3->setText(0, "1.1.3. РС");
        item1_1_4->setText(0, "1.1.4. ТУ");
        item1_1_5->setText(0, "1.1.5. Дкл");

        item1_2->setText(0, "1.2.  ИИ");
        item1_2_1->setText(0, "1.2.1.  ИГд");
        item1_2_2->setText(0, "1.2.2.  ИГл");
        item1_2_3->setText(0, "1.2.3.  ИЭ");

        item1_3->setText(0, "1.3.  ПД");
        item1_3_1->setText(0, "1.3.1. ПЗ");
        item1_3_2->setText(0, "1.3.2. СПОЗУ");
        item1_3_3->setText(0, "1.3.3. АР");
        item1_3_4->setText(0, "1.3.4. КР");

        item1_4->setText(0, "1.3.  РД");
        item1_4_1->setText(0, "1.3.1. ГП");
        item1_4_2->setText(0, "1.3.2. КЖ");

        item2->setText(0, "2.  Объект 2");

        item2_1->setText(0, "2.1.  ИРД");
        item2_1_1->setText(0, "2.1.1. ЗУ");
        item2_1_2->setText(0, "2.1.2. ГПЗУ");
        item2_1_3->setText(0, "2.1.3. РС");
        item2_1_4->setText(0, "2.1.4. ТУ");
        item2_1_5->setText(0, "2.1.5. Дкл");

        item2_2->setText(0, "2.2.  ИИ");
        item2_2_1->setText(0, "2.2.1.  ИГд");
        item2_2_2->setText(0, "2.2.2.  ИГл");
        item2_2_3->setText(0, "2.2.3.  ИЭ");

        item2_3->setText(0, "2.3.  ПД");
        item2_3_1->setText(0, "2.3.1. ПЗ");
        item2_3_2->setText(0, "2.3.2. СПОЗУ");
        item2_3_3->setText(0, "2.3.3. АР");
        item2_3_4->setText(0, "2.3.4. КР");

        item2_4->setText(0, "2.3.  РД");
        item2_4_1->setText(0, "2.3.1. ГП");
        item2_4_2->setText(0, "2.3.2. КЖ");

        item1_1_1->setForeground(0, QBrush(QColor(0, 150, 0)));
        item1_1_2->setForeground(0, QBrush(QColor(0, 150, 0)));
        item1_1_3->setForeground(0, QBrush(QColor(0, 150, 0)));
        item1_1_4->setForeground(0, QBrush(QColor(0, 150, 0)));
        item1_1_5->setForeground(0, QBrush(QColor(0, 150, 0)));

        item1_2_1->setForeground(0, QBrush(QColor(0, 0, 255)));
        item1_2_2->setForeground(0, QBrush(QColor(0, 0, 255)));
        item1_2_3->setForeground(0, QBrush(QColor(0, 0, 255)));

        item1_3_1->setForeground(0, QBrush(Qt::red));
        item1_3_2->setForeground(0, QBrush(Qt::red));
        item1_3_3->setForeground(0, QBrush(Qt::red));
        item1_3_4->setForeground(0, QBrush(Qt::red));

        item1_4_1->setForeground(0, QBrush(QColor(255, 165, 0)));
        item1_4_2->setForeground(0, QBrush(QColor(255, 165, 0)));

        item2_1_1->setForeground(0, QBrush(QColor(0, 150, 0)));
        item2_1_2->setForeground(0, QBrush(QColor(0, 150, 0)));
        item2_1_3->setForeground(0, QBrush(QColor(0, 150, 0)));
        item2_1_4->setForeground(0, QBrush(QColor(0, 150, 0)));
        item2_1_5->setForeground(0, QBrush(QColor(0, 150, 0)));

        item2_2_1->setForeground(0, QBrush(QColor(0, 0, 255)));
        item2_2_2->setForeground(0, QBrush(QColor(0, 0, 255)));
        item2_2_3->setForeground(0, QBrush(QColor(0, 0, 255)));

        item2_3_1->setForeground(0, QBrush(Qt::red));
        item2_3_2->setForeground(0, QBrush(Qt::red));
        item2_3_3->setForeground(0, QBrush(Qt::red));
        item2_3_4->setForeground(0, QBrush(Qt::red));

        item2_4_1->setForeground(0, QBrush(QColor(255, 165, 0)));
        item2_4_2->setForeground(0, QBrush(QColor(255, 165, 0)));

        tree->expandAll();
        isObjTreeCreated = true;
    }
    else QMessageBox::information(this, "", "Дерево уже сформировано");
}

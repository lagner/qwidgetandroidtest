#include <QMetaObject>
#include <QDebug>
#include <QStackedLayout>
#include <QLabel>
#include <QBrush>
#include <QPalette>
#include <QListView>
#include <QListWidget>
#include <QScroller>
#include <QListWidgetItem>
#include "mainwindow.h"
#include "commonmodel.h"
#include "itemdelegate.h"
#include "customitem.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMetaObject::invokeMethod(this, "init");
}


MainWindow::~MainWindow()
{
}


QSize MainWindow::sizeHint() const
{
    return QSize(500, 800);
}


void MainWindow::init()
{
    qDebug() << "init";

    tabs = new QTabWidget(this);
    setCentralWidget(tabs);

    model = new CommonModel(tabs);

    listv = new QListView(tabs);
    listw = new QListWidget(tabs);

    Q_ASSERT(model && listv && listw);

    initListView();
    initListWidget();

    tabs->addTab(listv, QStringLiteral("list view"));
    tabs->addTab(listw, QStringLiteral("list widget"));
}


void MainWindow::initListView()
{
    listv->setModel(model);
    listv->setItemDelegate(new ItemDelegate(listv));
#ifdef Q_OS_ANDROID
    listv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
#endif
    listv->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller::grabGesture(listv, QScroller::TouchGesture);
}


void MainWindow::initListWidget()
{
#ifdef Q_OS_ANDROID
    listw->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    listw->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
#endif
    listw->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller::grabGesture(listw, QScroller::TouchGesture);

    for (int i = 0, e = model->rowCount(QModelIndex()); i < e; ++i) {
        auto index = model->index(i, 1);
        if (index.isValid()) {
            const QString filepath = index.data((int)CommonModel::Roles::BACKGROUND).toString();

            auto custom = new CustomItem(filepath);
            auto listitem = new QListWidgetItem(listw);

            listitem->setSizeHint(custom->sizeHint());
            listw->addItem(listitem);
            listw->setItemWidget(listitem, custom);
        }
    }
}

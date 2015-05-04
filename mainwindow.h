#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QStackedLayout;
class QListView;
class QListWidget;
class QTabWidget;
class CommonModel;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Q_INVOKABLE void init();

    QSize sizeHint() const override;

private:
    void initListView();
    void initListWidget();

private:
    CommonModel* model          = nullptr;

    QTabWidget* tabs    = nullptr;
    QListView* listv    = nullptr;
    QListWidget* listw  = nullptr;
};

#endif // MAINWINDOW_H

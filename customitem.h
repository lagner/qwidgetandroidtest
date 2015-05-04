#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QLabel>

class QImage;
class QPushButton;

class CustomItem : public QLabel
{
    Q_OBJECT
public:
    CustomItem(const QString& path);

    QSize sizeHint() const override;

    void resizeEvent(QResizeEvent *);

signals:

public slots:

private:
    void initBackgroundImage();

private:
    QLabel* title       = nullptr;
    QLabel* label       = nullptr;
    QPushButton* buy    = nullptr;

    QString filepath;
    QImage backgroundOriginal;
};

#endif // CUSTOMITEM_H

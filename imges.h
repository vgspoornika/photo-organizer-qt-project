#ifndef IMGES_H
#define IMGES_H
#include <QWidget>
#include <QLabel>
#include <QPixmap>

class imges : public QWidget
{
    Q_OBJECT
public:
    explicit imges(QWidget *parent = nullptr);
    void setData(QPixmap Image, QString TitleText, QString InfoText, QString Path);
    QString getPath();
private:
    //set image label functions
    QLabel *img;
    QLabel *title;
    QLabel *info;
    QString path;

signals:

};

#endif // IMAGEITEM_H

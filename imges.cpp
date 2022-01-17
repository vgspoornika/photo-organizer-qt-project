#include "imges.h"
#include <QGridLayout>

imges::imges(QWidget *parent) : QWidget(parent)
{
 // Set the loaded image information
    img = new QLabel(this);
    title = new QLabel(this);
    info = new QLabel(this);
    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(img,0,0,0,1);
    grid->addWidget(title,0,1);
    grid->addWidget(info,1,1);
    img->setText("Image");
    title->setText("title");
    info->setText("info");
}


void imges::setData(QPixmap Image, QString TitleText, QString InfoText, QString Path)
{
 // set the data function to the main window
    img->setPixmap(Image);
    img->setFixedWidth(Image.width());
    title->setText(TitleText);
    info->setText(InfoText);
    path = Path;
}

QString imges::getPath()
{
    return path;
}

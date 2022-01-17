#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QFileDialog>
#include <QInputDialog>
#include <QListWidgetItem>
#include <QDir>
#include <QString>
#include <QRegularExpression>
#include "imges.h"
#include "math.h"
#include <QPixmap>
#include <QFileInfo>
#include <QDebug>
#include <QListView>
#include <QFileSystemModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
, ui(new Ui::MainWindow)

{
   ui->setupUi(this);


// Set directory path to the image and load the image to the scroll area
 QFileSystemModel *model = new QFileSystemModel(this);
  model->setRootPath(QDir::currentPath());

   QDir myPath("C:/Users/sures/Downloads/pix");
   myPath.setFilter (QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
   MyList = myPath.entryList();
   ui->listWidget->addItems(MyList);
   imageLabel = new QLabel(this);
   imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
   imageLabel->setScaledContents(true);
   ui->scrollArea->setWidget(imageLabel);

    this->setWindowTitle("Photo Organizer v1.0");

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::setImagesList(QString FileName)
{
    // Filter imgages from user selecting directory
    ui->listWidget_2->clear();
    QFileInfo info(FileName);
    QDir dir(info.absoluteDir());
    QStringList filtr;
    filtr << "*.jpg" << "*.png" << "*.bmp";
    qDebug() << dir.entryInfoList(filtr);
    QFileInfoList list = dir.entryInfoList(filtr);

    //  ListWidget loading directory path from imgaes folder
    for (int i = 0;i < list.count();i++) {
        QFileInfo f = list.at(i);
        QPixmap pix(f.filePath());
        int w = pix.width();
        int h = pix.height();
        double fSize =f.size() / 1024.;
        QString Info = QString::number(w) + "x" + QString::number(h) + ", " + QString::number(round(fSize * 10) / 10) + "KB";
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_2);
        imges *imgitem = new  imges;
        imgitem->setData(pix.scaledToWidth(90,Qt::SmoothTransformation),f.fileName(),Info, f.filePath());
        item->setSizeHint(imgitem->sizeHint());
        ui->listWidget_2->setItemWidget(item,imgitem);
}

}

void MainWindow::on_pushButton_2_pressed()
{

    // Open images using pressed the butoons to the image label
    QString imagePath = QFileDialog::getOpenFileName(

                this,

                tr("Open File"),

                "",

                tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )

                );
    imageObject = new QImage();

    imageObject->load(imagePath);

    image = QPixmap::fromImage(*imageObject);

    scene = new QGraphicsScene(this);

    scene->addPixmap(image);

    scene->setSceneRect(image.rect());
    ui->imagelabel->setPixmap(image);

    int w =ui->imagelabel->width();
    int h = ui->imagelabel->height();
    ui->imagelabel->setPixmap(image.scaled(w,h,Qt::KeepAspectRatio));
     //---------------------------------------------
}
void MainWindow::on_pushButton_clicked()
{


}

void MainWindow::on_pushButton_4_clicked()
{


}

void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
    // If list widget item click then load the image to the scroll area
    imges *imgitem = qobject_cast <imges *>(ui->listWidget->itemWidget(item));
    QPixmap pix(imgitem->getPath());
    imageLabel->setPixmap(pix);
    imageLabel->setFixedSize(pix.width(),pix.height());
}

void MainWindow::on_pushButton_4_pressed()
{

    // If selelcting the derectory from the listwidget then load the images  form  and load to the all images that user select to the list widget, leftside.
    QDir directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home",
        QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
        auto listWidget_images = new QListWidget(); // Set listwidget to display images
        listWidget_images->setMinimumSize(1200,400);
        listWidget_images->setViewMode(QListWidget::IconMode);
        listWidget_images->setIconSize(QSize(320,240));
        listWidget_images->setResizeMode(QListWidget::Adjust);
        for(const QFileInfo & finfo: directory.entryInfoList()){
        ui->listWidget->addItem(finfo.absoluteFilePath());
        }
        QString fileName = QFileDialog::getOpenFileName(this,
                           "Images", "",
                            "Downloads (*.bmp  *.jpg *.png)");
        QPixmap pix(fileName);
        imageLabel->setPixmap(pix);
        imageLabel->setFixedSize(pix.width(),pix.height());
        setImagesList(fileName);

// Support images file types to filter
        connect(ui->listWidget, & QListWidget::itemClicked,[listWidget_images,this](QListWidgetItem *item)
        {
            listWidget_images->show();
            listWidget_images->clear();
            QDir directory(item->text());
            directory.setNameFilters({"*.png", "*.jpg","*.bmp","*.TIFF","*.EPS","*.JFIF",});
            for(const QFileInfo & finfo: directory.entryInfoList()){
                QListWidgetItem *item = new QListWidgetItem(QIcon(finfo.absoluteFilePath()), finfo.fileName());
                listWidget_images->addItem(item);
            }
// Filter images from directory set
            directory.setFilter(QDir::Dirs |QDir::Files| QDir::NoDotAndDotDot);
             MyList = directory.entryList();
            ui->listWidget->addItems(MyList);

        });
}

void MainWindow::on_pushButton_5_clicked()
{
// What ever the user select direcory from list widget that can be deleted
    foreach (QListWidgetItem *item, ui->listWidget->selectedItems())
    delete item;
}

void MainWindow::on_pushButton_pressed()
{

}

void MainWindow::on_lineEdit_selectionChanged()
{

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
  /*  QListView *myview = new QListView(this);
    model *model = new model(this);
    QSortFilterProxyModel *proxy = new QSortFilterProxyModel(this);

    proxy->setSourceModel(model);
    myview->setModel(proxy);

    myview->setRootIndex(proxy->mapFromSource(model->index(model->rootPath()));

    connect(filterLineEdit, SIGNAL(textChanged(QString)),
            proxy,          SLOT(setFilterFixedString(QString)));*/

    // QString wildcard = QRegularExpression::wildcardToRegularExpression("*.jpeg");
   //  QRegularExpression  regularExpression (arg1, Qt::CaseInsensitive,  QRegularExpression::wildcardToRegularExpression());
   // QString wildcard = QRegularExpression::wildcardToRegularExpression("*.jpeg");
   // QRegularExpression  regularExpression (arg1, Qt::CaseInsensitive,  QRegularExpression::wildcard());
    // Will match files with names like:
    //   foo.jpeg
    //    f_o_o.jpeg
    //    föö.jpeg
   /* QRegularExpression regExp("*R*", Qt::CaseInsensitive, QRegularExpression::wildcardToRegularExpression());
    ui->listWidget->clear();
    ui->listWidget->addItems(MyList.filter(regexp));*/
    //  proxyModel.setFilterRegExp(regExp);

}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_3_pressed()
{
    QString imagePath = QFileDialog::getSaveFileName(

                    this,

                    tr("Save File"),

                    "",

                    tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )

                    );

    *imageObject = image.toImage();
    imageObject->save(imagePath);
}


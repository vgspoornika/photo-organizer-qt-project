#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QScrollArea>
#include <QMainWindow>
#include <QDialog>
#include <QDir>
#include <QDebug>
#include <QRegularExpression>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include <QLabel>
#include <QListWidgetItem>
#include "data.h"
//#include "filter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_pressed();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_4_pressed();

    void on_pushButton_5_clicked();

    void on_pushButton_pressed();

  //  void on_pushButton_clicked();
    void on_lineEdit_selectionChanged();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();


    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_3_pressed();

private:
    Ui::MainWindow *ui;

    QStringList MyList;

// Set images function which was loaded scrollarea
    QScrollArea *scrollArea;
    double scaleFactor = 1;
    QPixmap image;
    QImage  *imageObject;

   QGraphicsScene *scene;


   QLabel * imageLabel;
   void setImagesList(QString FileName);

   QStandardItemModel model;
  // Filter filter;

 void makeTestData();
    void loadTextFile();

};
#endif // MAINWINDOW_H

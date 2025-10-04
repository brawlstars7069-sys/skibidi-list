#include "popupwindow.h"
#include "ui_popupwindow.h"
#include "QPixmap"
#include <QUrl>
#include <QMediaPlayer>

PopupWindow::PopupWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PopupWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/ibaChotko.jpg");
    int w = ui->image->width();
    int h = ui->image->height();

    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    player = new QMediaPlayer(this);

    player->setVolume(100); // от 0 до 100

    player->setMedia(QUrl("qrc:/sounds/PIRIDAY.mp3"));

    player->play();

}

PopupWindow::~PopupWindow()
{
    delete ui;
}


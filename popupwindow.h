#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QMediaPlayer>

namespace Ui {
class PopupWindow;
}

class PopupWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PopupWindow(QWidget *parent = nullptr);
    ~PopupWindow();

private:
    Ui::PopupWindow *ui;

    QLabel *imageLabel;
    QMediaPlayer *player;
};

#endif // POPUPWINDOW_H

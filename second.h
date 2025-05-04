#ifndef SECOND_H
#define SECOND_H

#include <QMainWindow>

namespace Ui {
class second;
}

class second : public QMainWindow
{
    Q_OBJECT

public:
    explicit second(QWidget *parent = nullptr);
    ~second();

private slots:
    void on_gallery_btn_clicked();

    void on_start_btn_clicked();

private:
    Ui::second *ui;
};

#endif // SECOND_H

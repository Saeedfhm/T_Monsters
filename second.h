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

protected:
//    bool eventFilter(QObject *obj, QEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_gallery_btn_clicked();

    void on_start_btn_clicked();

private:
    Ui::second *ui;
};

#endif // SECOND_H

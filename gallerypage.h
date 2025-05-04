#ifndef GALLERYPAGE_H
#define GALLERYPAGE_H

#include <QMainWindow>

namespace Ui {
class gallerypage;
}

class gallerypage : public QMainWindow
{
    Q_OBJECT

public:
    explicit gallerypage(QWidget *parent = nullptr);
    ~gallerypage();

private slots:
    void on_back_btn_clicked();

private:
    Ui::gallerypage *ui;


};

#endif // GALLERYPAGE_H

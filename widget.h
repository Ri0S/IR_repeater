#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public slots:
    void on_GPIO_clicked(bool);
    void on_revPin_clicked(bool);
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    void checkEnable();
    void checkDisable();
    void radioEnable();
    void radioDisable();
};

#endif // WIDGET_H

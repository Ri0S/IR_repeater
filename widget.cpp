#include "widget.h"
#include "ui_widget.h"
#include "repeater.cpp"
#include <qcheckbox.h>
#include <qradiobutton.h>
//#include "repeater.cpp"

list<int>  writePinList;
int readPin;

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget){
    ui->setupUi(this);
    ///////////////////////////////////////////////////////////////////////////////////////////SEND Connect
    QObject::connect(ui->GPIO0, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO1, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO2, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO3, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO4, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO5, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO6, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO7, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO8, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO9, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO10, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO11, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO12, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO13, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO14, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO15, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO16, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO21, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO22, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO23, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO24, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO25, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO26, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO27, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO28, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO29, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO30, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO31, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    //////////////////////////////////////////////////////////////////////////////////////////READ connect
    QObject::connect(ui->REV_GPIO0, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO1, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO2, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO3, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO4, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO5, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO6, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO7, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO8, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO9, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO10, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO11, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO12, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO13, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO14, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO15, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO16, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO21, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO22, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO23, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO24, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO25, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO26, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO27, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO28, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO29, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO30, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
    QObject::connect(ui->REV_GPIO31, SIGNAL(clicked(bool)), this, SLOT(on_revPin_clicked(bool)));
}

void Widget::on_revPin_clicked(bool){
    QRadioButton* radioButton = dynamic_cast<QRadioButton*>(sender());
    readPin = radioButton->text().at(5).cell() - '0';
    if(radioButton->text().length() == 7){
        readPin *= 10;
        readPin += radioButton->text().at(6).cell() - '0';
    }
}
void Widget::checkEnable(){
    ui->GPIO0->setEnabled(true);
    ui->GPIO1->setEnabled(true);
    ui->GPIO2->setEnabled(true);
    ui->GPIO3->setEnabled(true);
    ui->GPIO4->setEnabled(true);
    ui->GPIO5->setEnabled(true);
    ui->GPIO6->setEnabled(true);
    ui->GPIO7->setEnabled(true);
    ui->GPIO8->setEnabled(true);
    ui->GPIO9->setEnabled(true);
    ui->GPIO10->setEnabled(true);
    ui->GPIO11->setEnabled(true);
    ui->GPIO12->setEnabled(true);
    ui->GPIO13->setEnabled(true);
    ui->GPIO14->setEnabled(true);
    ui->GPIO15->setEnabled(true);
    ui->GPIO16->setEnabled(true);
    ui->GPIO23->setEnabled(true);
    ui->GPIO24->setEnabled(true);
    ui->GPIO25->setEnabled(true);
    ui->GPIO26->setEnabled(true);
    ui->GPIO27->setEnabled(true);
    ui->GPIO28->setEnabled(true);
    ui->GPIO29->setEnabled(true);
    ui->GPIO31->setEnabled(true);
}
void Widget::checkDisable(){
    ui->GPIO0->setDisabled(true);
    ui->GPIO1->setDisabled(true);
    ui->GPIO2->setDisabled(true);
    ui->GPIO3->setDisabled(true);
    ui->GPIO4->setDisabled(true);
    ui->GPIO5->setDisabled(true);
    ui->GPIO6->setDisabled(true);
    ui->GPIO7->setDisabled(true);
    ui->GPIO8->setDisabled(true);
    ui->GPIO9->setDisabled(true);
    ui->GPIO10->setDisabled(true);
    ui->GPIO11->setDisabled(true);
    ui->GPIO12->setDisabled(true);
    ui->GPIO13->setDisabled(true);
    ui->GPIO14->setDisabled(true);
    ui->GPIO15->setDisabled(true);
    ui->GPIO16->setDisabled(true);
    ui->GPIO23->setDisabled(true);
    ui->GPIO24->setDisabled(true);
    ui->GPIO25->setDisabled(true);
    ui->GPIO26->setDisabled(true);
    ui->GPIO27->setDisabled(true);
    ui->GPIO28->setDisabled(true);
    ui->GPIO29->setDisabled(true);
    ui->GPIO31->setDisabled(true);
}
void Widget::radioEnable(){
    ui->REV_GPIO0->setEnabled(true);
    ui->REV_GPIO1->setEnabled(true);
    ui->REV_GPIO2->setEnabled(true);
    ui->REV_GPIO3->setEnabled(true);
    ui->REV_GPIO4->setEnabled(true);
    ui->REV_GPIO5->setEnabled(true);
    ui->REV_GPIO6->setEnabled(true);
    ui->REV_GPIO7->setEnabled(true);
    ui->REV_GPIO8->setEnabled(true);
    ui->REV_GPIO9->setEnabled(true);
    ui->REV_GPIO10->setEnabled(true);
    ui->REV_GPIO11->setEnabled(true);
    ui->REV_GPIO12->setEnabled(true);
    ui->REV_GPIO13->setEnabled(true);
    ui->REV_GPIO14->setEnabled(true);
    ui->REV_GPIO15->setEnabled(true);
    ui->REV_GPIO16->setEnabled(true);
    ui->REV_GPIO23->setEnabled(true);
    ui->REV_GPIO24->setEnabled(true);
    ui->REV_GPIO25->setEnabled(true);
    ui->REV_GPIO26->setEnabled(true);
    ui->REV_GPIO27->setEnabled(true);
    ui->REV_GPIO28->setEnabled(true);
    ui->REV_GPIO29->setEnabled(true);
    ui->REV_GPIO31->setEnabled(true);
}

void Widget::radioDisable(){
    ui->REV_GPIO0->setDisabled(true);
    ui->REV_GPIO1->setDisabled(true);
    ui->REV_GPIO2->setDisabled(true);
    ui->REV_GPIO3->setDisabled(true);
    ui->REV_GPIO4->setDisabled(true);
    ui->REV_GPIO5->setDisabled(true);
    ui->REV_GPIO6->setDisabled(true);
    ui->REV_GPIO7->setDisabled(true);
    ui->REV_GPIO8->setDisabled(true);
    ui->REV_GPIO9->setDisabled(true);
    ui->REV_GPIO10->setDisabled(true);
    ui->REV_GPIO11->setDisabled(true);
    ui->REV_GPIO12->setDisabled(true);
    ui->REV_GPIO13->setDisabled(true);
    ui->REV_GPIO14->setDisabled(true);
    ui->REV_GPIO15->setDisabled(true);
    ui->REV_GPIO16->setDisabled(true);
    ui->REV_GPIO23->setDisabled(true);
    ui->REV_GPIO24->setDisabled(true);
    ui->REV_GPIO25->setDisabled(true);
    ui->REV_GPIO26->setDisabled(true);
    ui->REV_GPIO27->setDisabled(true);
    ui->REV_GPIO28->setDisabled(true);
    ui->REV_GPIO29->setDisabled(true);
    ui->REV_GPIO31->setDisabled(true);
}

void Widget::on_GPIO_clicked(bool){
    checkDisable();
    QCheckBox* checkBox = dynamic_cast<QCheckBox*>(sender());
    int pinNum = checkBox->text().at(5).cell() - '0';
    if(checkBox->text().length() == 7){
        pinNum *= 10;
        pinNum += checkBox->text().at(6).cell() - '0';
    }
    if(checkBox->isChecked())
        writePinList.push_back(pinNum);
    else
        writePinList.remove(pinNum);
    checkEnable();
}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked(){
    checkDisable();
    radioDisable();
    quit = 1;
    //repeater(readPin, writePinList);
}

void Widget::on_pushButton_2_clicked(){
    quit = 0;
    checkEnable();
    radioEnable();
}

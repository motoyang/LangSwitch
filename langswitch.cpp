#include "langswitch.h"
#include "ui_langswitch.h"

LangSwitch::LangSwitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LangSwitch)
{
    ui->setupUi(this);
}

LangSwitch::~LangSwitch()
{
    delete ui;
}

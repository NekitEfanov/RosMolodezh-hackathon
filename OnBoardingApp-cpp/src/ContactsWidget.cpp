#include "ContactsWidget.hpp"

ContactsWidget::ContactsWidget(QWidget* parent) : BaseWidget(parent) {
    QGridLayout* layout = new QGridLayout(this);
    auto label = new QLabel;
    label->setText("ContactsWidget");
    layout->addWidget(label);
    //test
}


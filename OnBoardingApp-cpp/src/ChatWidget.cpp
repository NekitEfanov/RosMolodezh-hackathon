#include "ChatWidget.hpp"

ChatWidget::ChatWidget(QWidget* parent) : BaseWidget(parent) {
    QGridLayout* layout = new QGridLayout(this);
    auto label = new QLabel;
    label->setText("ChatWidget");
    layout->addWidget(label);
    //test
}

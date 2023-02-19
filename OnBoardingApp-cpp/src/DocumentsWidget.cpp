#include "DocumentsWidget.hpp"

DocumentsWidget::DocumentsWidget(QWidget* parent) : BaseWidget(parent) {
    QGridLayout* layout = new QGridLayout(this);
    auto label = new QLabel;
    label->setText("DocumentsWidget");
    layout->addWidget(label);
    //test
}


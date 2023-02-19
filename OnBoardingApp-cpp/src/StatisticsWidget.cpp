#include "StatisticsWidget.hpp"

StatisticsWidget::StatisticsWidget(QWidget* parent) : BaseWidget(parent) {
    QGridLayout* layout = new QGridLayout(this);
    auto label = new QLabel;
    label->setText("StatisticsWidget");
    layout->addWidget(label);
    //test
}


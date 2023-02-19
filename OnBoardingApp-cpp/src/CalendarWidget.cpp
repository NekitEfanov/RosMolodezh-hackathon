#include "CalendarWidget.hpp"

CalendarWidget::CalendarWidget(QWidget* parent) : BaseWidget(parent) {
    QGridLayout* layout = new QGridLayout(this);
    auto label = new QLabel;
    label->setText("CalendarWidget");
    layout->addWidget(label);
    //test
}
 

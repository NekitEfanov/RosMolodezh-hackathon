#pragma once

#include "BaseWidget.hpp"
#include "CalendarWidget.hpp"
#include "ContactsWidget.hpp"
#include "StatisticsWidget.hpp"

#include <QMainWindow>

#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <utility>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
public:
    MainWindow();

private:
    std::map<std::string, std::shared_ptr<BaseWidget>> m_widgets;
};
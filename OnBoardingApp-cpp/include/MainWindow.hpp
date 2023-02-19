#pragma once

#include "BaseWidget.hpp"
#include "CalendarWidget.hpp"
#include "ChatWidget.hpp"
#include "ContactsWidget.hpp"
#include "DocumentsWidget.hpp"
#include "StatisticsWidget.hpp"

#include <QHBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QResizeEvent>
#include <QThread>
#include <QVBoxLayout>

#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <utility>

#ifdef WIN32
constexpr int min_window_size_x = 360;
constexpr int min_window_size_y = 640;
#endif

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public BaseWidget {
public:
    MainWindow();

private:
    void create_buttons();
    void add_buttons();

    std::map<std::string, BaseWidget*> m_widgets;
    std::map<std::string, QPushButton*> m_buttons;

    BaseWidget* m_active_widget{nullptr};
    QPushButton* m_active_button{nullptr};

    QVBoxLayout* m_main_layout;
    QVBoxLayout* m_widgets_layout;
    QHBoxLayout* m_buttons_layout;

    std::shared_ptr<QWidget> m_widget_v_l;
    std::shared_ptr<QWidget> m_widget_h_l;

    bool m_is_menu_widgets_shown{false};

    void swap_widgets(const std::string& name);

private slots:
    void show_hide_menu_widgets();

    void show_statisctics();
    void show_documents();
    void show_calendar();
    void show_contacts();
    void show_chat();
};
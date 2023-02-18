#include "MainWindow.hpp"

MainWindow::MainWindow() {
    m_widgets["Calendar"].reset(new CalendarWidget);
    m_widgets["Contacts"].reset(new ContactsWidget);
    m_widgets["Statisctics"].reset(new StatiscticsWidget);
}

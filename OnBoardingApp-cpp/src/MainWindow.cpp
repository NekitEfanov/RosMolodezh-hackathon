#include "MainWindow.hpp"

MainWindow::MainWindow() {
    this->setMinimumSize({min_window_size_x, min_window_size_y});

    m_widgets["Calendar"] = new CalendarWidget;
    m_widgets["Contacts"] = new ContactsWidget;
    m_widgets["Statisctics"] = new StatiscticsWidget;
    m_widgets["DocumentsWidget"] = new DocumentsWidget;
    m_widgets["ChatWidget"] = new ChatWidget;

    create_buttons();

    m_main_layout = new QVBoxLayout(this);

    m_widget_v_l.reset(new QWidget);
    m_widget_h_l.reset(new QWidget);

    m_main_layout->addWidget(m_widget_v_l.get());
    m_main_layout->addWidget(m_widget_h_l.get());

    m_widget_v_l->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_widgets_layout = new QVBoxLayout(m_widget_v_l.get());
    m_buttons_layout = new QHBoxLayout(m_widget_h_l.get());

    add_buttons();

    connect(m_buttons["OpenMenu"], &QPushButton::pressed, this,
            &MainWindow::show_hide_menu_widgets);
}

void MainWindow::create_buttons() {
    m_buttons["OpenStatisctics"] = new QPushButton();
    m_buttons["OpenDocuments"] = new QPushButton();
    m_buttons["OpenCalendar"] = new QPushButton();
    m_buttons["OpenContacts"] = new QPushButton();
    m_buttons["OpenChat"] = new QPushButton();
    m_buttons["OpenMenu"] = new QPushButton();

    std::for_each(m_buttons.begin(), m_buttons.end(),
                  [this](std::pair<std::string, QPushButton*> pair_widget) {
                      pair_widget.second->setFixedSize({50, 50});
                  });

    m_buttons["OpenStatisctics"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/MenuButton.png) "
        "stretch; ");
    m_buttons["OpenDocuments"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/MenuButton.png) "
        "stretch; ");
    m_buttons["OpenCalendar"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/MenuButton.png) "
        "stretch; ");
    m_buttons["OpenContacts"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/MenuButton.png) "
        "stretch; ");
    m_buttons["OpenChat"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/MenuButton.png) "
        "stretch; ");
    m_buttons["OpenMenu"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/MenuButton.png) "
        "stretch; ");
}

void MainWindow::add_buttons() {
    m_buttons_layout->addWidget(m_buttons["OpenStatisctics"], Qt::AlignBottom,
                                Qt::AlignRight);
    m_buttons_layout->addWidget(m_buttons["OpenDocuments"], Qt::AlignBottom,
                                Qt::AlignRight);
    m_buttons_layout->addWidget(m_buttons["OpenCalendar"], Qt::AlignBottom,
                                Qt::AlignRight);
    m_buttons_layout->addWidget(m_buttons["OpenContacts"], Qt::AlignBottom,
                                Qt::AlignRight);
    m_buttons_layout->addWidget(m_buttons["OpenChat"], Qt::AlignBottom,
                                Qt::AlignRight);
    m_buttons_layout->addWidget(m_buttons["OpenMenu"], Qt::AlignBottom, 
                                Qt::AlignRight);
}

void MainWindow::show_hide_menu_widgets() {
    std::for_each(m_buttons.begin(), m_buttons.end(),
                  [this](std::pair<std::string, QPushButton*> pair_widget) {
                      if (pair_widget.first != "OpenMenu") {
                          if (m_is_menu_widgets_shown)
                              pair_widget.second->hide();
                          else
                              pair_widget.second->show();
                      }
                  });

    m_is_menu_widgets_shown = m_is_menu_widgets_shown ? false : true;
}
#include "MainWindow.hpp"

MainWindow::MainWindow() {
    this->setMinimumSize({min_window_size_x, min_window_size_y});

    m_widgets["Calendar"] = new CalendarWidget(this);
    m_widgets["Contacts"] = new ContactsWidget(this);
    m_widgets["Statistics"] = new StatisticsWidget(this);
    m_widgets["Documents"] = new DocumentsWidget(this);
    m_widgets["Chat"] = new ChatWidget(this);

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

    connect(m_buttons["OpenStatistics"], &QPushButton::pressed, this,
            &MainWindow::show_statisctics);

    connect(m_buttons["OpenDocuments"], &QPushButton::pressed, this,
            &MainWindow::show_documents);

    connect(m_buttons["OpenCalendar"], &QPushButton::pressed, this,
            &MainWindow::show_calendar);

    connect(m_buttons["OpenContacts"], &QPushButton::pressed, this,
            &MainWindow::show_contacts);

    connect(m_buttons["OpenChat"], &QPushButton::pressed, this,
            &MainWindow::show_chat);

    connect(m_buttons["OpenMenu"], &QPushButton::pressed, this,
            &MainWindow::show_hide_menu_widgets);
}

void MainWindow::create_buttons() {
    m_buttons["OpenStatistics"] = new QPushButton();
    m_buttons["OpenDocuments"] = new QPushButton();
    m_buttons["OpenCalendar"] = new QPushButton();
    m_buttons["OpenContacts"] = new QPushButton();
    m_buttons["OpenChat"] = new QPushButton();
    m_buttons["OpenMenu"] = new QPushButton();

    std::for_each(m_buttons.begin(), m_buttons.end(),
                  [](std::pair<std::string, QPushButton*> pair_button) {
                      pair_button.second->setFixedSize({50, 50});
                      if (pair_button.first != "OpenMenu")
                          pair_button.second->hide();
                  });

    std::for_each(m_widgets.begin(), m_widgets.end(),
                  [](std::pair<std::string, BaseWidget*> pair_widget) {
                      pair_widget.second->hide();
                  });

    m_buttons["OpenStatistics"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/StatisticsButton.png) "
        "stretch; ");
    m_buttons["OpenDocuments"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/DocumentsButton.png) "
        "stretch; ");
    m_buttons["OpenCalendar"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/CalendarButton.png) "
        "stretch; ");
    m_buttons["OpenContacts"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/ContactsButton.png) "
        "stretch; ");
    m_buttons["OpenChat"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/ChatButton.png) "
        "stretch; ");
    m_buttons["OpenMenu"]->setStyleSheet(
        "border-image: url(:/image/resources/MenuWidget/MenuButton.png) "
        "stretch; ");
}

void MainWindow::add_buttons() {
    m_buttons_layout->addWidget(m_buttons["OpenStatistics"], Qt::AlignBottom,
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

void MainWindow::swap_widgets(const std::string& name) {
    if (m_active_widget == m_widgets[name])
        return;

    m_widgets_layout->replaceWidget(m_active_widget, m_widgets[name]);
    if (m_active_widget != nullptr) {
        m_active_widget->hide();
    }

    m_active_widget = m_widgets[name];
    m_active_widget->show();

    std::string style_sheet =
        ("border-image: url(:/image/resources/MenuWidget/" + name +
         "ButtonActive.png) "
         "stretch; ");

    m_buttons["Open" + name]->setStyleSheet(style_sheet.c_str());

    if (m_active_button != nullptr)
        for (auto it = m_buttons.begin(); it != m_buttons.end(); it++) {
            if (it->second == m_active_button) {
                std::string style_sheet =
                    ("border-image: url(:/image/resources/MenuWidget/" +
                     std::string(it->first.begin() + 4, it->first.end()) +
                     "Button.png) "
                     "stretch; ");

                m_buttons[it->first]->setStyleSheet(style_sheet.c_str());
            }
        }
}

void MainWindow::show_statisctics() {
    swap_widgets("Statistics");
    m_active_button = m_buttons["OpenStatistics"];
}

void MainWindow::show_documents() {
    swap_widgets("Documents");
    m_active_button = m_buttons["OpenDocuments"];
}

void MainWindow::show_calendar() {
    swap_widgets("Calendar");
    m_active_button = m_buttons["OpenCalendar"];
}

void MainWindow::show_contacts() {
    swap_widgets("Contacts");
    m_active_button = m_buttons["OpenContacts"];
}

void MainWindow::show_chat() {
    swap_widgets("Chat");
    m_active_button = m_buttons["OpenChat"];
}

void MainWindow::show_hide_menu_widgets() {
    std::for_each(m_buttons.begin(), m_buttons.end(),
                  [this](std::pair<std::string, QPushButton*> pair_button) {
                      if (pair_button.first != "OpenMenu") {
                          if (m_is_menu_widgets_shown)
                              pair_button.second->hide();
                          else
                              pair_button.second->show();
                      }
                  });

    if (!m_is_menu_widgets_shown) {
        std::string style_sheet =
            ("border-image: "
             "url(:/image/resources/MenuWidget/MenuButtonActive.png) "
             "stretch; ");
        m_buttons["OpenMenu"]->setStyleSheet(style_sheet.c_str());


        if (m_active_widget == nullptr)
            show_statisctics();
        else
            m_active_widget->show();
    } else {
        std::string style_sheet =
            ("border-image: "
             "url(:/image/resources/MenuWidget/MenuButton.png) "
             "stretch; ");
        m_buttons["OpenMenu"]->setStyleSheet(style_sheet.c_str());

        if (m_active_widget != nullptr)
            m_active_widget->hide();
    }

    m_is_menu_widgets_shown = m_is_menu_widgets_shown ? false : true;
}
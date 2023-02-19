#pragma once

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <qDebug>

#include <string>

class BaseWidget : public QWidget {
public:
    explicit BaseWidget(QWidget* parent = nullptr);

protected:
    template <class Widget>
    void show_all(Widget* widget) {
        widget->show();
    }

    template <class Widget, class... Widgets>
    void show_all(Widget* widget, Widgets... widgets) {
        widget->show();
        show_all(widgets);
    }

    template <class Widget>
    void hide_all(Widget* widget) {
        widget->hide();
    }

    template <class Widget, class... Widgets>
    void hide_all(Widget* widget, Widgets... widgets) {
        widget->hide();
        hide_all(widgets);
    }
};
#include <iostream>
#include <gtkmm/settings.h>

#include "projectdefinitions.h"
#include "window.h"

Window::Window(Gtk::ApplicationWindow::BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder)
        : Gtk::ApplicationWindow(cobject),
          builder(builder),
          settings(nullptr),
          headerBar(nullptr) {
    settings = Gio::Settings::create(projectdefinitions::getApplicationID());

    std::string fileName = projectdefinitions::getApplicationPrefix() + "icons/48x48/icon.png";

    // Create a Gtk::IconTheme object
    auto theme = Gtk::IconTheme::get_for_display(get_display());

    // Load the icon from the theme
    auto icon = theme->lookup_icon(fileName, 48);

    if (icon != nullptr) {
        set_icon_name(icon->get_icon_name());
    }
    setHeaderBar();
}

Window::~Window() {}

Window *Window::create() {
    auto builder = Gtk::Builder::create_from_resource(projectdefinitions::getApplicationPrefix() + "ui/window.xml");

    auto window = Gtk::Builder::get_widget_derived<Window>(builder, "window");
    if (!window) {
        throw std::runtime_error("No \"window\" object in window.xml");
    }
    return window;
}

void Window::setHeaderBar() {
    auto builder =
            Gtk::Builder::create_from_resource(projectdefinitions::getApplicationPrefix() + "ui/headerbar.xml");
    headerBar = builder->get_widget<Gtk::HeaderBar>("headerBar");
    if (!headerBar) {
        throw std::runtime_error("No \"headerBar\" object in headerbar.xml");
    } else {
        set_titlebar(*headerBar);
    }
}

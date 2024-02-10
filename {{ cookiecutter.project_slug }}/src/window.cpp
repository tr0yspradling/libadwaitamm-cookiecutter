#include <iostream>
#include <gtkmm/settings.h>

#include "projectdefinitions.h"
#include "window.h"

Window::Window(Gtk::ApplicationWindow::BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder)
        : Gtk::ApplicationWindow(cobject),
          builder(builder) {
    std::cout << "creating gsettings.\n";
    // settings = Gio::Settings::create(projectdefinitions::getApplicationID());

    std::string fileName = projectdefinitions::getApplicationPrefix() + "icons/48x48/icon.png";

    // Create a Gtk::IconTheme object
    auto theme = Gtk::IconTheme::get_for_display(get_display());

    // Load the icon from the theme
    auto icon = theme->lookup_icon(fileName, 48);

    if (icon != nullptr) {
        set_icon_name(icon->get_icon_name());
    }
    set_header_bar();
}

Window::~Window() = default;

Window *Window::create() {
    const auto builder = Gtk::Builder::create_from_resource(projectdefinitions::getApplicationPrefix() + "ui/window.xml");

    const auto window = Gtk::Builder::get_widget_derived<Window>(builder, "window");
    if (!window) {
        throw std::runtime_error("No \"window\" object in window.xml");
    }
    return window;
}

void Window::set_header_bar() {
    const auto builder =
            Gtk::Builder::create_from_resource(projectdefinitions::getApplicationPrefix() + "ui/headerbar.xml");
    header_bar = Glib::RefPtr<Gtk::HeaderBar>(builder->get_widget<Gtk::HeaderBar>("headerBar"));
    if (header_bar) {
        set_titlebar(*header_bar);
    } else {
        throw std::runtime_error("No \"headerBar\" object in headerbar.xml");
    }
}

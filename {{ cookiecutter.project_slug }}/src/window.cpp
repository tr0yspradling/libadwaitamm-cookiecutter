#include <iostream>
#include <gtkmm/settings.h>

#include "projectdefinitions.h"
#include "window.h"

// Window::Window(GtkWidget* cobject)
// : TemplateWidget<Window, Adw::ApplicationWindow>(cobject) {
//     std::cout << "creating gsettings.\n";
//     // settings = Gio::Settings::create(projectdefinitions::getApplicationID());
//
//     std::string fileName = projectdefinitions::getApplicationPrefix() + "icons/48x48/icon.png";
//
//     // Create a Gtk::IconTheme object
//     auto theme = Gtk::IconTheme::get_for_display(get_display());
//
//     // Load the icon from the theme
//     auto icon = theme->lookup_icon(fileName, 48);
//
//     if (icon != nullptr) {
//         set_icon_name(icon->get_icon_name());
//     }
//     set_header_bar();
// }

const char Window::class_name[] = "Window";

Window* Window::create(const Glib::RefPtr<Adw::Application>& application) {
    Glib::ConstructParams params(type_class_.init(), "application",
                                 Glib::unwrap(application), nullptr);
    GObject* obj = g_object_new_with_properties(
        Window::get_type(), params.n_parameters, params.parameter_names,
        params.parameter_values);
    return Window::wrap(obj);
}

// Glib::RefPtr<Window> Window::create(const Glib::RefPtr<Adw::Application>& application) {
//     const Glib::ConstructParams params(type_class_.init(), "application",
//                                  Glib::unwrap(application), nullptr);
//     GObject *obj = g_object_new_with_properties(
//         get_type(), params.n_parameters, params.parameter_names,
//         params.parameter_values);
//
//     return Glib::make_refptr_for_instance(wrap(obj));
// }


// void Window::set_header_bar() {
//     const auto builder =
//             Gtk::Builder::create_from_resource(projectdefinitions::getApplicationPrefix() + "ui/headerbar.xml");
//     header_bar = Glib::RefPtr<Gtk::HeaderBar>(builder->get_widget<Gtk::HeaderBar>("headerBar"));
//     if (header_bar) {
//         this->set_header_bar();
//     } else {
//         throw std::runtime_error("No \"headerBar\" object in headerbar.xml");
//     }
// }


void Window::setup_template(Gtk::TemplateWidgetSetup& s) {
    s.set_resource("ui/window.xml");
}


void Window::init_widget(Gtk::TemplateWidgetInit& i) {
    i.init_template();

    // i.bind_widget(color_scheme_button, "color_scheme_button");

    auto manager = Adw::StyleManager::get_default();
    manager->property_system_supports_color_schemes()
        .signal_changed()
        .connect(sigc::mem_fun(*this, &Window::notify_system_supports_color_schemes_cb));
}


void Window::toast_undo_cb() { /* toasts_page->undo(); */ }


char* Window::get_color_scheme_icon_name(gboolean dark) {
    return g_strdup(dark ? "light-mode-symbolic" : "dark-mode-symbolic");
}


void Window::color_scheme_button_clicked_cb() {
    auto manager = Adw::StyleManager::get_default();

    if (manager->get_dark()) {
        manager->set_color_scheme(Adw::ColorScheme::FORCE_LIGHT);
    } else {
        manager->set_color_scheme(Adw::ColorScheme::FORCE_DARK);
    }
}


void Window::notify_system_supports_color_schemes_cb() {
    auto manager = Adw::StyleManager::get_default();
    bool supports = manager->get_system_supports_color_schemes();

    color_scheme_button->set_visible(!supports);

    if (supports) {
        manager->set_color_scheme(Adw::ColorScheme::DEFAULT);
    }
}

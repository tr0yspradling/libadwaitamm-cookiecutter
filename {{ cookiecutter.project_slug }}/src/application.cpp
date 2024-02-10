#include <iostream>
#include <memory>
#include "application.h"

Application::Application()
: Adw::Application(projectdefinitions::getApplicationID() + ".application", Gio::Application::Flags::NON_UNIQUE) {}

Glib::RefPtr<Application> Application::create() {
    return Glib::make_refptr_for_instance<Application>(new Application());
}


void Application::on_activate() {
    Adw::Application::on_activate();

    try {
        auto window = Window::create(Glib::make_refptr_for_instance(this));
        add_window(*window);
        window->signal_hide().connect(sigc::bind(sigc::mem_fun(*this, &Application::on_hide_window), window));
        window->present();
    } catch (const Glib::Error &ex) {
        std::cerr << "Application::on_activate(): " << ex.what() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Application::on_activate(): " << ex.what() << std::endl;
    }
}

void Application::on_startup() {
    Adw::Application::on_startup();

    // add_action("preferences", sigc::mem_fun(*this, &Application::on_action_preferences));
    // add_action("quit", sigc::mem_fun(*this, &Application::on_action_quit));
    // set_accel_for_action("app.quit", "<Ctrl>Q");

    // auto builder = Gtk::Builder::create();
    // try {
    //     builder->add_from_resource(projectdefinitions::getApplicationPrefix() + "ui/menu.xml");
    // } catch (const Glib::Error &ex) {
    //     std::cerr << "Application::on_startup(): " << ex.what() << std::endl;
    //     return;
    // }
    // auto app_menu = builder->get_object<Gio::Menu>("appmenu");
    // if (!app_menu) {
    //     std::cerr << "Application::on_startup(): No \"appmenu\" object in menu.xml" << std::endl;
    //     return;
    // }

    // set_menubar(app_menu);
}

void Application::on_hide_window(Gtk::Window *window) {
    // delete window;
}

void Application::on_action_preferences() {
    try {
        const auto prefsDialog = PreferencesWindow::create();
        prefsDialog->present();
        // prefsDialog->signal_hide().connect(sigc::bind(sigc::mem_fun(*this, &Application::on_hide_window), prefsDialog));
    } catch (const Glib::Error &ex) {
        std::cerr << "Application::on_action_preferences(): " << ex.what() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Application::on_action_preferences(): " << ex.what() << std::endl;
    }
}

void Application::on_action_quit() {
    auto windows = get_windows();
    for (auto window : windows) {
        window->hide();
    }
    quit();
}

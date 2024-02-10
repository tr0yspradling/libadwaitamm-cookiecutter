#ifndef APPLICATION_H
#define APPLICATION_H

#include <libadwaitamm/application.h>
#include <libadwaitamm/init.h>
#include "preferences.h"
#include "projectdefinitions.h"
#include "window.h"

class Application : public Adw::Application {
public:
    static Glib::RefPtr<Application> create();

    ~Application() override = default;

private:
    Application();

    Glib::RefPtr<Window> create_window();

    void on_activate() override;

    void on_startup() override;

    void on_hide_window(Gtk::Window* window);

    void on_action_preferences();

    void on_action_quit();
};

#endif  // APPLICATION_H

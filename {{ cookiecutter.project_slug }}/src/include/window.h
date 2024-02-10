#ifndef WINDOW_H
#define WINDOW_H

#include <giomm/settings.h>
#include <gtkmm/builder.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/icontheme.h>
#include <gtkmm/label.h>
#include <gtkmm/widget.h>
// #include <libadwaitamm.h>
#include <libadwaitamm/application.h>
#include <libadwaitamm/applicationwindow.h>
#include <libadwaitamm/private/applicationwindow_p.h>
#include <libadwaitamm/stylemanager.h>

#include "templatewidget.h"

class Window final : public Gtk::TemplateWidget<Window, Adw::ApplicationWindow> {
public:
    // static Glib::RefPtr<Window> create(const Glib::RefPtr<Adw::Application> &application);
    static Window* create(const Glib::RefPtr<Adw::Application>& application);
protected:
    explicit Window(GtkWidget* cobject) : TemplateWidgetBase(cobject) {}

private:
    static const char class_name[];
    static void setup_template(Gtk::TemplateWidgetSetup& s);
    void init_widget(Gtk::TemplateWidgetInit& i);

    Glib::RefPtr<Gtk::Builder> builder {nullptr};
    Glib::RefPtr<Gio::Settings> settings {nullptr};
    Gtk::Widget* color_scheme_button {nullptr};
    Glib::RefPtr<Gtk::HeaderBar> header_bar {nullptr};

//    void set_header_bar();

    void color_scheme_button_clicked_cb();
    void notify_visible_child_cb();
    void back_clicked_cb();
    void leaflet_back_clicked_cb();
    void leaflet_next_page_cb();
    void toast_undo_cb();
    void notify_system_supports_color_schemes_cb();
    char* get_color_scheme_icon_name(gboolean dark);

    static bool is_managed() { return false; }
    friend CppClassType;
};

#endif  // WINDOW_H

#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <giomm/settings.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/dialog.h>
#include <libadwaitamm.h>
#include <libadwaitamm/private/preferenceswindow_p.h>
#include "templatewidget.h"


class PreferencesWindow final : public Gtk::TemplateWidget<PreferencesWindow, Adw::PreferencesWindow> {

public:
    static PreferencesWindow* create();


protected:
    explicit PreferencesWindow(GtkWidget* cobject) : TemplateWidgetBase(cobject) {}


private:
    static const char class_name[];
    static void setup_template(Gtk::TemplateWidgetSetup& s);
    void init_widget(Gtk::TemplateWidgetInit& i);

    Glib::RefPtr<Gio::Settings> settings;

    static bool is_managed() { return false; }
    friend CppClassType;
};

#endif  // PREFERENCES_H

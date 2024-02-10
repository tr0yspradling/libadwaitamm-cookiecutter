#include "preferences.h"
#include "projectdefinitions.h"

const char PreferencesWindow::class_name[] =
    "PreferencesWindow";

void PreferencesWindow::setup_template(Gtk::TemplateWidgetSetup &s) {
	s.set_resource("ui/preferences.xml");
}

PreferencesWindow* PreferencesWindow::create() {
  GObject *obj = g_object_new_with_properties(get_type(),
                                              0, nullptr, nullptr);
  return wrap(obj);
}

void PreferencesWindow::init_widget(Gtk::TemplateWidgetInit &i) {
  i.init_template();

  // s.bind_widget("subpage2");
  //
  // s.bind_callback(
  //     "subpage1_activated_cb",
  //     Gtk::ptr_fun_to_mem_fun<&DemoPreferencesWindow::subpage1_activated>());

}
#include "preferences.h"
#include "projectdefinitions.h"

Preferences::Preferences(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder)
        : Gtk::Dialog(cobject), builder(builder), settings(nullptr) {
    settings = Gio::Settings::create(projectdefinitions::getApplicationID());
}

Preferences::~Preferences() { delete builder; delete settings; }

Preferences *Preferences::create(Gtk::Window &parent) {
    auto builder = Gtk::Builder::create_from_resource(
            projectdefinitions::getApplicationPrefix() + "ui/preferences.xml");

    auto prefsDialog = builder->get_widget<Preferences>("prefsDialog");
    if (!prefsDialog) {
        throw std::runtime_error("No \"prefsDialog\" object in preferences.xml");
    }

    prefsDialog->set_transient_for(parent);
    return prefsDialog;
}

# {{ cookiecutter.project_name }}

## Requirements
* [Cookiecutter](https://github.com/cookiecutter/cookiecutter)
* gtkmm-4.0
* CMake-3.2 or higher
* [Cambalache](https://gitlab.gnome.org/jpu/cambalache) (optional)

## Getting started
1. Install [Cookiecutter](https://github.com/cookiecutter/cookiecutter) on your system, if you haven't already done so. You can do this by running the following command in your terminal:
```bash
pip install cookiecutter
```

2. Generate a new project using the Cookiecutter template:
```bash
cookiecutter gh:tr0yspradling/gtkmm-cookiecutter
```
...and choose your application-ID e.g. "org.gtkmm.MyApplication".

3. Write your code.

4. Build the project:
```bash
mkdir build
cd build/
cmake ..
make
```
5. Installation:
```bash
sudo make install
```

6. If you want to uninstall your application run the shellscript in the build-directory:
```bash
sudo ./uninstall.sh
```

## References
Most parts used in the source code are copied from the GNOME Developer Guide [Programming with gtkmm4](https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/ "Programming with gtkmm4"), especially chapter [Building applications](https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/chapter-building-applications.html "Building applications").

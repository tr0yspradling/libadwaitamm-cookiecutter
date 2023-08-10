# libadwaitamm-cookiecutter

Simple cookiecutter template for a gtkmm + libadwaitamm application with C++17, CMake, & Cambalache.

## Requirements
* CMake-3.2 or higher
* [cookiecutter](https://github.com/cookiecutter/cookiecutter)
* [gtkmm4](https://gtkmm.org/en/index.html)
* [libadwaitamm](https://github.com/rofirrim/libadwaitamm/)
* [Cambalache](https://gitlab.gnome.org/jpu/cambalache) (optional)

## Getting started
1. Install [cookiecutter](https://github.com/cookiecutter/cookiecutter) on your system, if you haven't already done so. You can do this by running the following command in your terminal:
```bash
pip install cookiecutter
```

2. Generate a new project using the cookiecutter template:
```bash
cookiecutter git@github.com:tr0yspradling/libadwaitamm-cookiecutter
```

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

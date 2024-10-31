# nibbler

## How to build and run the program

**Build and install:**
`meson setup build --prefix=$PWD --bindir='' --libdir=''`
`ninja -C build install`

**Launch:**
`./nibbler <width> <height>` or `make run`

**If you don't have the necessary dependencies, install them with:**
`mkdir subprojects`
`meson wrap install <lib>`
The SFML package is momentarily non-functional so you'll need to use Suprapack to install it.
You can find the list of the available packages on: https://mesonbuild.com/Wrapdb-projects.html

**Rebuild:**
To avoid using the Makefile to rebuild the source and lib files, you can use the `ninja -C build` command.
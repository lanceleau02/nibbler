# nibbler

## How to build and run the program

**Build and install:**
- `meson setup build --prefix=$PWD --bindir='' --libdir=''`
- `ninja -C build install`

**Launch:**

`./nibbler <width> <height>` or `make run`

**Rebuild:**

To avoid using the Makefile to rebuild the source and lib files, you can use the `ninja -C build install` command.

**Build and run the docker:**

- `docker build -t nibbler .`
- `docker run --net=host --env="DISPLAY" -v /tmp/.X11-unix:/tmp/.X11-unix:rw --device /dev/snd -it nibbler`

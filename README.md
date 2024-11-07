# nibbler

## How to build and run the program

**Build and install:**

- `make setup`
- `make`

**Launch:**

`./nibbler <width> <height>` or `make run`

**Rebuild:**

`make re`

**Build and run the docker:**

- `docker build -t nibbler .`
- `xhost +local:docker`
- `docker run --net=host --env="DISPLAY" -v /tmp/.X11-unix:/tmp/.X11-unix:rw --device /dev/snd -it nibbler`

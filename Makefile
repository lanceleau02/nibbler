all:
	@ninja -C build install

setup:
	@meson setup build --prefix=$(PWD) --bindir='' --libdir=''

clean:
	@rm -rf nibbler libraylib.so libsdl2.so libsfml.so
	@rm -rf build

fclean: clean
	@rm -rf nibbler

re:
	@$(MAKE) fclean
	@$(MAKE) setup
	@$(MAKE) all

run:
	@./nibbler 10 10

docker-build:
	@docker build -t nibbler .

docker-run:
	@xhost +local:docker
	@docker run --net=host --env="DISPLAY" -v /tmp/.X11-unix:/tmp/.X11-unix:rw --device /dev/snd -it nibbler

docker-clean:
	@docker system prune -af

docker-re:
	@$(MAKE) docker-clean
	@$(MAKE) docker-build

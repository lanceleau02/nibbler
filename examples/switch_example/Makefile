CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror
RAYLIB_LDFLAGS	=	-L ../libs/Raylib/lib -lraylib -lglfw -lGL -lm -lpthread -lrt -lX11 -ldl
RAYLIB_INCLUDE	=	-I ../libs/Raylib/include
SDL_LDFLAGS		=	-L ../libs/SDL/ -lSDL2 -ldl
SDL_INCLUDE		=	-I ../libs/SDL/include/
SFML_LDFLAGS	=	-L ../libs/SFML/lib  -lsfml-graphics -lsfml-window -lsfml-system -ldl
SFML_INCLUDE	=	-I ../libs/SFML/include
BINS			=	raylib_wrapper.so sdl_wrapper.so sfml_wrapper.so main.elf

all: $(BINS)

%.so: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(RAYLIB_LDFLAGS) $(SDL_LDFLAGS) $(SFML_LDFLAGS) $(RAYLIB_INCLUDE) $(SDL_INCLUDE) $(SFML_INCLUDE)

%.elf: %.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(RAYLIB_LDFLAGS) $(SDL_LDFLAGS) $(SFML_LDFLAGS) $(RAYLIB_INCLUDE) $(SDL_INCLUDE) $(SFML_INCLUDE)

clean:
	rm -f $(BINS) *.o

re:
	$(MAKE) clean
	$(MAKE) all

run:
	export LD_LIBRARY_PATH=../libs/Raylib/lib/:$$LD_LIBRARY_PATH && export LD_LIBRARY_PATH=../libs/SDL/:$$LD_LIBRARY_PATH && export LD_LIBRARY_PATH=../libs/SFML/lib/:$$LD_LIBRARY_PATH && ./main.elf
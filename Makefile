CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror
LDFLAGS			=	-Wl,-rpath,'/nfs/homes/laprieur/.local/lib'
RAYLIB_LDFLAGS	=	-L /nfs/homes/laprieur/.local/lib -lraylib -lglfw -lGL -lm -lpthread -lrt -lX11 -ldl
RAYLIB_INCLUDE	=	-I /nfs/homes/laprieur/.local/include
SDL_LDFLAGS		=	-L /nfs/homes/laprieur/.local/lib -lSDL2 -ldl
SDL_INCLUDE		=	-I /nfs/homes/laprieur/.local/include/SDL2
SFML_LDFLAGS	=	-L /nfs/homes/laprieur/.local/lib -lsfml-graphics -lsfml-window -lsfml-system -ldl
SFML_INCLUDE	=	-I /nfs/homes/laprieur/.local/include/SFML
BINS			=	src/Raylib.so src/SDL.so src/SFML.so src/main.elf

all: $(BINS)

%.so: %.cpp
	@$(CC) $(CFLAGS) $(LDFLAGS) -fPIC -shared -o $@ $^ $(RAYLIB_LDFLAGS) $(SDL_LDFLAGS) $(SFML_LDFLAGS) $(RAYLIB_INCLUDE) $(SDL_INCLUDE) $(SFML_INCLUDE)

src/main.elf: src/main.cpp src/Raylib.so src/SDL.so src/SFML.so
	@$(CC) $(CFLAGS) -o $@ $^ -ldl

clean:
	@rm -f $(BINS) *.o

re:
	@$(MAKE) clean
	@$(MAKE) all

run:
	@./nibbler 500 500

CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror
LDFLAGS			=	-L ../SDL/ -lSDL2 -ldl
SDL_INCLUDE		=	-I ../SDL/include/
BINS			=	wrapper.so main.elf

all: $(BINS)

%.so: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(SDL_INCLUDE) $(LDFLAGS)

%.elf: %.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(SDL_INCLUDE) $(LDFLAGS)

clean:
	rm $(BINS)

run:
	export LD_LIBRARY_PATH=../SDL/:$$LD_LIBRARY_PATH && ./main.elf
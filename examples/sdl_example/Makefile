CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror
LDFLAGS			=	-L ../libs/SDL/ -lSDL2 -ldl
SDL_INCLUDE		=	-I ../libs/SDL/include/
BINS			=	wrapper.so main.elf

all: $(BINS)

%.so: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(SDL_INCLUDE) $(LDFLAGS)

%.elf: %.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(SDL_INCLUDE) $(LDFLAGS)

clean:
	rm -f $(BINS) *.o

re:
	$(MAKE) clean
	$(MAKE) all

run:
	export LD_LIBRARY_PATH=../libs/SDL/:$$LD_LIBRARY_PATH && ./main.elf
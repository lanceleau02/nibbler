CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror
LDFLAGS			=	-L ../libs/Raylib/lib -lraylib -lglfw -lGL -lm -lpthread -ldl -lrt -lX11
RAYLIB_INCLUDE	=	-I ../libs/Raylib/include
BINS			=	wrapper.so main.elf

all: $(BINS)

%.so: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(RAYLIB_INCLUDE) $(LDFLAGS)

%.elf: %.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(RAYLIB_INCLUDE) $(LDFLAGS)

clean:
	rm -f $(BINS) *.o

re:
	$(MAKE) clean
	$(MAKE) all

run:
	export LD_LIBRARY_PATH=../libs/Raylib/lib/:$$LD_LIBRARY_PATH && ./main.elf

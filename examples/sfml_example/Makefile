CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror
LDFLAGS			=	-L ../libs/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -ldl
SFML_INCLUDE	=	-I ../libs/SFML/include
BINS			=	wrapper.so main.elf

all: $(BINS)

%.so: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(SFML_INCLUDE) $(LDFLAGS)

%.elf: %.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(SFML_INCLUDE) $(LDFLAGS)

clean:
	rm -f $(BINS) *.o

re:
	$(MAKE) clean
	$(MAKE) all

run:
	export LD_LIBRARY_PATH=../libs/SFML/lib/:$$LD_LIBRARY_PATH && ./main.elf
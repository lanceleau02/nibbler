CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror
LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -ldl
BINS	=	wrapper.so main.elf

all: $(BINS)

%.so: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(LDFLAGS)

%.elf: %.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm $(BINS)
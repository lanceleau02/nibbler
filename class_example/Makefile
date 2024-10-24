CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror
BINS	=	triangle.so main.elf

all: $(BINS)

%.so: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^

%.elf: %.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(BINS)
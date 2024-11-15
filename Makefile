compiler = gcc
flags = -Wall -Werror -std=c99

all: fsh

#compile fsh.c into executable called fsh
fsh: fsh.c
	$(CC) $(CFLAGS) -o fsh fsh.c
#clean rule to remove the fsh executable
clean:
	rm -f fsh

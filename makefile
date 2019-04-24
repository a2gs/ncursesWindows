all: clean
	cc -o a a.c -lncurses -Wall
	cc -o b b.c -lncurses -Wall
	cc -o c c.c -lncurses -Wall -Wno-unused-but-set-variable

clean:
	rm -rf a b c

all:
	cc -o a a.c -lncurses -Wall
	cc -o b b.c -lncurses -Wall

clean:
	rm -rf a b

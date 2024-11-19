all: 
	gcc -Wall -Wextra -Wpedantic rps.c -o runGame

clean: 
	rm runGame
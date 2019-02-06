all:cachesim

cachesim:cachesim.c
	gcc -g -Wall -Werror -fsanitize=address cachesim.c -lm -o cachesim 
clean:
	rm -rf cachesim

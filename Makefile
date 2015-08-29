default: build execute

build:
	@gcc -Wall -o stare -s stare.c
	@gcc -Wall -o genea -s genea.c

execute:
	@valgrind -v --leak-check=full ./stare genea -v echo yes

cmd=./stare genea -v echo yes

default: compile execute

compile:
	@gcc -Wall -o stare -s stare.c
	@gcc -Wall -o genea -s genea.c

execute:
	@$(cmd)

valgrind_execute:
	@valgrind $(cmd)
	#@valgrind -v --leak-check=full $(cmd)

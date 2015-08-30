cmd=stare Makefile -v echo yes

default: compile

compile:
	@mkdir -p build
	@gcc -Wall -o build/stare -s src/stare.c

execute:
	@$(cmd)

clean:
	rm -rf build

valgrind_execute:
	@valgrind -v --leak-check=full build/$(cmd)

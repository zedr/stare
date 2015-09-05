cmd=stare Makefile -v echo yes

default: compile

compile:
	@mkdir -p build
	gcc -Wall -o build/stare -s src/stare/*.c

execute:
	@$(cmd)

tests:
	gcc -g -Wall -o build/tests src/stare/config.c src/tests/config_tests.c
	@./build/tests

clean:
	@rm -rf build

valgrind_execute:
	@valgrind -v --leak-check=full build/$(cmd)

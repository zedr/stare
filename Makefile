cmd=stare Makefile -v echo yes

default: compile

compile:
	@mkdir -p build
	gcc -Wall -o build/stare -s src/stare/*.c

execute:
	@$(cmd)

tests:
	gcc -g -Wall -o build/config_tests src/stare/config.c src/tests/config_tests.c
	gcc -g -Wall -o build/str_tests src/stare/str.c src/tests/str_tests.c
	@./build/config_tests
	@./build/str_tests

clean:
	@rm -rf build

lint:
	 @./tools/checkpatch.pl -f --no-tree src/**/*.c

valgrind_execute:
	@valgrind -v --leak-check=full build/$(cmd)

KEY = -std=c99 -Wall -Werror -pedantic
FILES = my_snprintf.o unit_tests.o
test.exe: $(FILES) unit_tests.o
	gcc -o test.exe $(FILES) $(KEY)
utest: test.exe
	./test.exe
%.o: %.c
	gcc -c $< -o $@ $(KEY)
clean:
	rm *.exe *.o
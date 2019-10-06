KEY = -std=c99 -Wall -Werror
app.exe: main.o adding.o CDIO.o darray.o multiply.o removal.o func_test
	gcc -o app.exe main.o adding.o CDIO.o darray.o multiply.o removal.o $(KEY)
%.o: %.c
	gcc -c $< -o $@ $(KEY)
func_test:
	./func_tests/func_tests.exec
clear:
	rm *.exe *.o

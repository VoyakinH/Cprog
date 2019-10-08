KEY = -std=c99 -Wall -Werror
app.exe: main.o adding.o CDIO.o darray.o multiply.o removal.o test.exe
	gcc -o app.exe main.o adding.o CDIO.o darray.o multiply.o removal.o $(KEY)
test.exe: unit_tests.o CDIO.o darray.o
	gcc -o test.exe unit_tests.o CDIO.o darray.o $(KEY)
%.o: %.c
	gcc -c $< -o $@ $(KEY)
func_test: app.exe
	./func_tests/func_tests.exec
clear:
	rm *.exe *.o

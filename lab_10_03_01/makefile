KEY = -std=c99 -Wall -Werror -pedantic
app.exe: main.o CDIO.o darray.o arr_process.o read_exp.o
	gcc -o app.exe main.o CDIO.o darray.o arr_process.o read_exp.o $(KEY)
test.exe: unit_tests.o CDIO.o darray.o arr_process.o read_exp.o
	gcc -o test.exe unit_tests.o CDIO.o darray.o arr_process.o read_exp.o $(KEY)
clean:
	rm *.exe *.o
ftest: app.exe
	./func_tests/func_tests.exec
utest: test.exe
	./test.exe
%.o: %.c
	gcc -c $< -o $@ $(KEY)
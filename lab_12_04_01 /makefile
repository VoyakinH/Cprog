KEY = -std=c99 -Wall -Werror -pedantic -O0 -g3
app.exe: main.o cdio.o list_func.o process.o
	gcc -o app.exe main.o cdio.o list_func.o process.o $(KEY)
test.exe: unit_tests.o
	gcc -o test.exe unit_tests.o $(KEY)
utest: test.exe
	./test.exe
%.o: %.c
	gcc -c $< -o $@ $(KEY)
clean:
	rm *.exe *.o
ftest: app.exe
	./func_tests/func_tests.exec
KEY = -std=c99 -Wall -Werror -pedantic
app.exe: main.o cdio.o process.o list_func.o
	gcc -o app.exe main.o cdio.o process.o list_func.o $(KEY)
test.exe: test.o cdio.o process.o list_func.o
	gcc -o test.exe test.o cdio.o process.o list_func.o $(KEY)
clean:
	rm *.exe *.o
utest: test.exe
	./test.exe
ftest: app.exe
	./func_tests/func_tests.exec
%.o: %.c
	gcc -c $< -o $@ $(KEY)
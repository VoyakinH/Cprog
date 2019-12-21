KEY = -std=c99 -Wall -Werror -pedantic
app.exe: main.o cdio.o process.o list_func.o
	gcc -o app.exe main.o cdio.o process.o list_func.o $(KEY)
clean:
	rm *.exe *.o
ftest: app.exe
	./func_tests/func_tests.exec
%.o: %.c
	gcc -c $< -o $@ $(KEY)
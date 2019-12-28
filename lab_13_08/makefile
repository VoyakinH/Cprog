KEY = -std=c99 -Wall -Werror -pedantic -fPIC
static: darray.o count.o CDIO.o insertion.o removal.o
	ar rc libdynarr.a darray.o count.o CDIO.o insertion.o removal.o
	ranlib libdynarr.a
sprog: main.c static
	gcc main.c -L. -ldynarr -o sprog.exe $(KEY)
dynamic: darray.o count.o CDIO.o insertion.o removal.o
	gcc -shared -o libdynarr.so darray.o count.o CDIO.o insertion.o removal.o
dprog: main.o dynamic
	gcc main.o -L. -ldynarr -Wl,-rpath,. -o dprog.exe $(KEY)
lprog: main_lin.c dynamic
	gcc -ldl main_lin.c -o lprog.exe
ftest: sprog dprog lprog
	./func_tests/func_tests.exec
%.o: %.c
	gcc -c $< -o $@ $(KEY)
clean:
	rm *.exe *.o *.a *.so

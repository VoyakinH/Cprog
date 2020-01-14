KEY = -std=c99 -Wall -Werror -pedantic -fPIC
app.exe: main.o
	gcc main.o -L. -lui.A -Wl,-rpath,. -o app.exe $(KEY)
clean:
	rm *.exe *.o
%.o: %.c
	gcc -c $< -o $@ $(KEY)
KEY = -std=c99 -Wall -Werror
app.exe: main.o adding.o CDIO.o darray.o multiply.o removal.o
	gcc -o app.exe main.o adding.o CDIO.o darray.o multiply.o removal.o $(KEY)
%.o: %.c
	gcc -c $< -o $@ $(KEY)
clear:
	rm *.exe *.o

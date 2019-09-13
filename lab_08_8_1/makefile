app.exe: main.o darray.o count.o CDIO.o insertion.o removal.o
	gcc -o app.exe main.o darray.o count.o CDIO.o insertion.o removal.o
main.o: main.c
	gcc -o main.o -c main.c
darray.o: darray.c
	gcc -o darray.o -c darray.c
count.o: count.c
	gcc -o count.o -c count.c
CDIO.o: CDIO.c
	gcc -o CDIO.o -c CDIO.c
insertion.o: insertion.c
	gcc -o insertion.o -c insertion.c
removal.o: removal.c
	gcc -o removal.o -c removal.c
clear:
	rm *.exe *.o
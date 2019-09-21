KEY = -std=c99 -Wall -Werror
app.exe: main.o darray.o count.o CDIO.o insertion.o removal.o test.exe
	gcc -o  app.exe main.o darray.o count.o CDIO.o insertion.o removal.o $(KEY)
test.exe: CDIO.o test.o
	gcc -o test.exe CDIO.o test.o $(KEY)
main.o: main.c
	gcc -o main.o -c main.c $(KEY)
darray.o: darray.c
	gcc -o darray.o -c darray.c $(KEY)
count.o: count.c
	gcc -o count.o -c count.c $(KEY)
CDIO.o: CDIO.c
	gcc -o CDIO.o -c CDIO.c $(KEY)
insertion.o: insertion.c
	gcc -o insertion.o -c insertion.c $(KEY)
removal.o: removal.c
	gcc -o removal.o -c removal.c $(KEY)
test.o: test.c
	gcc -o test.o -c test.c $(KEY)
clear:
	rm *.exe *.o

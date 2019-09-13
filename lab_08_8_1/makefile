app.exe: main.o darray.o count.o cdio.o insertion.o removal.o
	gcc -o  app.exe main.o darray.o count.o cdio.o insertion.o removal.o -std=c99 -Wall -Werror
test.exe: cdio.o test.o
	gcc -o test.exe cdio.o test.o -std=c99 -Wall -Werror
main.o: main.c
	gcc -o main.o -c main.c -std=c99 -Wall -Werror
darray.o: darray.c
	gcc -o darray.o -c darray.c -std=c99 -Wall -Werror
count.o: count.c
	gcc -o count.o -c count.c -std=c99 -Wall -Werror
cdio.o: cdio.c
	gcc -o cdio.o -c cdio.c -std=c99 -Wall -Werror
insertion.o: insertion.c
	gcc -o insertion.o -c insertion.c -std=c99 -Wall -Werror
removal.o: removal.c
	gcc -o removal.o -c removal.c -std=c99 -Wall -Werror
test.o: test.c
	gcc -o test.o -c test.c -std=c99 -Wall -Werror
clear:
	rm *.exe *.o
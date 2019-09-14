app.exe: main.o darray.o count.o CDIO.o insertion.o removal.o test.exe
	gcc -o  app.exe main.o darray.o count.o CDIO.o insertion.o removal.o -std=c99 -Wall -Werror -O0 -g3
test.exe: CDIO.o test.o
	gcc -o test.exe CDIO.o test.o -std=c99 -Wall -Werror -O0 -g3
main.o: main.c
	gcc -o main.o -c main.c -std=c99 -Wall -Werror -O0 -g3
darray.o: darray.c
	gcc -o darray.o -c darray.c -std=c99 -Wall -Werror -O0 -g3
count.o: count.c
	gcc -o count.o -c count.c -std=c99 -Wall -Werror -O0 -g3
CDIO.o: CDIO.c
	gcc -o CDIO.o -c CDIO.c -std=c99 -Wall -Werror -O0 -g3
insertion.o: insertion.c
	gcc -o insertion.o -c insertion.c -std=c99 -Wall -Werror -O0 -g3
removal.o: removal.c
	gcc -o removal.o -c removal.c -std=c99 -Wall -Werror -O0 -g3
test.o: test.c
	gcc -o test.o -c test.c -std=c99 -Wall -Werror -O0 -g3
clear:
	rm *.exe *.o

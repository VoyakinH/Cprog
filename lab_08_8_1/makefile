app.exe: main.o darray.o count_u1.o
	gcc -o app.exe main.o darray.o count_u1.o
main.o: main.c
	gcc -o main.o -c main.c
darray.o: darray.c
	gcc -o darray.o -c darray.c
count_u1.o: count_u1.c
	gcc -o count_u1.o -c count_u1.c
clear:
	rm *.exe *.o
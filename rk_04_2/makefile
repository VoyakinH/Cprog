app.exe: main.o list_func.o process.o
	gcc -o app.exe main.o list_func.o process.o
%.o: %.c
	gcc -c $< -o $@
clean:
	rm *.exe *.o
	
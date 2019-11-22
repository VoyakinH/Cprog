KEY = -std=c99 -Wall -Werror -pedantic
FILES = main.o darray.o CDIO.o arr_process.o
run: app.exe
	./app.exe
app.exe: $(FILES)
	gcc -o app.exe $(FILES) $(KEY)
%.o: %.c
	gcc -c $< -o $@ $(KEY)
clear:
	rm *.exe *.o

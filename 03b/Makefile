main.o: main.c
	@echo "Compiling main"
	gcc -c main.c

link: main.o
	@echo "Linking"
	gcc main.o -o run

clean:
	@echo "Cleaning"
	rm main.o run

start:
	@./run

CC = gcc -lSDL2main -lSDL2 -lSDL_image
CFLAGS = -Wall -Wextra -Werror 

Parcours_Utilisateur: main.o 
	$(CC) main.o 

all: main.o
	$(CC) main.o 


%o:%c %h
	$(CC) -o $@ -c $< $(OPTIONS)
clean:
	rm -rf *.o

fclean:
	rm a.out

re:
	$(fclean) $(all)



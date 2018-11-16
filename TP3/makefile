OPTIONS=-Wall -Wextra -g

prog:vecteur.o teZZt.o tests_vecteur.o
	gcc -o prog vecteur.o teZZt.o tests_vecteur.o
	
vecteur.o:vecteur.c vecteur.h
	gcc ${OPTIONS} vecteur.c -c
	
tests_vecteur.o:tests_vecteur.c
	gcc ${OPTIONS} tests_vecteur.c -c

teZZt.o:teZZt.h teZZt.c
	gcc -c teZZt.c
clean:
	rm -f vecteur.o teZZt.o tests_vecteur.o *.gch

cc = gcc
obj = src/arbre.o src/hachage.o src/liste.o src/main.o
flags = -Wall -o

app: $(obj)
	$(cc) $(flags) app $(obj)

src/arbre.o: src/arbre.c include/arbre.h
src/hachage.o: src/hachage.c include/hachage.h
src/liste.o: src/liste.c include/liste.h
src/main.o: src/main.c

clean:
	rm -f $(obj) app

git:
	git add include/* src/*.c makefile notice.txt
HEADERS = commits.h users.h repos.h

default: guiao1

guiao1: main.o
	gcc -o guiao1 main.o users.o commits.o repos.o

main.o: main.c users.o commits.o repos.o $(HEADERS)
	gcc -c main.c users.c commits.c repos.c

users.o: users.c users.h

commits.o: commits.c commits.h

repos.o: repos.c repos.h



clean:
	-rm -f users.o
	-rm -f commits.o
	-rm -f repos.o
	-rm -f main.o
	-rm -f guiao1


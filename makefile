work10: work10.o main10.o
	gcc -o work10 work10.o main10.o

main10.o: main10.c work10.h
	gcc -c main10.c

work10.o: work10.c work10.h
	gcc -c work10.c

run:
	./work10
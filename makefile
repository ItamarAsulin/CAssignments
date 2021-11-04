CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=mylib.o
FLAGS= -Wall -g
OBJ_LOOP = basicClassification.o advancedClassificationLoop.o
OBJ_REC = basicClassification.o advancedClassificationRecursion.o

all: loops recursives recursived loopd mains maindloop maindrec 

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so

mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm

maindrec: main.o
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

maindloop: main.o
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so -lm

libclassloops.a: $(OBJ_LOOP)
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassloops.so: $(OBJ_LOOP)
	$(CC) -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so

libclassrec.a: $(OBJ_REC)
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
	 
libclassrec.so: $(OBJ_REC)
	$(CC) -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so

basicClassification.o: basicClassification.c
	$(CC) $(FLAGS) -c basicClassification.c -lm

advancedClassificationLoop.o: advancedClassificationLoop.c
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -lm

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c -lm

clean:
	rm -f *.o *.a *.so mains maindrec maindloop

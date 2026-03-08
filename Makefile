
all: nr r tr


nr:
	g++ noRecursion.cpp -o nr
	./nr
r:
	g++ recursion.cpp -o r
	./r
tr:
	g++ tailRecursion.cpp -o tr
	./tr

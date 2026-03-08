
all: nr r tr clean


nr:
	g++ noRecursion.cpp -o nr -O2
	./nr
r:
	g++ recursion.cpp -o r -O2
	./r
tr:
	g++ tailRecursion.cpp -o tr -O2
	./tr
clean:
	rm -f nr tr r

all:
	g++ -o main.o main.cpp -std=c++11
run:
	./main.o
clean:
	rm -f main.o
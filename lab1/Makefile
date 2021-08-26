approx.o: approx.cpp
	g++ -c approx.cpp

main.o: main.cpp
	g++ -c main.cpp

approx-pi: approx.o main.o
	g++ main.o approx.o -o approx-pi

test: approx-pi
	./approx-pi < lab1-test.in > lab1-mine.out

clean: 
	rm *.o 

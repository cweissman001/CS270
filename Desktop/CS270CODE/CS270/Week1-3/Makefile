all: factorial 

factorial: factorial.o main.o
	g++ factorial factoral.o main.0

facttest: factorial.o test.o
	g++ -o facttest factorial.o test.o -lgtest -lpthread
    
factorial.o: factorial.cpp factorial.h
	g++ -c factorial.cpp
    
test.o: test.cpp factorial.h
	g++ -c test.cpp
    
main.o: factorial_main.cpp factorial.h
	g++ -c factorial_main.cpp -o main.o
	
clean:
	rm -f factorial.0 test.o main.o factorial facttest
	
test: facttest
	./facttest
all: test

test: mytest
	./mytest

testcompile: test.o

mytest: test.o mystring.o
	g++ $^ -o $@ -lgtest -lpthread

%.o: %.cpp mystring.h
	g++ -c $< -o $@

clean:
	rm -f ./*.o mytest

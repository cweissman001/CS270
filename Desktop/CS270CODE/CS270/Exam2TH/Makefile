all: test

test: reuse
	./reuse

reuse: reuse.o
	g++ -std=c++11 -o $@ $^ -lgtest -lpthread

%.o: %.cpp
	g++ -c -o $@ $<

clean:
	rm -f reuse ./*.o
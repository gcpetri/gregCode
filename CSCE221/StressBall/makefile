all: test

test:  Stress_ball.o Collection.o main.o
	g++ -o test Stress_ball.o Collection.o main.o

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	g++ -c Stress_ball.cpp

Collection.o: Stress_ball.cpp Stress_ball.h Collection.cpp Collection.h
	g++ -c Collection.cpp

main.o: Stress_ball.cpp Stress_ball.h Collection.cpp Collection.h main.cpp
	g++ -c main.cpp

clean:
	rm -f *o test

run: test
	./test
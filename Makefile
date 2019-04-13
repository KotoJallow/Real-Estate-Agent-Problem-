
run: exe
	./runnable

exe: util matcher main
	g++ util.o matcher.o main.o -o runnable

main: main.cpp
	g++ -c main.cpp

util: util.cpp
	g++ -c util.cpp 
matcher: matcher.cpp
	g++ -c matcher.cpp

clean:
	rm *.o
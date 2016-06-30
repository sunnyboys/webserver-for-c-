objects = ./bin/main.o ./bin/request.o ./bin/serverSocket.o
webserver : $(objects)
	g++ -o webserver $(objects)


./bin/request.o : ./src/request.cpp
	g++ -c -o ./bin/request.o ./src/request.cpp

./bin/serverSocket.o : ./src/serverSocket.cpp
	g++ -c -o ./bin/serverSocket.o ./src/serverSocket.cpp

./bin/main.o : ./src/main.cpp ./head/request.h ./head/serverSocket.h
	g++ -c -o ./bin/main.o ./src/main.cpp

.PHONY : clean
clean :
	rm webserver $(objects) 

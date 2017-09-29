all: server cli

server: server.cpp socket.cpp
	g++ -o server server.cpp socket.cpp

cli: cli.cpp socket.cpp
	g++ -o cli cli.cpp socket.cpp

clean:
	rm -rf server cli

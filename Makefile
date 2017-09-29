all:ser_cv cli_cv

ser_cv:ser_cv.cpp socket.cpp sockmat.cpp
	g++ -o ser_cv ser_cv.cpp socket.cpp sockmat.cpp `pkg-config --cflags --libs opencv` -g

cli_cv:cli_cv.cpp socket.cpp sockmat.cpp
	g++ -o cli_cv cli_cv.cpp socket.cpp sockmat.cpp `pkg-config --cflags --libs opencv`

clean:
	rm -rf ser_cv cli_cv

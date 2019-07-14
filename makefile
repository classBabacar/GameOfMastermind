build: game

game: main.cc mastermind.cc colors.h
	g++ -o game *.cc

clean:
	rm game
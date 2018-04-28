LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: isid

GameManager.o: GameManager.h GameManager.cpp
	g++ -c "GameManager.cpp" -o GameManager.o

isid.o: GameManager.h isid.cpp
	g++ -c "isid.cpp" -o isid.o
	
isid: GameManager.o isid.o
	@echo "Building the game"
	g++ -o isid GameManager.o isid.o $(LIBS)

clean:
	@echo "Removing object files and executable"
	rm -f isid *.o

install:
	@echo "Installing"
	cp isid /usr/bin

uninstall:
	@echo "Uninstalling"
	rm -f /usr/bin/isid

LIBS=-lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp

all: isid

RenderedObject.o: RenderedObject.h RenderedObject.cpp
	g++ -c "RenderedObject.cpp" -o RenderedObject.o

FileManager.o: RenderedObject.h FileManager.h FileManager.cpp
	g++ -c "FileManager.cpp" -o FileManager.o

RenderManager.o: RenderedObject.h RenderManager.h RenderManager.cpp
	g++ -c "RenderManager.cpp" -o RenderManager.o

GameManager.o: RenderedObject.h RenderManager.h FileManager.h GameManager.h GameManager.cpp
	g++ -c "GameManager.cpp" -o GameManager.o

isid.o: GameManager.h isid.cpp
	g++ -c "isid.cpp" -o isid.o
	
isid: RenderedObject.o FileManager.o RenderManager.o GameManager.o isid.o
	@echo "Building the game"
	g++ -o isid RenderedObject.o FileManager.o RenderManager.o GameManager.o isid.o $(LIBS)

clean:
	@echo "Removing object files and executable"
	rm -f isid *.o

install:
	@echo "Installing"
	cp isid /usr/bin

uninstall:
	@echo "Uninstalling"
	rm -f /usr/bin/isid

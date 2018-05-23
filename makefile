LIBS=-lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp

all: isid

Vec2D.o: Vec2D.h Vec2D.cpp
	g++ -c "Vec2D.cpp" -o Vec2D.o

GridMap.o: Vec2D.h GridMap.h GridMap.cpp
	g++ -c "GridMap.cpp" -o GridMap.o

RenderedObject.o: GridMap.h RenderedObject.h RenderedObject.cpp
	g++ -c "RenderedObject.cpp" -o RenderedObject.o

FileManager.o: RenderedObject.h FileManager.h FileManager.cpp
	g++ -c "FileManager.cpp" -o FileManager.o

HUD.o: RenderedObject.h HUD.h HUD.cpp
	g++ -c "HUD.cpp" -o HUD.o

RenderManager.o: RenderedObject.h RenderManager.h RenderManager.cpp
	g++ -c "RenderManager.cpp" -o RenderManager.o

GameManager.o: RenderedObject.h HUD.h RenderManager.h FileManager.h GameManager.h GameManager.cpp
	g++ -c "GameManager.cpp" -o GameManager.o

isid.o: GameManager.h isid.cpp
	g++ -c "isid.cpp" -o isid.o
	
isid: Vec2D.o RenderedObject.o FileManager.o HUD.o RenderManager.o GridMap.o GameManager.o isid.o
	@echo "Building the game"
	g++ -o isid Vec2D.o RenderedObject.o FileManager.o HUD.o RenderManager.o GridMap.o GameManager.o isid.o $(LIBS)

clean:
	@echo "Removing object files and executable"
	rm -f isid *.o

install:
	@echo "Installing"
	cp isid /usr/bin

uninstall:
	@echo "Uninstalling"
	rm -f /usr/bin/isid

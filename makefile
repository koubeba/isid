LIBS=-lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp

friends: isid
all: isid

Item.o: RenderedObject.h Item.h Item.cpp
	g++ -c -g "Item.cpp" -o Item.o



Player.o: Pawn.h Player.h Player.cpp
	g++ -c -g "Player.cpp" -o Player.o

Pawn.o: RenderedObject.h Pawn.h Pawn.cpp
	g++ -c -g "Pawn.cpp" -o Pawn.o

GraphMap.o: TiledMap.h Tile.h Pawn.h GraphMap.h GraphMap.cpp
	g++ -c -g "GraphMap.cpp" -o GraphMap.o

Enemy.o: GraphMap.h Pawn.h Enemy.h Enemy.cpp
	g++ -c -g "Enemy.cpp" -o Enemy.o

Tile.o: Tile.h Tile.cpp
	g++ -c -g "Tile.cpp" -o Tile.o

TiledMap.o: Tile.h Vec2D.h FileManager.h TiledMap.h TiledMap.cpp
	g++ -c -g "TiledMap.cpp" -o TiledMap.o

Vec2D.o: Vec2D.h Vec2D.cpp
	g++ -c -g "Vec2D.cpp" -o Vec2D.o

GridMap.o: Vec2D.h GridMap.h GridMap.cpp
	g++ -c -g "GridMap.cpp" -o GridMap.o

RenderedObject.o: GridMap.h RenderedObject.h RenderedObject.cpp
	g++ -c -g "RenderedObject.cpp" -o RenderedObject.o

FileManager.o: RenderedObject.h FileManager.h FileManager.cpp
	g++ -c -g "FileManager.cpp" -o FileManager.o

HUDElement.o: RenderedObject.h Vec2D.h HUDElement.h HUDElement.cpp
	g++ -c -g "HUDElement.cpp" -o HUDElement.o

HUD.o: HUDElement.h RenderedObject.h HUD.h HUD.cpp
	g++ -c -g "HUD.cpp" -o HUD.o

RenderManager.o: RenderedObject.h RenderManager.h RenderManager.cpp
	g++ -c -g "RenderManager.cpp" -o RenderManager.o

GameManager.o: TiledMap.h GraphMap.h RenderedObject.h HUD.h RenderManager.h FileManager.h GameManager.h GameManager.cpp
	g++ -c -g "GameManager.cpp" -o GameManager.o

isid.o: GameManager.h isid.cpp
	g++ -c -g "isid.cpp" -o isid.o
	
isid: Item.o Enemy.o Player.o Pawn.o GraphMap.o Tile.o TiledMap.o Vec2D.o RenderedObject.o FileManager.o HUDElement.o HUD.o RenderManager.o GridMap.o GameManager.o isid.o
	@echo "Building the game"
	g++ -o isid -g Item.o Enemy.o Player.o Pawn.o GraphMap.o Tile.o TiledMap.o Vec2D.o RenderedObject.o FileManager.o HUDElement.o HUD.o RenderManager.o GridMap.o GameManager.o isid.o $(LIBS)

clean:
	@echo "Removing object files and executable"
	rm -f isid *.o

install:
	@echo "Installing"
	cp isid /usr/bin

uninstall:
	@echo "Uninstalling"
	rm -f /usr/bin/isid

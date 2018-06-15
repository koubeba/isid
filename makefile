LIBS=-lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp
CFLAGS=-std=c++11

friends: isid
all: isid

BehavioralNode.o: BehavioralNode.h BehavioralNode.cpp
	g++ -c -g "BehavioralNode.cpp" -o BehavioralNode.o

DecoratorNode.o: BehavioralNode.h DecoratorNode.h DecoratorNode.cpp
	g++ -c -g "DecoratorNode.cpp" -o DecoratorNode.o

Inverter.o: DecoratorNode.h Inverter.h Inverter.cpp
	g++ -c -g "Inverter.cpp" -o Inverter.o

Repeater.o: DecoratorNode.h Repeater.h Repeater.cpp
	g++ -c -g "Repeater.cpp" -o Repeater.o

RepeatUntilFail.o: DecoratorNode.h RepeatUntilFail.h RepeatUntilFail.cpp
	g++ -c -g "RepeatUntilFail.cpp" -o RepeatUntilFail.o

LeafNode.o: BehavioralNode.h LeafNode.h LeafNode.cpp
	g++ -c -g "LeafNode.cpp" -o LeafNode.o

CompositeNode.o: BehavioralNode.h CompositeNode.h CompositeNode.cpp
	g++ -c -g "CompositeNode.cpp" -o CompositeNode.o

MasterNode.o: CompositeNode.h MasterNode.h MasterNode.cpp
	g++ -c -g "MasterNode.cpp" -o MasterNode.o

SelectorNode.o: CompositeNode.h SelectorNode.h SelectorNode.cpp
	g++ -c -g "SelectorNode.cpp" -o SelectorNode.o

SequenceNode.o: CompositeNode.h SequenceNode.h SequenceNode.cpp
	g++ -c -g "SequenceNode.cpp" -o SequenceNode.o

RandomSelectorNode.o: CompositeNode.h RandomSelectorNode.h RandomSelectorNode.cpp
	g++ -c -g "RandomSelectorNode.cpp" -o RandomSelectorNode.o

TestLeaf.o: LeafNode.h TestLeaf.h TestLeaf.cpp
	g++ -c -g "TestLeaf.cpp" -o TestLeaf.o

WaitNode.o: LeafNode.h WaitNode.h WaitNode.cpp
	g++ -c -g "WaitNode.cpp" -o WaitNode.o

BehavioralTree.o: Repeater.h BehavioralTree.h BehavioralTree.cpp
	g++ -c -g "BehavioralTree.cpp" -o BehavioralTree.o

Item.o: RenderedObject.h Item.h Item.cpp
	g++ $(CFLAGS) -c -g "Item.cpp" -o Item.o

Player.o: Pawn.h Player.h Player.cpp
	g++ $(CFLAGS) -c -g "Player.cpp" -o Player.o

Pawn.o: RenderedObject.h Pawn.h Pawn.cpp
	g++ $(CFLAGS) -c -g "Pawn.cpp" -o Pawn.o

GraphMap.o: TiledMap.h Tile.h Pawn.h GraphMap.h GraphMap.cpp
	g++ $(CFLAGS) -c -g "GraphMap.cpp" -o GraphMap.o

Enemy.o: BehavioralTree.h GraphMap.h Pawn.h Enemy.h Enemy.cpp
	g++ $(CFLAGS) -c -g "Enemy.cpp" -o Enemy.o

Tubaman.o: Enemy.h Tubaman.h Tubaman.cpp
	g++ $(CFLAGS) -c -g "Tubaman.cpp" -o Tubaman.o

Cymbalman.o: Enemy.h Cymbalman.h Cymbalman.cpp
	g++ $(CFLAGS) -c -g "Cymbalman.cpp" -o Cymbalman.o

Tile.o: Tile.h Tile.cpp
	g++ $(CFLAGS) -c -g "Tile.cpp" -o Tile.o

TiledMap.o: Tile.h Vec2D.h FileManager.h TiledMap.h TiledMap.cpp
	g++ $(CFLAGS) -c -g "TiledMap.cpp" -o TiledMap.o

Vec2D.o: Vec2D.h Vec2D.cpp
	g++ $(CFLAGS) -c -g "Vec2D.cpp" -o Vec2D.o

GridMap.o: Vec2D.h GridMap.h GridMap.cpp
	g++ $(CFLAGS) -c -g "GridMap.cpp" -o GridMap.o

RenderedObject.o: GridMap.h RenderedObject.h RenderedObject.cpp
	g++ $(CFLAGS) -c -g "RenderedObject.cpp" -o RenderedObject.o

FileManager.o: RenderedObject.h FileManager.h FileManager.cpp
	g++ $(CFLAGS) -c -g "FileManager.cpp" -o FileManager.o

HUDElement.o: RenderedObject.h Vec2D.h HUDElement.h HUDElement.cpp
	g++ $(CFLAGS) -c -g "HUDElement.cpp" -o HUDElement.o

HUD.o: HUDElement.h RenderedObject.h HUD.h HUD.cpp
	g++ $(CFLAGS) -c -g "HUD.cpp" -o HUD.o

RenderManager.o: RenderedObject.h RenderManager.h RenderManager.cpp
	g++ $(CFLAGS) -c -g "RenderManager.cpp" -o RenderManager.o

GameManager.o: TiledMap.h GraphMap.h RenderedObject.h HUD.h RenderManager.h FileManager.h GameManager.h GameManager.cpp
	g++ $(CFLAGS) -c -g "GameManager.cpp" -o GameManager.o

WalkNode.o: GraphMap.h WalkNode.h WalkNode.cpp
	g++ -c -g "WalkNode.cpp" -o WalkNode.o

RunAwayNode.o: GraphMap.h RunAwayNode.h RunAwayNode.cpp
	g++ -c -g "RunAwayNode.cpp" -o RunAwayNode.o

isid.o: GameManager.h isid.cpp
	g++ $(CFLAGS) -c -g "isid.cpp" -o isid.o

isid: BehavioralNode.o DecoratorNode.o Inverter.o Repeater.o RepeatUntilFail.o LeafNode.o WaitNode.o CompositeNode.o MasterNode.o SelectorNode.o SequenceNode.o RandomSelectorNode.o TestLeaf.o BehavioralTree.o Item.o Enemy.o Tubaman.o Cymbalman.o Player.o Pawn.o GraphMap.o Tile.o TiledMap.o Vec2D.o RenderedObject.o FileManager.o HUDElement.o HUD.o RenderManager.o GridMap.o WalkNode.o RunAwayNode.o GameManager.o isid.o
	@echo "Building the game"
	g++ $(CFLAGS) -o isid -g BehavioralNode.o DecoratorNode.o Inverter.o Repeater.o RepeatUntilFail.o LeafNode.o WaitNode.o CompositeNode.o MasterNode.o SelectorNode.o SequenceNode.o RandomSelectorNode.o TestLeaf.o BehavioralTree.o Item.o Enemy.o Tubaman.o Cymbalman.o Player.o Pawn.o GraphMap.o Tile.o TiledMap.o Vec2D.o RenderedObject.o FileManager.o HUDElement.o HUD.o RenderManager.o GridMap.o WalkNode.o RunAwayNode.o GameManager.o isid.o $(LIBS)

clean:
	@echo "Removing object files and executable"
	rm -f isid *.o

install:
	@echo "Installing"
	cp isid /usr/bin

uninstall:
	@echo "Uninstalling"
	rm -f /usr/bin/isid

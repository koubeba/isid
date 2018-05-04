# isid

## classes

###### Vec2D
A helper structure of a integer vector, used to express map coordinates.

| Variable Type | Variable Name | |
| :---:         | :---:         | --- |
| *int*         | **x**         | The width coordinate |
| *int*         | **y**         | The height coordinate |

###### RenderedObject
An object that has a physical implementation in the game: has a renderable sprite


| Variable Type | Variable Name | |
| :---:         | :---:         | --- |
| *sf::Sprite* *| **sprite**    | --- |
| *Vec2D*       | **position**  | The object position in Grid coordinates |

###### GridMap
A static class used to convert between grid coordinates and window coordinates.

All maps in game, and therefore all movements, are all based on a grid map.

| Variable Type | Variable Name | |
| :---:         | :---:         | --- |
| *Vec2D*       | **size**      | Size of the map: quantity of grids in width and height |
| *Vec2D*       | **gridSize**  | A size of a single grid: in pixels |

###### FileManager
A singleton class used to load textures and other gamefiles into the running game

| Variable Type | Variable Name | |
| :---:         | :---:         | --- |
|*std::map<std::string, sf::Texture*>*| **sprites** | A map of textures which will be used to create sprites, identified by sprite name.|


###### RenderManager
A singleton class used to render sprites on the screen.

###### GameManager
A singleton class that manages the game, objects' lifetime, gamestates.


| Variable Type | Variable Name | |
| :---:         | :---:         | --- |
| *GameState*   | **gameState** | The state the game is currently in: can be either Pause, InGame, Menu |
| *RenderManager**| **renderManager** | A pointer to RenderManager that will be used to render this GameManager's objects|
| *FileManager** | **fileManager** | A pointer to FileManager that will be used to load this GameManager's objects|
| *sf::Clock* | **userInputTime** | A clock used to measure time that has passed between consequent user inputs |
| *int* | **userInputInterval** | Time (in milliseconds) after which next user input is accepted |
| *RenderedObject* | **player** | The player, who is controlled by user |

###### Biome

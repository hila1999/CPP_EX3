### README for Catan-like Game Implementation

#### Game Overview
This implementation is a simplified version of a game inspired by Settlers of Catan. The game involves players collecting resources (wood, brick, sheep, wheat, ore) to build settlements and roads on a hexagonal board made up of tiles. Each tile produces resources based on a dice roll, and players gain victory points by building settlements and cities. The first player to reach a certain number of victory points wins.

#### Class Hierarchy

1. **Player**
   - Represents a player in the game.
   - **Methods**:
     - `addResources(Resource, int)`: Adds resources to the player's inventory.
     - `addVictoryPoints(int)`: Increases the player's victory points.
     - `getName()`: Returns the player's name.
     - `setTurn(bool)`: Sets whether it's the player's turn.

2. **Structure**
   - Abstract class representing structures like settlements and cities.
   - **Methods**:
     - `getOwner()`: Returns the owner of the structure.

3. **Settlement** (inherits from Structure)
   - Represents a settlement built on a vertex of the board.

4. **City** (inherits from Structure)
   - Represents an upgraded settlement to a city.

5. **Vertex**
   - Represents a vertex on the board where structures (settlements/cities) can be built.
   - **Methods**:
     - `addAdjacentTile(vector<Tile>)`: Adds adjacent tiles to the vertex.
     - `getOwner()`: Returns the owner of the vertex.
     - `addStructure(Structure*)`: Adds a structure to the vertex.
     - `hasSettlement()`: Checks if the vertex has a settlement.
     - `upgradeToCity()`: Upgrades a settlement to a city.

6. **Edge**
   - Represents an edge on the board where roads can be built.
   - **Methods**:
     - `getOwner()`: Returns the owner of the edge.
     - `setOwner(Player*)`: Sets the owner of the edge.
     - `addStructure(Structure*)`: Adds a structure to the edge.

7. **Tile**
   - Represents a hexagonal tile on the board that produces resources.
   - **Methods**:
     - `getNumber()`: Returns the number associated with the tile.
     - `getResourceName()`: Returns the type of resource produced by the tile.
     - `getVertices()`: Returns indices of vertices adjacent to the tile.

8. **Board**
   - Represents the game board.
   - **Methods**:
     - `make()`: Initializes the board with tiles, vertices, and edges.
     - `getTile(int)`: Returns a specific tile on the board.
     - `getTiles()`: Returns all tiles on the board.
     - `getVertices()`: Returns all vertices on the board.
     - `distributeResources(int)`: Distributes resources based on a dice roll.
     - `placeStructure(Structure&, int)`: Places a structure (settlement/city) on a vertex.
     - `placeRoad(Structure&, int)`: Places a road on an edge.
     - `addPlayer(Player&)`: Adds a player to the game.
     - `getPlayers()`: Returns all players in the game.

9. **Catan**
   - Represents the main game controller.
   - **Methods**:
     - `ChooseStartingPlayer()`: Determines the starting player.
     - `getCurrentPlayer()`: Returns the current player.
     - `getBoard()`: Returns the game board.

#### Libraries Used
- `<iostream>`: Input/output operations.
- `<iomanip>`: Formatting output.
- `<sstream>`: String stream processing.
- `<stdexcept>`: Standard exceptions.
- `<typeinfo>`: Type information.
- `<vector>`: Dynamic array container.
- `<string>`: String handling.
- `<map>`: Associative containers (not fully used in the provided code).

#### Explanation of Methods

- **Vertex::hasSettlement()**: Checks if a vertex contains a settlement by iterating through its structures and using `dynamic_cast` to differentiate between Settlement and City objects.
  
- **Vertex::upgradeToCity()**: Upgrades a settlement to a city if found on the vertex, replacing the settlement object with a city object in the `structures` vector.

- **Board::make()**: Initializes the board with tiles, vertices, and edges, setting up the game environment for subsequent gameplay.

- **Board::placeStructure()**: Places a structure (settlement or city) on a specified vertex if the vertex is valid and not already occupied.

- **Board::placeRoad()**: Places a road on a specified edge if the edge is valid and not already occupied by another player's road.

- **Catan::ChooseStartingPlayer()**: Sets the starting player and initializes the game.

hila.shamir99@gmail.com
314906983

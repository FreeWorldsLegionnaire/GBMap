#ifndef GBMap
#define GBMap
//ASSUMPTION: Using a AdjacencyList for GameBoard
#include <vector> //To store all Gameboard tiles?

//default Tile from which all other tiles are derived
struct EmptyTile {
	//wtf goes in here??
	//pointer to next tile?
};

//RessourceTiles to be placed on map
struct RessourceTile : EmptyTile {
	//wtf goes in here??
	//amt of stone, wood, grain, sheep?
	//some method to count up ressources if two tiles are placed...
	//next to each other?
};
class GameBoard {
public:
	GameBoard(int players, char side);//only constructor we'll need?
	
	//All three of these methods to be used in constructor to initialize map
	//perhaps a for loop which adds EmptyTiles + edges on the board depending on num 
	//of players

	//For loop will also add 4 default ressource tiles on board perhaps by using modulus
	//e.g. for(int i = 0; i < sizeofBoard; i++)
	//			if(i % 5 == 0) *5 because it's at every corner of 5x5 square?
					//add_RessourceTile();

	void add_EmptyTile();
	void add_RessourceTile();
	void add_edge();
					
	//Demo requires showing off the map as a connected graph of adjacent squares
	//Simply print it?
	void print_map();
	
	//demo also requires testing for valid/invalid maps
	//just one method where we cram all test cases?
	bool is_valid();

private:

	int sizeofGameBoard;

	//vector(aka GameBoard/AdjacencyList) to take in any Tile derived from EmptyTile
	//*Note each tile is considered a vertex within the adjacencylist*
	vector<? : EmptyTile> TheBoard;
};
#endif
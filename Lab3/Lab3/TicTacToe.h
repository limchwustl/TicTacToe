#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "GamePieces.h"
#include <ostream>




class Tictactoe {
	friend std :: ostream& operator<< (std :: ostream&, const Tictactoe&);
public: 
	bool done();
	bool draw();
	int prompt(unsigned int& x, unsigned int&y);
	bool turn_checker = true;
	int turn();
	int play();
	int turnChecker;
	int turn_count;
	vector<game_pieces> pieces;
	string x_turn_history;
	string o_turn_history;

private: 
	unsigned int width = 5;
	unsigned int height = 5;
	
	
	
};
std::ostream & operator<< (std::ostream& os, const Tictactoe& ttc);

#endif /*TICTACTOE_H*/
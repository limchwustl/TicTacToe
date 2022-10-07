#include "stdafx.h"


#include "Lab3.h"
#include "gamePieces.h"
#include "TicTacToe.h"
#include <ostream>
#include <sstream>
#include <string>
using namespace std;

std::ostream & operator<< (std::ostream& os, const Tictactoe& ttc) {
	


	
	for (int row = 4; row >= 0; --row) {
		for (int col = 0; col <= 4; ++col) {
			unsigned int index = 5*row + col ;
			if (col == 0 ) {
				os << row << " ";
			}
			
			else if (row == 0 && col != 0) {
				os << col << " ";
			}

			else {

				os << ttc.pieces[index].displayed_piece << " ";




			}
			
			
		}
			os << " "<< endl;
			
	
		
	}
	
	return os;
}
bool Tictactoe :: done() {
	 //row 1,2,3 diag 1,2 , col 1,2,3 must be completed with one piece display to win the game
	if (pieces[5 * 3 + 1].displayed_piece != " " && pieces[5 * 3 + 1].displayed_piece == pieces[5 * 3 + 2].displayed_piece && pieces[5 * 3 + 2].displayed_piece == pieces[5 * 3 + 3].displayed_piece && pieces[5 * 3 + 1].displayed_piece == pieces[5 * 3 + 3].displayed_piece) {
		
		return true;
		//row 3
	}
	if (pieces[5 * 2 + 1].displayed_piece != " " && pieces[5 * 2 + 1].displayed_piece == pieces[5 * 2 + 2].displayed_piece && pieces[5 * 2 + 2].displayed_piece == pieces[5 * 2 + 3].displayed_piece && pieces[5 * 2 + 1].displayed_piece == pieces[5 * 2 + 3].displayed_piece) {
		
		return true;
		//row 2
	}
	if (pieces[5 * 1 + 1].displayed_piece != " " && pieces[5 * 1 + 1].displayed_piece == pieces[5 * 1 + 2].displayed_piece && pieces[5 * 1 + 2].displayed_piece == pieces[5 * 1 + 3].displayed_piece && pieces[5 * 1 + 1].displayed_piece == pieces[5 * 1 + 3].displayed_piece) {
		
		return true;
		//row 1
	}
	if (pieces[5 * 1 + 1].displayed_piece != " " && pieces[5 * 1 + 1].displayed_piece == pieces[5 * 2 + 2].displayed_piece && pieces[5 * 2 + 2].displayed_piece == pieces[5 * 3 + 3].displayed_piece && pieces[5 * 1 + 1].displayed_piece == pieces[5 * 3 + 3].displayed_piece) {
	
		return true;
		//diag 1
	}
	if (pieces[5 * 3 + 1].displayed_piece != " " && pieces[5 * 3 + 1].displayed_piece == pieces[5 * 2 + 2].displayed_piece && pieces[5 * 2 + 2].displayed_piece == pieces[5 * 1 + 3].displayed_piece && pieces[5 * 3 + 1].displayed_piece == pieces[5 * 1 + 3].displayed_piece) {
		
		return true;
		//diag 2
	}
	if (pieces[5 * 1 + 3].displayed_piece != " " && pieces[5 * 1 + 3].displayed_piece == pieces[5 * 2 + 3].displayed_piece && pieces[5 * 2 + 3].displayed_piece == pieces[5 * 3 + 3].displayed_piece && pieces[5 * 1 + 3].displayed_piece == pieces[5 * 3 + 3].displayed_piece) {
		
		return true;
		//col 3
	}
	if (pieces[5 * 1 + 2].displayed_piece != " " && pieces[5 * 1 + 2].displayed_piece == pieces[5 * 2 + 2].displayed_piece && pieces[5 * 2 + 2].displayed_piece == pieces[5 * 3 + 2].displayed_piece && pieces[5 * 1 + 2].displayed_piece == pieces[5 * 3 + 2].displayed_piece) {
		
		return true;
		//col 2
	}
	if (pieces[5 * 1 + 1].displayed_piece != " " && pieces[5 * 1 + 1].displayed_piece == pieces[5 * 2 + 1].displayed_piece && pieces[5 * 2 + 1].displayed_piece == pieces[5 * 3 + 1].displayed_piece && pieces[5 * 1 + 1].displayed_piece == pieces[5 * 3 + 1].displayed_piece) {
	
		return true;
		//col 1
	}
	
	
	return false;
}
bool Tictactoe :: draw() {
	int count = 0;
	for (int row = 3; row >= 1; --row) {
		for (int col = 1; col <= 3; ++col) {
			if (pieces[5 * row + col].displayed_piece != " ") {
				count++;
		
			}
		}
	}
	if (count == 9) {
		return true;
	}
	else if (done()) {
		return false;
	}
	
	else {
		return false;
	}
	

}
int Tictactoe :: prompt(unsigned int& x, unsigned int& y) {
	bool valid_coor = false;
	while (valid_coor == false) {
		cout << "Type your x,y coordinate in 'x,y' manner or type 'quit' to end the game." << endl;
		string line1;
		getline(cin, line1);
		int typed_x = (int)line1[0] - '0' ;
		int typed_y = (int)line1[2] - '0';
		
		if (line1.length() == 3 && line1[1] == ','&& typed_x >= 1 && typed_x < 4 && typed_y  >= 1 && typed_y < 4 && pieces[5*typed_y+typed_x].displayed_piece == " ") {
			valid_coor = true;
			line1[1] = ' ';
			istringstream iss(line1);
			iss >> x;
			iss >> y;
			return success;
		} else if (line1 == "quit") {
			valid_coor = true;
			return quit;
		}
		else {
			cout << "Type your x,y coordinate again." << endl;
		}
	}
	return success;
}
int Tictactoe::turn() {
	turn_checker = !turn_checker;
	int return_val = 0;
	if (turn_checker) {
		cout << "It is the second player (X)'s turn." << endl;
		unsigned int x;
		unsigned int y;
		game_pieces xpiece;
		if (prompt(x, y) == success) {
			xpiece.displayed_piece = "X";
			x_turn_history.push_back(x+48);
			x_turn_history.push_back(',');
			x_turn_history.push_back(y+48);
			x_turn_history.push_back(';');
			pieces[5*y+x] = xpiece;
			cout << " " << endl;
 			cout << *this << endl;
			cout << " " << endl;
			cout << "X Turn: ";
			cout << x_turn_history << endl;
			turn_checker = true;	
		}
		else {
			return quit;
		}	
	}
	else {
		cout << "It is the first play (O)'s turn." << endl;
		unsigned int x;
		unsigned int y;
		game_pieces opiece;
		if (prompt(x, y) == success) {
			//place x,y value of the piece
			opiece.displayed_piece = "O";
			o_turn_history.push_back(x+48);
			o_turn_history.push_back(',');
			o_turn_history.push_back(y+48);
			o_turn_history.push_back(';');
			pieces[5*y+x] = opiece;
			cout << " " << endl;
			cout << *this << endl;
			cout << " " << endl;
			cout << "O Turn: ";
			cout << o_turn_history << endl;
			turn_checker = false;
		}
		else {
			// quit
			return quit;
		}
	}
	return success;
}
int Tictactoe::play() {
	int error_checker = still_running;
	cout << *this << endl;
	while (error_checker == still_running) {
		
		if (done()) {
			if (turn_checker == false) {
				cout << "Turn Count : ";
				cout << turn_count << endl;
				cout << "O has won!" << endl;
				return success;
			}
			else {
				cout << "Turn Count : ";
				cout << turn_count << endl;
				cout << "X has won!" << endl;
				return success;
			}
		}
		if (draw()) {
			cout << "Turn Count : ";
			cout << turn_count << endl;
			cout << "The game is a draw!" << endl;
			return draw_check;
	}
		if (turn() == success) {
			turn_count++;
			error_checker = still_running;
		}
		else {
			cout << "Turn Count : ";
			cout << turn_count << endl;
			if (turn_checker == false) {
				
				cout << "O has quit the game..." << endl;
			}
			else {
				cout << "X has quit the game..." << endl;
			}
			
			return quit;
		}
		
}
		
	
	
	return success;
}
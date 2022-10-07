// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lab3.h"
#include "GamePieces.h"
#include "TicTacToe.h"
#include <ostream>

int usageMessage(char* program_name) {
	
		cout << "usage:" << program_name << " TicTacToe" << endl;
	
	
	return wrong_arguments_error;
}

int main(int argc, char* argv[])
{
	int return_val = success;
	string check = "";
	if (argv[input_name] != NULL) {
		check = argv[input_name];
	}

	if (argc != expected_argument || check != "TicTacToe") {
		usageMessage(argv[program_name]);
		return wrong_arguments_error;
		// return usage message for wrong arguments
	} else {
		
		
		game_pieces piece;
		Tictactoe game;
		game.turn_count = 0;
		piece.displayed_piece = " ";
		for (size_t i = 0; i < 25; ++i) {
			game.pieces.push_back(piece);
		}

		return game.play();
	
	}

}


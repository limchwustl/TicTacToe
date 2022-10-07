#pragma once
#ifndef LAB3_H
#define LAB3_H


#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

enum arrIndices
{
	program_name,
	input_name,
	expected_argument,
	
};

enum outputSuccess
{
	success,
	missing_input_file_error,
	wrong_arguments_error,
	missing_strings_in_file_error,
	missing_dimensions_error,
	missing_piece_value_error,
	missing_information_of_piece_error,
	unable_to_print_error,
	draw_check,
	quit,
	still_running,
	
	

};




int usageMessage(char* program_name);

#endif /* LAB3_H */
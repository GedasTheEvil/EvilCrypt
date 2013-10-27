#include "arg_parser.h"
#include <stdio.h>
#include <string.h>

//=============================================================================
// Fallback values
//=============================================================================

void ArgParser::add_fallbacks()
{
	if(this -> input_filename == NULL)
	{
		printf("Input filename was not set! Falling back to './input' \n");

		this -> input_filename = new char[ strlen("input") ];
		strcpy( (char*)"input", this -> input_filename );
	}

	if(this -> output_filename == NULL)
	{
		printf("Output filename was not set! Falling back to './output' \n");

		this -> output_filename = new char[ strlen("output") ];
		strcpy( (char*)"output", this -> output_filename );
	}

	if(this -> key_filename == NULL)
	{
		printf("Key filename was not set! Falling back to './key' \n");

		this -> key_filename = new char[ strlen("key") ];
		strcpy( (char*)"key", this -> key_filename );
	}
}

//=============================================================================
// Empty constructor
//=============================================================================

ArgParser::ArgParser()
{
	this -> set_all_to_null();
	this -> add_fallbacks();
}

//=============================================================================
// Main constructor
//=============================================================================

ArgParser::ArgParser(int argc, char *argv[])
{
	this -> set_all_to_null();
	this -> parse( argc, argv );
	this -> add_fallbacks();
}

//=============================================================================
// Parsing function
//=============================================================================

void ArgParser::parse(int argc, char *argv[])
{
	int i = 0;

	if( argc < 1 )
		return;

	if( strcmp( argv[i], "e" ) == 0 || strcmp( argv[i], "encrypt" ) == 0 )
	{
		this -> operation = 0;
	}
	else if( strcmp( argv[i], "d" ) == 0 || strcmp( argv[i], "decrypt" ) == 0 )
	{
		this -> operation = 1;
	}

	for( i = 1; i < argc; i++ )
	{
		if( i+1 >= argc  )
		{
			printf("Bad arguments: %s needs to be followed by a value!\n");
			break;
		}

		if( strcmp( argv[i], "-i" ) == 0 || strcmp( argv[i], "--input" ) == 0 )
		{
			i++;
			strcpy( argv[i], this -> input_filename );
		}

		else if( strcmp( argv[i], "-o" ) == 0 || strcmp( argv[i], "--output" ) == 0 )
		{
			i++;
			strcpy( argv[i], this -> output_filename );
		}

		else if( strcmp( argv[i], "-k" ) == 0 || strcmp( argv[i], "--key" ) == 0 )
		{
			i++;
			strcpy( argv[i], this -> key_filename );
		}
	}

}

//=============================================================================
// operation
//=============================================================================

int ArgParser::get_operation()
{
	return this -> operation;
}

//=============================================================================
// input
//=============================================================================

char* ArgParser::get_input()
{
	return this -> input_filename;
}

//=============================================================================
// output
//=============================================================================

char* ArgParser::get_output()
{
	return this -> output_filename;
}

//=============================================================================
// key
//=============================================================================

char* ArgParser::get_key()
{
	return this -> key_filename;
}

//=============================================================================
// Sets vars to NULL
//=============================================================================

void ArgParser::set_all_to_null()
{
	this -> operation = 0;
	this -> input_filename = NULL;
	this -> output_filename = NULL;
	this -> key_filename = NULL;
}

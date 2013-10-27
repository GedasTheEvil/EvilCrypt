#include "cui.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
//=============================================================================
// Main constructor
//=============================================================================

CUI::CUI()
{

}

//=============================================================================
// Help text function
//=============================================================================

void CUI::print_help_text()
{
	printf("Usage: operand (-i | --input) <filename> [ (-o | --output) <filename> ] [ (-k | --key ) <filename> ] \n\n");
	printf("Operands:\n\t (e | encrypt) -- Set up input file to be encrypted with key\n ");
	printf("\t (d | decrypt) -- Set up input file to be decrypted with key\n\n ");
}

//=============================================================================
// Main constructor
//=============================================================================

void CUI::print_progress( float progress, char type )
{
	if(type == 'e')
	{
		std::cout << "Encrypting: " << progress << "%\r" << std::flush;
	}
	else
	{
		std::cout << "Decrypting: " << progress << "%\r" << std::flush;
	}
}

#include "caesar_string.h"
#include <string.h>

//=============================================================================
// Main constructor
//=============================================================================

CaesarString::CaesarString( char *string )
{
        strcpy(str, string);
        length = strlen(string);
        iter   = 0;
}//constructor

//=============================================================================
// Fallback constructor
//=============================================================================

CaesarString::CaesarString()
{
        str    = new char[1];
        str[0] = 0;
        iter   = 0;
        length = 1;
}

//=============================================================================
// Char iterator. Returns the char and mover cursor forward (loop)
//=============================================================================

char CaesarString::getChar()
{
        char to_return = str[iter];
        
        iter++;
        
        if( iter >= length -1 )
        {
                iter = 0;
        }
        
        return to_return;
}//getChar

//=============================================================================
// Destructor
//=============================================================================

CaesarString::~CaesarString()
{
	delete str;
	iter   = 0;
	length = 0;
}

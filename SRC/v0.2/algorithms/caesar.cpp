#include "caesar.h"
#include <cstddef>

//=============================================================================
// Empty constructor
//=============================================================================

Caesar::Caesar()
{
	this -> mode = -1;
	this -> key  = NULL;
}

//=============================================================================
// Main constructor, without key
//=============================================================================

Caesar::Caesar(int set_mode)
{

	this -> key = NULL;
	this -> set_mode( set_mode );
}

//=============================================================================
// Main constructor
//=============================================================================

Caesar::Caesar(int set_mode, char *set_key)
{
	this -> set_mode( set_mode );
	this -> set_key( set_key );
}

//=============================================================================
// Mode setting function
//=============================================================================

void Caesar::set_mode(int set_mode)
{
	if( set_mode < 0 )
		set_mode = 0;

	if( set_mode > 1 )
		set_mode = 1;

	this -> mode = set_mode;
}

//=============================================================================
// Main constructor
//=============================================================================

void Caesar::set_key(char *set_key)
{
	if( this -> key != NULL )
	{
		delete this -> key;
		this -> key = NULL;
	}

	this -> key = new CaesarString( set_key );
}

//=============================================================================
// Main constructor
//=============================================================================

char Caesar::do_action(char ch)
{
	if( this -> key == NULL )
	{
		return ch;
	}

	int tmp = (int) ch;

	if( this -> mode == 0 )
	{
		tmp += (int) this -> key -> getChar();
	}
	else if( this -> mode == 1 )
	{
		tmp -= (int) this -> key -> getChar();
	}

	return (char) tmp;

}

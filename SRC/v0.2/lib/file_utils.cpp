#include "file_utils.h"

//=============================================================================
// Calculates the size of the file
//=============================================================================

void FileUtils::calculate_size()
{
	if( this -> type == 'w' )
	{
		this -> size = 0;
		return;
	}

	if( this -> f == NULL )
	{
		this -> f = fopen(this -> filename,"rb");
	}

	this -> size = 0;

	fseek(this -> f, 0, 0);

	if (fseek(this -> f,0, SEEK_END) == 0)
	{
		this -> size = ftell(f);
	}

	fseek(this -> f, 0, this -> cursor);
}

//=============================================================================
// Fallback constructor
//=============================================================================

FileUtils::FileUtils()
{
	this -> size     = 0;
	this -> cursor   = 0;
	this -> f        = NULL;
	this -> type     = 'r';
	this -> filename = NULL;
}

//=============================================================================
// Main constructor, no type
//=============================================================================

FileUtils::FileUtils(char *filename)
{
	this -> size   = 0;
	this -> cursor = 0;
	this -> f      = NULL;
	this -> type   = 'r';
	strcpy(this -> filename, filename);
}

//=============================================================================
// Main constructor
//=============================================================================

FileUtils::FileUtils(char *filename, char type)
{
	this -> size   = 0;
	this -> cursor = 0;
	this -> f      = NULL;
	this -> type   = type;

	if( this-> type != 'r' && this-> type != 'w')
		this-> type = 'r';

	this -> open();

	strcpy(this -> filename, filename);
}

//=============================================================================
// Close the file
//=============================================================================

void FileUtils::close()
{
	if( this -> f != NULL )
	{
		fclose(this -> f);
		this -> f = NULL;
		this -> cursor = 0;
		this -> size = 0;
	}
}

//=============================================================================
// Seek start
//=============================================================================

void FileUtils::go_to_start()
{
	if( this -> f != NULL )
	{
		fseek(this -> f, 0, 0);
	}
}

//=============================================================================
// open the file
//=============================================================================

void FileUtils::open()
{
	if( this -> f != NULL )
	{
		this -> close();
	}

	if( this -> filename == NULL )
		return;

	if( this -> type = 'r' )
	{
		this -> f = fopen(this -> filename, "rb");
	}
	else
	{
		this -> f = fopen(this -> filename, "wb");
	}
}

//=============================================================================
// Destructor
//=============================================================================

FileUtils::~FileUtils()
{
	if( this -> f != NULL )
	{
		this -> close();
	}

	if( this -> filename != NULL )
	{
		delete this -> filename;
		this -> filename = NULL;
	}
}

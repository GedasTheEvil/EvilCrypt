#include "caesar_string.h"
#include <string.h>

CaesarString::CaesarString( char *string )
{
        strcpy(string, str);
        length = strlen();
        iter = 0;
}//constructor

CaesarString::CaesarString()
{
        str = new char[1];
        str[0] = 0;
        iter= 0;
        length = 1;
}

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

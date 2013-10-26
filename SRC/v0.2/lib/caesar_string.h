#ifndef CaesarStringH
#define CaesarStringH

/**
 * The main component for all algorithms that add a string value to the file.
 * This is for the most basic encryption
 */

class CaesarString
{
        private:
                
                char *str;
                int iter;
                int length;
                
        public:
                CaesarString( char *string );
                CaesarString();

		~CaesarString();
                
                char getChar();               
        
};

#endif

#ifndef CaesarStringH
#define CaesarStringH

class CaesarString
{
        private:
                
                char *str;
                int iter;
                int length;
                
        public:
                CaesarString( char *string );
                CaesarString();
                
                char getChar();               
        
};

#endif

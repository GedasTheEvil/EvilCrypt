#ifndef CaesarH
#define CaesarH

#include "../lib/caesar_string.h"

class Caesar
{
	private:

		int mode; // 0 == encrypt, 1 == decrypt
		CaesarString *key;

	public:

		Caesar();
		Caesar(int set_mode);
		Caesar(int set_mode, char *set_key);

		void set_mode(int set_mode);
		void set_key(char *set_key);

		char do_action( char ch );
};

#endif

#ifndef ArgParserH
#define ArgParserH

#include <cstddef>

class ArgParser
{
	private:

		int operation = 0;
		char *input_filename = NULL;
		char *output_filename = NULL;
		char *key_filename = NULL;

		void add_fallbacks();
		void set_all_to_null();

	public:

		ArgParser();

		ArgParser(int argc, char *argv[]);

		void parse(int argc, char *argv[]);

		int get_operation();
		char* get_input();
		char* get_output();
		char* get_key();


};

#endif


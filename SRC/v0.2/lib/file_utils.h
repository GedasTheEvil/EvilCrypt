#ifndef FileUtilsH
#define FileUtilsH

#include <stdio.h>
#include <cstddef>
#include <string.h>

class FileUtils
{
	private:

		FILE *f;
		long size;
		int cursor;
		char *filename;
		char type;

		void calculate_size();

	public:

		FileUtils();
		FileUtils(char *filename);
		FileUtils(char *filename, char type);

		~FileUtils();

		long get_size();
		char get_next( bool &end_reached, float &progress );

		void close();
		void go_to_start();
		void open();
};

#endif

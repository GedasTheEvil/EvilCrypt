#include "algorithms/caesar.h"
#include "lib/cui.h"
#include "lib/arg_parser.h"

int main(int argc, char *argv[])
{
	CUI ui;

	if( argc < 3 )
	{
		ui.print_help_text();
	}

	ArgParser *AP = new ArgParser( argc, argv);

	return 0;
}

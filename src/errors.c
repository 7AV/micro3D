#include "among3D.h"

void	ft_error(char code)
{
	ft_putendl_fd("Error", 2);
	code == ER_ARG ? write(2, "Invalid program argument.", 26) : 0;
	code == ER_FD ? write(2, "Couldn't open file.", 20) : 0;
	code == ER_MALLOC ? write(2, "Malloc failed.", 15) : 0;
	code == ER_BAD_OPT ? write(2, "Bad options.", 13) : 0;
	code == ER_BAD_RES ? write(2, "Invalid resolution.", 20) : 0;
	code == ER_PATH ? write(2, "Invalid texture path.", 22) : 0;
	code == ER_BAD_TEXT ? write(2, "Invalid texture.", 17) : 0;
	code == ER_DUP_TEXT ? write(2, "Duplicate texture.", 19) : 0;
	code == ER_COLOR ? write(2, "Invalid colour.", 16) : 0;
	code == ER_MAP ? write(2, "Invalid map.", 13) : 0;
	code == ER_PLR ? write(2, "Invalid player.", 16) : 0;
	code == ER_SCRNSHT ? write(2, "Failed to create screenshot.", 29) : 0;
	ft_putendl_fd(" Exiting among3D... Bye!", 2);
	exit(0);
}

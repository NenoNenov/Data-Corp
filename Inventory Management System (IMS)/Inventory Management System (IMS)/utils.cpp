#include "utils.h"
#include <cstdlib>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

void clearConsole()
{
	system(CLEAR_COMMAND);
}
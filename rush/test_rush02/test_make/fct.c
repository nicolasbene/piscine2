#include <unistd.h>

void	hello()
{
	write(1, "Hello\n", 6);
}

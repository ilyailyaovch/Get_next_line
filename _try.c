#include "get_next_line.h"

//#include <unistd.h>
#include <stdio.h>

// char	*get_next_line(int fd)
// {
	
// }

int main(void)
{
	int fd;

	fd = open("tsts/file_1", O_RDONLY);
	printf ("file descriptor: %d\n", fd);

	return (0);
}
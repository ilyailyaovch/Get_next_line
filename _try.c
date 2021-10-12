#include "get_next_line.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// char	*get_next_line(int fd)
// {
	
// }

int main(void)
{
	int fd;

	fd = open("file_1", O_RDONLY);
	printf ("file descriptor: %d\n", fd);

	return (0);
}
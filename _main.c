#include "get_next_line.h"

#include <stdio.h>



char	*ft_get_buff_line(int fd, char *line)
{
	char	*buff;
	int		bytes;

	bytes = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strrchr(line, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		line = ft_strjoin(line, buff); //Adding buff to line until there is no '\n'
	}
	free (buff);
	return (line);
}

char	*ft_find_real_line(char *remain)
{
	int		coun;
	int		len_line;
	char	*line;

	coun = 0;
	len_line = 0;
	if (!remain[0])
		return (NULL);
	while (remain[len_line] && remain[len_line] != '\n')
		len_line++;
	line = (char *)malloc(sizeof(char) * (len_line + 1 + 1));
	if (!line)
		return (NULL);
	while (remain[coun] && remain[coun] != '\n')
	{
		line[coun] = remain[coun];
		coun++;
	}
	if (remain[coun] == '\n')
	{
		line[coun] = remain[coun];
		coun++;
	}
	line[coun] = '\0';
	return (line);
}

char	*ft_get_next_buff_line(char *remain)
{	
	char	*str;
	int		len_line;
	int		coun;

	len_line = 0;
	coun = 0;
	while (remain[len_line] && remain[len_line] != '\n')
		len_line++;
	if (!remain[len_line])
	{
		free(remain);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remain) - len_line));
	if (!str)
	{
		free (remain);
		return (NULL);
	}
	len_line = len_line + 1;
	while (remain[len_line])
		str[coun++] = remain[len_line++];
	str[coun] = '\0';
	free (remain);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*remain;

	if (!remain) //If there is no remain at first time
		remain = "\0";
	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	remain = ft_get_buff_line(fd, remain); //Adding everything
	if (!remain)
		return (NULL);
	line = ft_find_real_line(remain); //Looking for real line
	remain = ft_get_next_buff_line(remain); //Cut real line and saving remains
	return (line);
}

int main (void)
{
	int fd1;
	int fd2;
	int fd3;
	int i = 1;
	//int j = 1;
	char *line;

	printf ("--------------------------------------\n");
	printf ("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	printf ("--------------------------------------\n");
	fd1 = open("tsts/file_1", O_RDONLY);
	fd2 = open("tsts/file_2", O_RDONLY);
	fd3 = open("tsts/file_3", O_RDONLY);
	printf ("file_1 descriptor: %d\n", fd1);
	printf ("file_2 descriptor: %d\n", fd2);
	printf ("file_3 descriptor: %d\n", fd3);
	printf ("--------------------------------------\n");

	
	while (i < 3)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		i++;
	}
	
	// while (j < 5)
	// {
	// 	printf("%s", get_next_line(fd2));
	// 	j++;
	// }
	return (0);
}
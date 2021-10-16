/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:42:28 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/12 19:02:06 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		line[coun] = '\n';
	line[coun++] = '\0';
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
	str = (char *)malloc(sizeof(char) * (ft_strlen(remain) - len_line + 1));
	if (!str)
		return (NULL);
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
	if (fd <= -1 || BUFFER_SIZE <= 0)
		return (NULL);
	remain = ft_get_buff_line(fd, remain); //Adding evwrything
	if (!remain)
		return (NULL);
	line = ft_find_real_line(remain); //Looking for real line
	remain = ft_get_next_buff_line(remain); //Cut real line and taking remains
	return (line);
}
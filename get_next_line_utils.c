/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:50:13 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/18 14:07:22 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	coun;

	coun = 0;
	if (!str)
		return (0);
	while (str[coun] != '\0')
		coun++;
	return (coun);
}

int	ft_strchr(char *str, int ch)
{
	int	coun;

	coun = 0;
	if (!str)
		return (0);
	while (str[coun] != '\0')
	{
		if (str[coun] == (char)ch)
			return (1);
		coun++;
	}
	return (0);
}

char	*ft_strjoin(char *mem, char *buf)
{
	int			coun1;
	int			coun2;
	int			len;
	char		*str;

	if (!mem || !buf)
		return (NULL);
	len = ft_strlen(mem) + ft_strlen(buf);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	coun1 = 0;
	coun2 = 0;
	while (mem[coun1] != '\0')
	{
		str[coun1] = mem[coun1];
		coun1++;
	}
	while (buf[coun2] != '\0')
		str[coun1++] = buf[coun2++];
	str[len] = '\0';
	free (mem);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:50:13 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/12 19:50:14 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	unsigned int	coun;

	coun = 0;
	while (str[coun] != '\0')
	{
		coun++;
	}
	return (coun);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	len;
	unsigned int	coun1;
	unsigned int	coun2;
	char			*dst;

	if (!s1 || !s2)
		return (NULL);
	coun1 = 0;
	coun2 = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[coun1])
	{
		dst[coun1] = s1[coun1];
		coun1++;
	}
	while (s2[coun2])
	{
		dst[coun1 + coun2] = s2[coun2];
		coun2++;
	}
	dst[coun1 + coun2] = '\0';
	return (dst);
}

char	*ft_strrchr(char *str, int ch)
{
	int	coun;

	coun = ft_strlen(str);
	while (coun >= 0)
	{
		if (*(str + coun) == (unsigned char)ch)
			return ((char *)(str + coun));
		coun--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:44:12 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/18 11:49:55 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_get_buff_line(int fd, char *line);
char	*ft_find_real_line(char *remain);
char	*ft_get_next_buff_line(char *remain);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, int ch);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:28:39 by mmorice           #+#    #+#             */
/*   Updated: 2016/12/13 18:25:40 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	before_len_break(char *rest)
{
	int	i;

	i = 0;
	while (rest[i] != '\n')
	{
		if (i == BUFF_SIZE)
			return (i);
		i++;
	}
	return (i);
}

int	ft_free_char(char *rest, char **line, char *tmp3, char *tmp2)
{
	char	*tmp;
	size_t	len;

	len = before_len_break(rest);
	if (*line == NULL)
		tmp3 = NULL;
	if (ft_strlen(rest) >= len)
		tmp = ft_strsub(rest, len + 1, BUFF_SIZE - len - 1);
	else
	{
		*line = ft_strjoin(*line, rest);
		return (0);
	}
	if (*line != NULL)
		*line = ft_strjoin(*line, tmp2);
	else
		*line = ft_strsub(tmp2, 0, len);
	ft_strcpy(rest, tmp);
	if (tmp3 != NULL)
		free(tmp3);
	free(tmp2);
	free(tmp);
	return (1);
}

int	ft_resolve(char *rest, char **line)
{
	size_t	len;
	char	*tmp2;
	char	*tmp3;

	if (*line == NULL)
		tmp3 = NULL;
	else
		tmp3 = *line;
	len = before_len_break(rest);
	tmp2 = ft_strsub(rest, 0, len);
	if (len == BUFF_SIZE)
	{
		*line = ft_strjoin(*line, tmp2);
		if (tmp3 != NULL)
			free(tmp3);
		free(tmp2);
	}
	else
	{
		if (ft_free_char(rest, line, tmp3, tmp2) == 1)
			return (1);
	}
	return (0);
}

int	ft_check_rest(char *rest, char **line)
{
	int	i;

	i = -1;
	while (rest[++i])
	{
		if (rest[i] == '\n' || rest[i] == '\0')
		{
			if (ft_resolve(rest, line) > 0)
			{
				if ((*line)[0] != '\0')
				{
					return (1);
				}
				return (1);
			}
		}
	}
	return (-1);
}

int	get_next_line(const int fd, char **line)
{
	static char	rest[BUFF_SIZE + 1];
	int			i;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if ((i = ft_check_rest(rest, line)) >= 0)
		return (i);
	else
		*line = ft_strdup(rest);
	while ((i = read(fd, rest, BUFF_SIZE)) > 0)
	{
		if (i < 0)
			return (-1);
		rest[i] = '\0';
		if (ft_resolve(rest, line) > 0)
			return (1);
	}
	if (i < 0)
		return (-1);
	ft_strclr(rest);
	if ((*line)[0] != '\0')
		return (1);
	*line = NULL;
	return (0);
}

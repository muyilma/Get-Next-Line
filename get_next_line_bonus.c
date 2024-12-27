/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:06:33 by musyilma          #+#    #+#             */
/*   Updated: 2024/12/24 23:36:27 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_read(int fd, char *str)
{
	char	*readstr;
	int		byte;
	char	*tmp;

	readstr = ft_calloc(BUFFER_SIZE + 1, 1);
	byte = 1;
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(readstr, '\n') == 0 && byte > 0)
	{
		byte = read(fd, readstr, BUFFER_SIZE);
		if ((byte == -1) || (byte == 0 && !str[0]))
		{
			free(str);
			free(readstr);
			return (NULL);
		}
		readstr[byte] = '\0';
		tmp = str;
		str = ft_strjoin(str, readstr);
		free(tmp);
	}
	free(readstr);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*afterstr[1024];
	int			j;
	char		*beforestr;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	beforestr = NULL;
	j = -1;
	afterstr[fd] = ft_read(fd, afterstr[fd]);
	while (afterstr[fd] && afterstr[fd][++j])
	{
		if (afterstr[fd][j] == '\n' || afterstr[fd][j + 1] == '\0')
		{
			j++;
			beforestr = ft_substr(afterstr[fd], 0, j);
			temp = afterstr[fd];
			afterstr[fd] = ft_strdup(afterstr[fd] + j);
			free(temp);
			return (beforestr);
		}
	}
	return (beforestr);
}

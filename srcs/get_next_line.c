/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:47:29 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:50:50 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				get_next_line(const int fd, char **line)
{
	int			rd;
	char		buf[BUFF_SIZE + 1];
	static char *str;
	char		*cpy;

	if (!line || fd < 0 || !(str = str ? str : ft_strnew(1)))
		return (-1);
	while (!ft_strchr(str, '\n') && (rd = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (rd == ((buf[rd] = '\0') - 1))
			return (-1);
		cpy = ft_strjoin(str, buf);
		free(str);
		str = cpy;
	}
	*line = (ft_strchr(str, '\n') ? ft_strsub(str, 0,
				ft_strchr(str, '\n') - str) : ft_strdup(str));
	if (ft_strchr(cpy = str, '\n'))
	{
		str = ft_strsub(str, ft_strchr(str, '\n') - str + 1, ft_strlen(str));
		free(cpy);
	}
	else
		ft_strdel(&str);
	return (!str && ft_strlen(*line) == 0 ? 0 : 1);
}
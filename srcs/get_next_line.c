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

static char	*readline(const int fd, char *buff, int *ret)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;

	*ret = read(fd, tmp, BUFF_SIZE);
	tmp[*ret] = '\0';
	tmp2 = buff;
	if (!(buff = ft_strjoin(buff, tmp)))
		return (NULL);
	ft_strdel(&tmp2);
	return (buff);
}

int			ft_cpy_end(char **line, char **buff)
{
	if (!(*line = ft_strdup(*buff)))
		return (-1);
	ft_bzero(*buff, ft_strlen(*buff));
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*buff = "";
	int				ret;
	char			*str;

	ret = 1;
	if (!line || fd < 0 || (buff[0] == '\0' && (!(buff = ft_strnew(0)))))
		return (-1);
	while (ret > 0)
	{
		if ((str = ft_strchr(buff, '\n')) != NULL)
		{
			*str = '\0';
			if (!(*line = ft_strdup(buff)))
				return (-1);
			ft_memmove(buff, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		if (!(buff = readline(fd, buff, &ret)))
			return (-1);
	}
	ft_strdel(&str);
	if (ret == 0 && ft_strlen(buff))
		ret = ft_cpy_end(&(*line), &buff);
	return (ret);
}

/*
static char		*ft_read(char *str, int fd)
{
	int		i;
	int		ret;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	i = 0;
	str = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else
		{
			tmp = str;
			str = ft_strjoin(tmp, buff);
			ft_strdel(&tmp);
		}
	}
	return (str);
}

static char		*local_strccpy(char *str, char c)
{
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	i = ft_strchr(str, c) ? (int)(ft_strchr(str, c) - str) : ft_strlen(str);
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*tmp;
	int			i;

	if (fd < 0 || line == NULL || read(fd, str, 0) == -1)
		return (-1);
	if (!str)
		str = ft_read(*line, fd);
	i = 0;
	if (str && str[i])
	{
		while (str[i] && str[i] != '\n' && str[i + 1] != '\0')
			i++;
		*line = local_strccpy(str, '\n');
		tmp = str;
		if (*(str + i + 1))
			str = ft_strdup(&str[i + 1]);
		else
			str = NULL;
		free(tmp);
		return (1);
	}
	str = NULL;
	return (0);
}*/
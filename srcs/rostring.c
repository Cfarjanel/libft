/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:39:30 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:39:52 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

// if space (32) || '0'
// else pas de déplacement
// les spaces et zero à droite sont déplacé à gauche
/*int			rostring(char *str)
{
	char 	*new;
	int		ret;

	ret = 0;
	if (*str)
	{
		if (ft_strchr(str, ' ') == NULL)
		{
			ft_putstr(str);
			ret = ft_strlen(str);
			return (ret);
		}
		else if (*str != ' ' || *str != '0')
			new = str;
		else
			str++;
		while (*(str - 1) != ' ')
			str++;
		if (*(str - 1) == ' ')
		{
			ft_putstr(str);
			ret += ft_strlen(str);
		}
		if (*str)
		{
			write (1, " ", 1);
			ret++;
		}
		while (*new && *new != ' ')
		{
			write (1, new, 1);
			ret++;
			new++;
		}
	}
	return (ret);
}*/

int		rostring(char *str)
{
	char	*new;
	int		ret;

	ret = 0;
	if (!(new = malloc(sizeof str)))
		return (0);
	ft_putstr("test 0\n");
	while (*str && (*str != ' ' || *str != '0'))
	{
		str++;
		ft_putstr("test 01\n");
	}
	while ((*str == ' ' || *str == '0') && *str)
	{
		ft_putstr("test 1\n");
		*new = *str;
		str++;
		new++;
		if (*str == '\0')
		{
			ft_putstr("test 2\n");
			ret += ft_putstr(new);
			ret += ft_putstr(str);
		}
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
		rostring(argv[1]);
	return (0);
}

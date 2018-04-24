/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:34:36 by cfarjane          #+#    #+#             */
/*   Updated: 2017/11/22 17:11:31 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len(unsigned int n)
{
	int cmpt;

	cmpt = 0;
	while (n != 0)
	{
		n = n / 10;
		cmpt++;
	}
	return (cmpt);
}

char			*ft_itoa(int n)
{
	int				i;
	char			*str;
	int				s;
	unsigned int	p;
	int				len;

	i = 0;
	s = (n < 0 ? 1 : 0);
	p = (n < 0 ? -(n) : n);
	len = ft_len(p);
	if (!(str = (char*)malloc(sizeof(char) * (len + s + 1 + (n == 0)))))
		return (NULL);
	str[len + s] = '\0';
	str[0] = (s == 1 ? '-' : '0');
	i = len + s - 1;
	while (p > 0)
	{
		str[i] = (p % 10) + '0';
		p = p / 10;
		i--;
	}
	return (str);
}

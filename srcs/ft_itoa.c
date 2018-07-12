/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:34:36 by cfarjane          #+#    #+#             */
/*   Updated: 2018/06/13 16:08:15 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static	int		ft_len(int n)
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

char			*ft_itoa(unsigned long long int n)
{
	int				i;
	char			*str;
	int				s;
	unsigned int	nbr;
	int				len;

	i = 0;
	s = ((long long)n < 0 ? 1 : 0);
	nbr = ((long long)n < 0 ? -(n) : n);
	len = ft_len(nbr);
	if (!(str = (char*)malloc(sizeof(char) * (len + s + 1 + (n == 0)))))
		return (NULL);
	str[len + s] = '\0';
	str[0] = (s == 1 ? '-' : '0');
	i = len + s - 1;
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	return (str);
}

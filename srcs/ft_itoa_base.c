/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:48:01 by cfarjane          #+#    #+#             */
/*   Updated: 2018/05/14 21:15:08 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
** négatif en base 10 à corriger
*/
static int		ft_len(unsigned int n, int base)
{
	int cpt;

	cpt = 0;
	while (n != 0)
	{
		n /= base;
		cpt++;
	}
	return (cpt);
}

char		*ft_itoa_base(int value, int base)
{
	int				i;
	char			*str;
	unsigned int	s;
	int				nbr;
	unsigned int	len;

	i = 0;
	s = (value < 0 ? 1 : 0);
	nbr = (value < 0 ? -(value) : value);
	len = ft_len(nbr, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + s + 1 + (value == 0)))))
		return (NULL);
	str[len + s] = '\0';
	str[0] = (s == 1 ? '-' : '0');
	i = len + s - 1;
	while (value != 0)
	{
		if (value % base > 9)
			str[i] = (value % base) + 55;
		else
			str[i] = (value % base) + 48;
		value /= base;
		i--;
	}
	return (str);
}

/*
**int		main(void)
**{
**	int value;
**	int base;
**
**	value = 21;
**	base = 16;
**	printf("mine : %s\n", ft_itoa_base(value, base));
**	return (0);
**}
*/

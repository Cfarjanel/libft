/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:48:01 by cfarjane          #+#    #+#             */
/*   Updated: 2018/06/13 16:08:12 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		ft_len(long long value, int base)
{
	int cpt;

	cpt = 0;
	while (value != 0)
	{
		value /= base;
		cpt++;
	}
	return (cpt);
}

char			*ft_itoa_base(long long value, int base)
{
	char			*ret;
	long long		len;
	long long		neg;

	if (value == 0)
		return ("0");
	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	neg = ((long long)value < 0 && base == 10 ? 1 : 0);
	value = ((long long)value < 0 ? (value *= - 1) : value);
	len = ft_len(value, base);
	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	ret[len + neg] = '\0';
	while (len-- > 0)
	{
		ret[len + neg] = (value % base) + (value % base > 9 ? 55 : 48);
		value /= base;
	}
	if (neg == 1)
		ret[0] = '-';
	return (ret);
}

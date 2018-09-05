/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:30:37 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:33:34 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_putnbr(long long int n)
{
	unsigned int	nb;
	int				ret;

	ret = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		ret = 11;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
			ret += 1;
		}
		nb = n;
		if (nb < 10)
		{
			ft_putchar(n + '0');
			return (++ret);
		}
		ret += ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
		ret += 1;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:30:37 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 15:06:31 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	cheat_norme(long long int n, int ret, unsigned int nb)
{
	if (nb < 10)
	{
		ft_putchar(n + '0');
		return (++ret);
	}
	else
	{
		ret += ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
		ret += 1;
		return (ret);
	}
}

int			ft_putnbr(long long int n)
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
		ret = cheat_norme(n, ret, nb);
	}
	return (ret);
}

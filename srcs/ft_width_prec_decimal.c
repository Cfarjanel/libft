/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prec_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 18:52:00 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:39:03 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	pre_wp_next(t_flags *f, char *tmp, int len)
{
	int ret;

	ret = 0;
	if (f->width > 0 && f->width > len && (f->pre == 0 ||
			f->pre == -1) && f->minus == 0)
	{
		if (f->pre == -1)
			ret = ft_putnchar(' ', f->width);
		else
			ret = ft_putnchar(' ', ((f->width - (len + f->spe)) - f->plus_c));
	}
	else if (f->width > 0 && f->pre > 0 && f->width > len && f->minus == 0)
	{
		if (*tmp == '-')
			f->width--;
		if (f->pre > len)
			ret = ft_putnchar(' ', (f->width - (len + f->spe)) -
					(f->pre - (len + f->spe)) - f->plus_c);
		else
			ret = ft_putnchar(' ', (f->width - (len + f->spe)) - f->plus_c);
	}
	return (ret);
}

static int	pre_wp(t_flags *f, char *fmt, int nbr, char *tmp)
{
	f->len = (int)ft_strlen(tmp);
	f->plus_c = 0;
	f->spe = 0;
	f->ret = 0;
	f->plus == 1 ? f->plus_c = 1 : 0;
	if (f->hash == 1 || *fmt == 'p')
	{
		if (*fmt == 'x' || *fmt == 'X' || *fmt == 'p')
		{
			if (f->width > f->pre && (f->pre > 0 && f->width > 0))
			{
				f->width -= 2;
				f->len += 2;
			}
			f->pre == 0 && f->width > 0 ? f->len += 2 : 0;
		}
		if ((*fmt == 'o' || *fmt == 'O') && nbr > 0)
		{
			f->spe = 1;
			f->pre > f->width || (f->pre > 0 && f->width == 0) ? f->pre-- : 0;
		}
	}
	f->ret += pre_wp_next(f, tmp, f->len);
	return (f->ret);
}

static int	print_hash(t_flags *f, char *fmt, int nbr, int ret)
{
	if (((*fmt == 'x' && f->hash == 1) || *fmt == 'p') && nbr != 0)
		ret = ft_putstr("0x");
	if (*fmt == 'X' && f->hash == 1)
		ret = ft_putstr("0X");
	return (ret);
}

int			width_prec_decimal(t_flags *f, char *tmp, char *fmt, int nbr)
{
	int len;

	f->neg = 0;
	f->ret = 0;
	len = (int)ft_strlen(tmp);
	if (((f->width > 0 && f->zero == 0) || f->pre > 0))
	{
		f->minus == 0 ? f->ret = pre_wp(f, fmt, nbr, tmp) : 0;
		f->plus == 1 && f->width > 0 && nbr >= 0 ? f->ret += ft_putstr("+") : 0;
		if (f->pre > 0)
		{
			if (*tmp == '-' && f->pre != 0 && *fmt != 'u' && *fmt != 'U')
			{
				ft_putchar(*tmp);
				tmp++;
				f->ret++;
				f->neg = 1;
			}
			f->ret = print_hash(f, fmt, nbr, f->ret);
			f->ret += ft_putnchar('0', (f->pre - len) + f->neg);
		}
		else if (f->pre > 0 && f->minus == 1)
			f->ret += ft_putnchar('0', (f->pre - len + f->neg));
	}
	return (f->ret);
}

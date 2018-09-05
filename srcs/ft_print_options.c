/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:38:35 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:32:55 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	cheat_print_minus(char *str, t_flags *f, int nbr, char *fmt)
{
	f->ret = 0;
	if ((*fmt == 'x' && f->hash == 1) || *fmt == 'p')
		f->len = 2;
	else if (f->hash == 1 && (*fmt == 'o' || *fmt == 'O') &&
			(f->pre == 0 || f->pre == -1))
	{
		f->len += 1;
		f->ret += ft_putstr("0");
	}
	if (f->plus == 1 && (*fmt == 'd' || *fmt == 'D' || *fmt == 'i') &&
			nbr >= 0)
	{
		f->ret += ft_putstr("+");
		f->len = 1;
	}
	if (f->pre > (int)ft_strlen(str) && (*fmt == 'd' || *fmt == 'D'
			|| *fmt == 'i'))
		f->ret += ft_putnchar('0', f->pre - (int)ft_strlen(str));
	(*fmt != 'x' && *fmt != 'p' && f->pre != -1) ?
		(f->ret += ft_putstr(str)) : (f->ret += ft_putstr(ft_strtolower(str)));
	if (f->width > 0 && f->pre == 0)
		f->ret += ft_putnchar(' ', f->width - ((int)ft_strlen(str) + f->len));
	else if (f->pre > 0 || f->width > 0)
		f->ret += ft_putnchar(' ', (f->width - f->pre) - f->len);
	return (f->ret);
}

static int	cheat_zero(t_flags *f, char *fmt, int nbr, char *str)
{
	if (f->pre == -1)
	{
		if (f->hash == 1 && (*fmt == 'o' || *fmt == 'O'))
			nbr == 0 ? f->width += 2 : f->width--;
		if (f->hash == 1 && (*fmt == 'x' || *fmt == 'X'))
			nbr == 0 ? f->width += 3 : 0;
		f->ret = ft_putnchar(' ', f->width - (int)ft_strlen(str));
	}
	if (f->hash == 1 && (*fmt == 'x' || *fmt == 'X') && nbr != 0)
		*fmt == 'x' ? (f->ret += ft_putstr("0x")) : (f->ret +=
				ft_putstr("0X"));
	return (f->ret);
}

static int	micro_norme(char *str, t_flags *f, char *fmt)
{
	if (*str == '-' && *fmt != 'u' && *fmt != 'U')
	{
		ft_putchar('-');
		f->neg = 1;
	}
	return (f->neg);
}

int			print_zero_decimal(char *str, t_flags *f, int nbr, char *fmt)
{
	f->neg = 0;
	f->ret = 0;
	f->plus_c = 0;
	if (f->zero == 1 && (f->pre == 0 || f->pre == -1))
	{
		if (f->plus == 1 && nbr >= 0)
		{
			f->plus_c = 1;
			f->ret += ft_putstr("+");
		}
		f->hash == 1 && *fmt == 'x' ? f->width -= 2 : 0;
		if (f->zero == 1 && (f->pre == 0 || f->pre == -1))
		{
			f->ret = cheat_zero(f, fmt, nbr, str);
			if (f->pre == 0)
			{
				f->neg = micro_norme(str, f, fmt);
				f->neg == 1 ? str++ : 0;
				f->ret += ft_putnchar('0', (f->width - ((int)ft_strlen(str)) -
						(f->neg + f->plus_c)));
			}
		}
	}
	return (f->ret + f->neg);
}

int			print_minus(char *str, t_flags *f, int nbr, char *fmt)
{
	int ret;

	ret = 0;
	f->len = 0;
	if (f->minus == 1)
		ret = cheat_print_minus(str, f, nbr, fmt);
	return (ret);
}

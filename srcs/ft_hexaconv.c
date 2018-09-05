/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:05:41 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:29:57 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		hexa_final(char *fmt, char *s, t_flags *f, uintmax_t n)
{
	int ret;

	ret = 0;
	if (*fmt == 'x' || *fmt == 'p')
	{
		if (f->minus == 1)
			ret = print_minus(s, f, 0, fmt);
		else
		{
			if (f->pre != -1 || n > 0)
				ret = ft_print_unsigned(n, 16, 0);
		}
	}
	else if (*fmt == 'X')
	{
		if (f->minus == 1)
		{
			ret = print_minus(s, f, 0, fmt);
			f->hash == 1 ? f->ret -= 2 : 0;
		}
		else
			f->pre != -1 || n > 0 ? (ret = ft_print_unsigned(n, 16, 1)) : 0;
	}
	return (ret);
}

static int		norme_hexa(t_flags *f, char *format, int hexa, int ret)
{
	f->x = "0x";
	if ((hexa != 0 || *format == 'p') && (f->pre == 0 ||
			f->pre == -1) && f->zero == 0)
		ret = ft_putstr(f->x);
	return (ret);
}

uintmax_t		ft_hexaconv(char *format, va_list ap, t_flags *f)
{
	uintmax_t	hexa;

	hexa = 0;
	if (*format == 'x' || *format == 'p' || *format == 'X')
	{
		if (f->length == 0 && *format != 'p')
			hexa = va_arg(ap, unsigned int);
		else if (f->length == 1 || *format == 'p')
			hexa = va_arg(ap, unsigned long);
		else if (f->length == 2)
			hexa = va_arg(ap, unsigned long long);
		else if (f->length == 3)
			hexa = (unsigned short)va_arg(ap, int);
		else if (f->length == 4)
			hexa = (unsigned char)va_arg(ap, int);
		else if (f->length == 5)
			hexa = va_arg(ap, uintmax_t);
		else if (f->length == 6)
			hexa = va_arg(ap, size_t);
	}
	return (hexa);
}

int				ft_print_hexa(char *format, va_list ap, t_flags *f)
{
	uintmax_t	hexa;
	int			ret;

	f->bigx = "0X";
	ret = 0;
	f->cheat = 0;
	hexa = ft_hexaconv(format, ap, f);
	f->tmp = ft_itoa_base(hexa, 16);
	if (f->hash == 0 && *format != 'p')
		f->cheat += width_prec_decimal(f, f->tmp, format, hexa);
	if ((f->hash == 1 && *format == 'x') || *format == 'p')
	{
		f->cheat += width_prec_decimal(f, f->tmp, format, hexa);
		ret = norme_hexa(f, format, hexa, ret);
	}
	else if (f->hash == 1 && *format == 'X')
	{
		f->cheat += width_prec_decimal(f, f->tmp, format, 0);
		if (hexa != 0 && (f->pre == 0 || f->pre == -1))
			ret = ft_putstr(f->bigx);
	}
	f->zero == 1 ? (ret = print_zero_decimal(f->tmp, f, hexa, format)) : 0;
	ret += hexa_final(format, f->tmp, f, hexa);
	free(f->tmp);
	return (ret + f->cheat);
}

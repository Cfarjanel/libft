/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ouconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:05:16 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:32:48 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					ft_print_unsigned(unsigned long long v, int base, int maj)
{
	const char	basestr[17] = "0123456789abcdef";
	const char	basestrmaj[17] = "0123456789ABCDEF";
	int			ret;

	ret = 0;
	if ((v / base) > 0)
		ret += ft_print_unsigned(v / base, base, maj);
	ft_putchar((maj) ? basestrmaj[(v % base)] : basestr[(v % base)]);
	return (++ret);
}

static int			ft_unsigned(uintmax_t n, t_flags *f, int ret, char *fmt)
{
	char *str;

	if ((*fmt == 'u' || *fmt == 'U') && (f->pre != -1 || n != 0))
	{
		str = ft_itoa_base(n, 10);
		if (f->minus == 0)
		{
			ret = print_zero_decimal(str, f, n, fmt);
			if (f->width > 0 || f->pre > 0)
				ret += width_prec_decimal(f, str, fmt, n);
			if (f->pre != -1 || n != 0)
				ret += ft_print_unsigned(n, 10, 0);
		}
		else
			ret += print_minus(str, f, 0, fmt);
		free(str);
	}
	return (ret);
}

unsigned long long	ft_ouconv(char *format, va_list ap, t_flags *flag)
{
	unsigned long long ret;

	ret = 0;
	if (*format == 'O' || *format == 'U')
		flag->length = 1;
	if (*format == 'o' || *format == 'u' || *format == 'O' || *format == 'U')
	{
		if (flag->length == 0)
			ret = va_arg(ap, unsigned int);
		if (flag->length == 1)
			ret = va_arg(ap, unsigned long);
		if (flag->length == 2)
			ret = (uintmax_t)va_arg(ap, unsigned long long);
		if (flag->length == 3)
			ret = (unsigned short)va_arg(ap, unsigned int);
		if (flag->length == 4)
			ret = (unsigned char)va_arg(ap, unsigned int);
		if (flag->length == 5)
			ret = va_arg(ap, uintmax_t);
		if (flag->length == 6)
			ret = va_arg(ap, size_t);
	}
	return (ret);
}

int					ft_print_octal(char *format, va_list ap, t_flags *f)
{
	unsigned long long	nbr;
	int					ret;
	char				*tmp;

	ret = 0;
	nbr = ft_ouconv(format, ap, f);
	if (*format == 'o' || *format == 'O')
	{
		tmp = ft_itoa_base(nbr, 8);
		if (f->width > 0 || f->pre > 0)
			ret += width_prec_decimal(f, tmp, format, nbr);
		ret += print_zero_decimal(tmp, f, nbr, format);
		if (f->hash == 1 && (nbr > 0 || f->pre == -1)
				&& (f->zero == 0 || f->pre == -1) && f->minus == 0)
			ret += ft_putstr("0");
		if (f->minus == 1)
			ret += print_minus(tmp, f, 0, format);
		else
			f->pre != -1 || nbr != 0 ? (ret += ft_print_unsigned(nbr, 8, 0))
				: 0;
		free(tmp);
	}
	ret = ft_unsigned(nbr, f, ret, format);
	return (ret);
}

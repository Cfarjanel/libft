/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 20:01:45 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:29:44 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static long long	ft_diconv(char *format, va_list ap, t_flags *f)
{
	long long	ret;

	ret = 0;
	if (*format == 'D')
		f->length = 1;
	if (*format == 'd' || *format == 'i' || *format == 'D')
	{
		if (f->length == 0)
			ret = (long)va_arg(ap, int);
		if (f->length == 1)
			ret = va_arg(ap, long);
		if (f->length == 2)
			ret = va_arg(ap, long long);
		if (f->length == 3)
			ret = (short)va_arg(ap, int);
		if (f->length == 4)
			ret = (signed char)va_arg(ap, int);
		if (f->length == 5)
			ret = va_arg(ap, intmax_t);
		if (f->length == 6)
			ret = va_arg(ap, size_t);
	}
	return (ret);
}

static int			print_dec_next(int nbr, t_flags *f, char *format, char *tmp)
{
	int ret;

	ret = 0;
	if (nbr >= 0 && f->plus == 1 && f->width == 0)
	{
		ft_putchar('+');
		ret++;
	}
	free(tmp);
	ret += width_prec_decimal(f, tmp, format, nbr);
	ret += print_zero_decimal(tmp, f, nbr, format);
	if (nbr >= 0 && f->plus != 1 && f->space == 1 && f->width == 0
			&& (f->pre == 0 || f->pre == -1))
	{
		ft_putchar(' ');
		ret++;
	}
	return (ret);
}

int					ft_print_decimal(char *format, va_list ap, t_flags *f)
{
	long long	nbr;
	int			ret;
	char		*tmp;

	ret = 0;
	nbr = ft_diconv(format, ap, f);
	tmp = ft_itoa_base(nbr, 10);
	if (f->minus == 0)
	{
		ret += print_dec_next(nbr, f, format, tmp);
		(f->pre > 0 || f->zero > 0) && nbr < 0 ? tmp++ : 0;
		f->pre != -1 || nbr != 0 ? (ret += ft_putstr(tmp)) : 0;
	}
	else
	{
		ret += print_minus(tmp, f, nbr, format);
		free(tmp);
	}
	return (ret);
}

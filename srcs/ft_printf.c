/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:02:15 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:33:02 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		initialise_flags(t_flags *flag)
{
	flag->zero = 0;
	flag->plus = 0;
	flag->minus = 0;
	flag->hash = 0;
	flag->space = 0;
	flag->pre = 0;
	flag->width = 0;
	flag->length = 0;
}

static int		ft_percent(char *format, t_flags *flag)
{
	int ret;

	ret = 0;
	if (*format == '%')
	{
		if (flag->minus == 0)
		{
			ret += width_char(flag, ret);
			if (ft_isflag(*format) && *(format + 1) == '%')
			{
				ft_putchar('%');
				ret++;
			}
			ft_putchar('%');
			ret++;
		}
		else
			ret = print_minus_char('%', flag, ret);
	}
	return (ret);
}

int				print_conversion(char *fmt, va_list ap, t_flags *flag)
{
	int	ret;

	ret = 0;
	if (*fmt == 'd' || *fmt == 'i' || *fmt == 'D')
		ret = ft_print_decimal(fmt, ap, flag);
	else if (*fmt == 'o' || *fmt == 'O' || *fmt == 'u' || *fmt == 'U')
		ret = ft_print_octal(fmt, ap, flag);
	else if (*fmt == 'x' || *fmt == 'X' || *fmt == 'p')
		ret = ft_print_hexa(fmt, ap, flag);
	else if (*fmt == 'c' || *fmt == 'C')
	{
		ret = ft_cconv(fmt, ap, flag);
		if (ret == -1)
			exit(0);
	}
	else if (*fmt == 's' || *fmt == 'S')
		ret = ft_sconv(fmt, ap, flag);
	else if (!ft_isconv(*fmt) && *fmt != '%')
		exit(0);
	return (ret);
}

int				ft_final_print(char **format, va_list ap)
{
	t_flags	flag;
	int		ret;

	ret = 0;
	if (*format)
	{
		initialise_flags(&flag);
		if (ft_isflag(**format))
		{
			check_flags(format, &flag);
			check_length(format, &flag);
			check_width(format, &flag);
			check_precision(format, &flag);
		}
		ret += ft_percent(*format, &flag);
		ret += print_conversion(*format, ap, &flag);
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_ret		ret;

	va_start(ap, format);
	ret.written = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			ret.written += 1;
		}
		if (*format == '%')
		{
			format++;
			ret.written += ft_final_print((char**)&format, ap);
		}
		format++;
	}
	va_end(ap);
	return (ret.written);
}

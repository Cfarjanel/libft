/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cconv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:12:08 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:29:34 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_cconv_next(int ret, t_flags *flag, va_list ap)
{
	ret = print_zero_char(flag, ret);
	if (flag->minus == 1)
		ret = print_minus_char((char)va_arg(ap, int), flag, ret);
	else
	{
		ft_putchar((char)va_arg(ap, int));
		ret++;
	}
	return (ret);
}

int			print_minus_wchar(wchar_t wc, t_flags *flag)
{
	int ret;

	ret = 0;
	ft_putwchar(wc);
	if (flag->minus == 1 && flag->width > 0)
		ft_putnchar(' ', flag->width - ft_wcharlen(wc));
	else
		ret = 1;
	if (flag->width > ft_wcharlen(wc))
		ret += flag->width;
	else
		ret += ft_wcharlen(wc);
	return (ret);
}

int			print_minus_char(char c, t_flags *flag, int ret)
{
	ft_putchar(c);
	if (flag->minus == 1 && flag->width > 0)
	{
		ret++;
		ret += ft_putnchar(' ', flag->width - 1);
	}
	else
		ret = 1;
	return (ret);
}

int			width_char(t_flags *flag, int ret)
{
	if (flag->width > 1 && flag->minus == 0)
	{
		if (flag->zero == 0 && flag->pre == 0)
		{
			ft_putnchar(' ', flag->width - 1);
			ret += (flag->width - 1);
		}
		else
			ret += print_zero_char(flag, ret);
	}
	return (ret);
}

int			ft_cconv(char *format, va_list ap, t_flags *flag)
{
	wchar_t		wchar;
	int			ret;

	ret = 0;
	wchar = 0;
	ret += width_char(flag, ret);
	if (flag->length == 0 && *format == 'c')
		ret = ft_cconv_next(ret, flag, ap);
	else if ((flag->length == 1 && *format == 'c') || *format == 'C')
	{
		wchar = va_arg(ap, wchar_t);
		ret = print_zero_char(flag, ret);
		if (flag->minus == 1)
			ret += print_minus_wchar(wchar, flag);
		else
		{
			if (wchar < 0 || (wchar > 55295 && wchar < 57344) || wchar >
					1114111)
				ret = -1;
			else
				ret += ft_putwchar(wchar);
		}
	}
	return (ret);
}

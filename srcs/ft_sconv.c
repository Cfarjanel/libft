/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sconv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:04:53 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:34:52 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		cheat_width_str(t_flags *f, int len, char *str, int ret)
{
	if (f->width < len)
	{
		ft_putnchar(' ', f->width - len);
		if (f->pre != -1)
			ret = ft_putstr(str);
	}
	else
	{
		ft_putnchar(' ', f->width - len);
		ret = (f->width - len) + ft_putstr(str);
	}
	return (ret);
}

static int		wdpc_next(t_flags *flag, char *str, int ret)
{
	int		len;

	len = (int)ft_strlen(str);
	if (flag->pre >= len)
	{
		if (flag->width > 0 && flag->minus == 0)
			ret += ft_putnchar(' ', flag->width - len);
		if (flag->pre != -1)
			ret += ft_putstr(str);
	}
	else
	{
		if (flag->width > 0 && flag->minus == 0)
			ret += ft_putnchar(' ', flag->width - flag->pre);
	}
	if (flag->pre < len && flag->pre > 0)
		ret += ft_putnstr(str, flag->pre);
	if (flag->minus == 1)
		ret = minus_str(flag, str, ret);
	return (ret);
}

static int		width_prec_str(t_flags *f, char *str, int ret)
{
	int	len;

	len = (int)ft_strlen(str);
	if (f->zero == 1 && f->width > 0)
		ret += ft_putnchar('0', f->width - len) + ft_putstr(str);
	else if (f->zero == 0 && f->width > 0 && f->pre == 0 && f->minus == 0)
		ret += cheat_width_str(f, len, str, ret);
	else if (f->width > 0 && (f->pre == 0 || f->pre == -1))
	{
		if (f->minus == 0 || f->pre == -1)
		{
			ret += ft_putnchar(' ', f->width);
			if (f->pre != -1)
				ret += ft_putstr(str);
		}
		else
			ret += minus_str(f, str, ret);
	}
	else if (f->pre > 0)
		ret = wdpc_next(f, str, ret);
	else if (f->pre > 0 && f->width > 0 && f->width > len)
		f->pre > len ? ft_putnchar(' ', (f->width - len) - \
			(f->pre - len)) : ft_putnchar(' ', f->width - len);
	return (ret);
}

static int		ft_bigs(t_flags *flag, int ret, va_list ap)
{
	wchar_t		*wstr;
	wchar_t		*tmp;

	wstr = va_arg(ap, wchar_t*);
	tmp = wstr;
	while (*tmp)
	{
		if (*tmp < 0 || (*tmp > 55295 && *tmp < 57344) ||
				*tmp > 1114111 || *tmp == 49150)
			return (-1);
		tmp++;
	}
	if (flag->pre > 0 || flag->width > 0)
		ret += width_prec_wstr(flag, wstr, ret);
	else if (wstr == NULL && flag->pre != -1)
		ret = ft_putstr("(null)");
	else
	{
		if (flag->pre != -1)
		{
			ret += ft_wstrlen(wstr);
			ft_putwstr(wstr);
		}
	}
	return (ret);
}

int				ft_sconv(char *format, va_list ap, t_flags *f)
{
	char	*str;
	int		ret;

	ret = 0;
	if (*format == 's' && f->length == 0)
	{
		str = va_arg(ap, char*);
		if (str == NULL)
			str = "(null)";
		if (f->minus == 0)
		{
			if (f->pre > 0 || f->width > 0)
				(ret += width_prec_str(f, str, ret));
			else
			{
				if (f->pre != -1)
					ret = ft_putstr(str);
			}
		}
		else
			ret = width_prec_str(f, str, ret);
	}
	else if ((*format == 's' && f->length == 1) || *format == 'S')
		ret += ft_bigs(f, ret, ap);
	return (ret);
}

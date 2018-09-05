/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wp_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:04:41 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 15:11:53 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	cheat_norme(int ret, t_flags *f, wchar_t *str)
{
	ret += ft_putnchar(' ', f->width);
	if (f->pre != -1)
	{
		ft_putwstr(str);
		ret += ft_wstrlen(str);
	}
	return (ret);
}

int			cheat_width_wstr(t_flags *f, int len, wchar_t *str, int ret)
{
	if (f->width < len)
	{
		ft_putnchar(' ', f->width - len);
		if (f->pre != -1)
		{
			ret = len;
			ft_putwstr(str);
		}
	}
	else
	{
		ft_putnchar(' ', f->width - len);
		ret = (f->width - len) + len;
		ft_putwstr(str);
	}
	return (ret);
}

int			wwdpc_next(t_flags *flag, wchar_t *str, int ret)
{
	int		len;

	len = ft_wstrlen(str);
	if (flag->pre >= len)
	{
		if (flag->width > 0 && flag->minus == 0)
			ret += ft_putnchar(' ', flag->width - len);
		if (flag->pre != -1)
		{
			ft_putwstr(str);
			ret += ft_wstrlen(str);
		}
	}
	else
	{
		if (flag->width > 0 && flag->minus == 0)
			ret += ft_putnchar(' ', flag->width - flag->pre);
	}
	if (flag->pre < len && flag->pre > 0)
		ret += ft_putnstr((char*)str, flag->pre);
	if (flag->minus == 1)
		ret = minus_wstr(flag, str, ret);
	return (ret);
}

int			width_prec_wstr(t_flags *f, wchar_t *str, int ret)
{
	int	len;

	len = ft_wstrlen(str);
	if (f->zero == 1 && f->width > 0)
	{
		ret += ft_putnchar('0', f->width - len) + len;
		ft_putwstr(str);
	}
	else if (f->zero == 0 && f->width > 0 && f->pre == 0 && f->minus == 0)
		ret += cheat_width_wstr(f, len, str, ret);
	else if (f->width > 0 && (f->pre == 0 || f->pre == -1))
	{
		if (f->minus == 0 || f->pre == -1)
			ret = cheat_norme(ret, f, str);
		else
			ret += minus_wstr(f, str, ret);
	}
	else if (f->pre > 0)
		ret = wwdpc_next(f, str, ret);
	else if (f->pre > 0 && f->width > 0 && f->width > len)
		f->pre > len ? ft_putnchar(' ', (f->width - len) - \
				(f->pre - len)) : ft_putnchar(' ', f->width - len);
	return (ret);
}

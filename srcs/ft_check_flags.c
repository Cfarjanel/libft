/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:50:06 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:29:25 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		check_flags(char **format, t_flags *flag)
{
	while (**format == '0' || **format == '+' || **format == '-' ||
			**format == '#' || **format == ' ')
	{
		if (**format == '0')
			flag->zero = 1;
		if (**format == '+')
			flag->plus = 1;
		if (**format == '-')
			flag->minus = 1;
		if (**format == '#')
			flag->hash = 1;
		if (**format == ' ')
			flag->space = 1;
		(*format)++;
	}
	if (flag->minus == 1 || flag->space == 1)
		flag->zero = 0;
	if (flag->plus == 1)
		flag->space = 0;
}

void		check_length(char **format, t_flags *flag)
{
	while (**format == 'l' || **format == 'h' || **format == 'j' ||
			**format == 'z')
	{
		if (**format == 'l')
			flag->length = 1;
		if (**format == 'h')
			flag->length = 3;
		if (**format == 'j')
			flag->length = 5;
		if (**format == 'z')
			flag->length = 6;
		if (flag->length == 1 && *(*format + 1) == 'l')
		{
			flag->length = 2;
			(*format)++;
		}
		if (flag->length == 3 && *(*format + 1) == 'h')
		{
			flag->length = 4;
			(*format)++;
		}
		(*format)++;
	}
}

void		check_width(char **format, t_flags *flag)
{
	if (ft_isdigit(**format) && **format != '0')
	{
		if (ft_isdigit(**format))
			flag->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			*format = *format + 1;
	}
}

void		check_precision(char **format, t_flags *flag)
{
	if (**format == '.')
	{
		(*format)++;
		if ((**format == '0') || ft_isconv(**format))
			flag->pre = -1;
		else if (ft_isdigit(**format))
			flag->pre = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

int			ft_islength(char c)
{
	return (c == 'l' || c == 'h' || c == 'j' || c == 'z');
}

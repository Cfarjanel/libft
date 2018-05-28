/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:47:19 by cfarjane          #+#    #+#             */
/*   Updated: 2018/05/28 13:05:37 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_putwchar(wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
		return (2);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
		return (3);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
		return (4);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:54:38 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/05 14:55:06 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_wstrlen(wchar_t *wstr)
{
	int		len;
	int		ret;

	ret = 0;
	len = 0;
	if (wstr)
	{
		while (wstr[len])
		{
			if (wstr[len] <= 0x7F)
				ret += 1;
			else if (wstr[len] <= 0x7FF)
				ret += 2;
			else if (wstr[len] <= 0xFFFF)
				ret += 3;
			else if (wstr[len] <= 0x10FFFF)
				ret += 4;
			len++;
		}
	}
	return (ret);
}

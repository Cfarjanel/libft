/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:15:32 by cfarjane          #+#    #+#             */
/*   Updated: 2017/11/21 13:51:49 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (n > i)
	{
		if ((unsigned char)c == ((unsigned char*)str)[i])
			return ((void*)&(str[i]));
		i++;
	}
	return (NULL);
}

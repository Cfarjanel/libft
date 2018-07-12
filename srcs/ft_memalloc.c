/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:59:42 by cfarjane          #+#    #+#             */
/*   Updated: 2018/06/04 18:47:19 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if ((str = malloc(size)))
	{
		ft_bzero(str, size);
		return (str);
	}
	return (NULL);
}

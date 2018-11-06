/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubletabfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:43:09 by cfarjane          #+#    #+#             */
/*   Updated: 2018/11/06 20:43:16 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	free_double_tab(void **tab, int x)
{
	int i;

	i = 0;
	while (tab && i < x)
	{
		ft_memdel(&(tab[i]));
		i++;
	}
	free(tab);
	tab = NULL;
}

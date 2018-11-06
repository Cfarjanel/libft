/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubletabfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:40:03 by cfarjane          #+#    #+#             */
/*   Updated: 2018/11/06 14:40:20 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void        free_double_tab(void **tab, int x)
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

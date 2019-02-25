/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_leaks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:24:21 by cfarjane          #+#    #+#             */
/*   Updated: 2019/02/25 17:26:15 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_check_leaks(char *path)
{
	ft_putendl(path);
	system("leaks lem_in | grep 'total leaked bytes'");
}

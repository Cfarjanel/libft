/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:02:07 by cfarjane          #+#    #+#             */
/*   Updated: 2018/11/26 19:33:31 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strccpy(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i] != c && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = str[i];
	new[i + 1] = '\0';
	return (new);
}

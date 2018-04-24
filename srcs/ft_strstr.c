/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:48:27 by cfarjane          #+#    #+#             */
/*   Updated: 2017/12/01 23:26:37 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*s;
	char	*n;

	s = (char*)str;
	n = (char*)needle;
	i = 0;
	if (n[0] == '\0')
		return (s);
	while (s[i])
	{
		j = 0;
		while (s[i + j] == n[j] && n[j])
			j++;
		if (n[j] == '\0')
			return (s + i);
		i++;
	}
	return (NULL);
}

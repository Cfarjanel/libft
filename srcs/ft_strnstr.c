/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:43:00 by cfarjane          #+#    #+#             */
/*   Updated: 2017/12/03 12:11:46 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
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
		while (s[i + j] == n[j] && n[j] && (i + j) < len)
		{
			if (n[j + 1] == '\0')
				return (s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:33:27 by cfarjane          #+#    #+#             */
/*   Updated: 2017/12/05 18:15:41 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char const *s)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > 0)
		j--;
	if ((j - i) <= 0)
		return (0);
	return (j - i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*s2;
	int		l;

	if (!s)
		return (NULL);
	l = len(s) + 1;
	if (!(s2 = ft_strnew(len(s))))
		return (NULL);
	i = 0;
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	while (i < l)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:30:45 by cfarjane          #+#    #+#             */
/*   Updated: 2017/12/05 18:16:23 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cpt_wrds(const char *str, char c)
{
	int	i;
	int	cpt;
	int	wrd;

	i = 0;
	wrd = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] != c && str[i])
		{
			cpt = 1;
			i++;
		}
		if (str[i] == c && str[i])
		{
			(cpt == 1) ? wrd++ : 0;
			cpt = 0;
			i++;
		}
	}
	return (wrd + 1);
}

static int		cpt_ltr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	if (!str || !(tab = (char**)malloc(sizeof(char*) * (cpt_wrds(str, c) + 1))))
		return (NULL);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if (!(tab[j] = (char*)malloc(cpt_ltr(&(str[i]), c) + 1)))
				return (NULL);
			while (str[i] != c && str[i])
				tab[j][k++] = str[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}

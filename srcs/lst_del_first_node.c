/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_first_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:50:49 by cfarjane          #+#    #+#             */
/*   Updated: 2019/03/25 13:54:34 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lst_del_first_node(t_list **head)
{
	t_get_paths	*del;

	if (*head != NULL && (*head)->next != NULL)
	{
		del = *head;
		*head = (*(head))->next;
		free(del->content);
		free(del->content_size);
		free(del);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_last_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:45:36 by cfarjane          #+#    #+#             */
/*   Updated: 2019/03/25 13:54:58 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			del_last_node(t_list *head)
{
	t_list	*del;
 	t_list	*prev;

 	del = head;
 	prev = head;
 	while (del->next != NULL)
 	{
 		prev = del;
 		del = del->next;
 	}
 	if (del == head)
 		head = NULL;
 	else
 		prev->next = NULL;
	free(del->content);
	free(del->content_size);
 	free(del);
}

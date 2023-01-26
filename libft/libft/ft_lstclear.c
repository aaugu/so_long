/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:47:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:57:05 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Deletes and frees the given node and every successor of that node, using the
function ’del’ and free(3). Finally, the pointer to the list must be set to
NULL.

lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = temp;
	}
}

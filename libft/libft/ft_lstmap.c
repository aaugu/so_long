/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:48:33 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:57:26 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of each
node. Creates a new list resulting of the successive applications of the
function ’f’. The ’del’ function is used to delete the content of a node if
needed.

lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
del: The address of the function used to delete the content of a node if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_list;

	if (!lst || !f || !del)
		return (0);
	new_list = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, new);
		lst = lst->next;
	}
	return (new_list);
}

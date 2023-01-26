/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:48:39 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/26 10:57:29 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Allocates (with malloc(3)) and returns a new node. The member variable ’content’
is initialized with the value of the parameter ’content’. The variable ’next’ is
initialized to NULL. Returns the new node.

content: The content to create the node with.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (!lstnew)
		return (0);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}

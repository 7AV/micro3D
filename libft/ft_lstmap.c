/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:55:12 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/04 17:34:07 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  The adress of a pointer to an element.
**	#2.  The adress of the function used to iterate on the list.
**	#3.  The adress of the function used to delete the content of an element
**	if needed.
**
** Return value
** 	The new list.  NULL if the allocation fails.
**
** Description
** 	Iterates the list ’lst’ and applies the function ’f’ to the content of
**	each element.  Creates a new list resulting of the successive applications
**	of the function ’f’.  The ’del’ function is used to delete the content
**	of an element if needed.
*/
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*elem;

	list = NULL;
	if ((!lst) || (!f))
		return (NULL);
	while (lst)
	{
		if (!(elem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, elem);
		lst = lst->next;
	}
	return (list);
}

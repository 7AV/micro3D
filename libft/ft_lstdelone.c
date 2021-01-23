/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:22:48 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/04 16:20:08 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  The element to free.
**	#2.  The address of the function used to delete the content.
**
** Description
** 	Takes as a parameter an element and frees the memory of the element’s
**	content using the function ’del’ given as a parameter and free the element.
**	The memory of ’next’ must not be freed.
*/
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

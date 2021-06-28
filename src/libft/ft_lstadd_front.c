/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:29:48 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/04 14:41:21 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  The address of a pointer to the first link of a list.
**	#2.  The address of a pointer to the element to be added to the list.
**
** Description
** 	Adds the element ’new’ at the beginning of the list.
*/
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((!lst) || (!new))
		return ;
	new->next = *lst;
	*lst = new;
}

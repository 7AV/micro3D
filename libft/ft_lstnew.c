/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:05:24 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/04 14:27:57 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  The content to create the new element with.
**
** Return value
** 	The new element.
**
** Description
** 	Allocates (with malloc(3)) and returns a new element. The variable
**	’content’ is initialized with the value of the parameter ’content’.
**	The variable ’next’ is initialized to NULL.
*/
#include "libft.h"

t_list				*ft_lstnew(void *content)
{
	struct s_list	*new;

	if (!(new = (struct s_list*)ft_calloc(2, sizeof(struct s_list))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

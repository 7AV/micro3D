/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:58:44 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:15:12 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  The prefix string.
**	#2.  The suffix string.
**
** Return value
** 	The new string.  NULL if the allocation fails.
**
** Description
** 	Allocates (with malloc(3)) and returns a new string, which is the result
** 	of the concatenation of ’s1’ and ’s2’.
*/
#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*dst;

	if ((!s1) || (!s2))
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	if (!(dst = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char))))
		return (NULL);
	ft_strlcat(dst, s1, len_s1 + 1);
	ft_strlcat(dst + len_s1, s2, len_s2 + 1);
	return (dst);
}

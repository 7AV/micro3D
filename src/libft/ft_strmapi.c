/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:12:03 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:19:57 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  The string on which to iterate.
**	#2.  The function to apply to each character.
**
** Return value
** 	The string created from the successive applications of ’f’.  Returns NULL
**	if the allocation fails.
**
** Description
** 	Applies the function ’f’ to each character of the string ’s’ to create a
**	new string (with malloc(3)) resulting from successive applications of ’f’.
*/
#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*dst;

	if ((!s) || (!f))
		return (NULL);
	if (!(dst = (char *)ft_calloc(ft_strlen((char *)s) + 1, sizeof(char))))
		return (NULL);
	index = 0;
	while (s[index])
	{
		dst[index] = f(index, s[index]);
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

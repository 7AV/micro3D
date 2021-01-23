/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:22:17 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:15:33 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  The string from which to create the substring.
** 	#2.  The start index of the substring in the string ’s’.
** 	#3.  The maximum length of the substring.
**
** Return value
** 	The substring.  NULL if the allocation fails.
**
** Description
** 	Allocates (with malloc(3)) and returns a substring from the string ’s’.
**	The substring begins at index ’start’ and is of maximum size ’len’.
*/
#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	len_s;
	unsigned int	index;
	char			*dst;

	if (!s)
		return (NULL);
	len_s = ft_strlen((char *)s);
	if (start > len_s)
		return (ft_calloc(1, sizeof(s)));
	if (len_s < start + len)
		len = len_s - start;
	if (!(dst = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	index = 0;
	while (index < len)
	{
		dst[index] = s[start];
		index++;
		start++;
	}
	dst[index] = '\0';
	return (dst);
}

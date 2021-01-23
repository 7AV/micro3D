/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:36:11 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:23:17 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The memccpy() function copies bytes from string src to string dst.
** 	If the character c (as converted to an unsigned char) occurs in the string
** 	src, the copy stops and a pointer to the byte after the copy of c in the
** 	string dst is returned. Otherwise, n bytes are copied, and a NULL pointer
** 	is returned.
**
** 	The source and destination strings should not overlap, as the behavior
** 	is undefined.
*/
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src;
		if (*(unsigned char *)src++ == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}

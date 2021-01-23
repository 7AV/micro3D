/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:01:25 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:17:24 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The strlcpy() and strlcat() functions copy and concatenate strings with
**	the same input parameters and output result as snprintf(3). They are
**	designed to be safer, more consistent, and less error prone replacements
**	for the easily misused functions strncpy(3) and strncat(3).
*/
#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	index;

	if (!dest)
		return (0);
	index = 0;
	if (!dstsize)
		return (ft_strlen((char *)src));
	if (dest > src)
		while (src[index] && index < dstsize - 1)
		{
			dest[index] = src[index];
			index++;
		}
	dest[index] = '\0';
	return (ft_strlen((char *)src));
}

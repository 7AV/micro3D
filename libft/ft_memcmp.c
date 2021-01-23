/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:02:56 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/01 17:19:28 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The memcmp() function compares byte string s1 against byte string s2.
** 	Both strings are assumed to be n bytes long.
**
** RETURN VALUES
** 	The memcmp() function returns zero if the two strings are identical,
** 	otherwise returns the difference between the first two differing bytes
** 	(treated as unsigned char values, so that `\200' is greater than `\0',
** 	for example).  Zero-length strings are always identical. This behavior
** 	is not required by C and portable code should only depend on the sign
** 	of the returned value.
*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while ((*(unsigned char *)s1 == *(unsigned char *)s2) && (n - 1))
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

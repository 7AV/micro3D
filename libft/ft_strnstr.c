/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:18:04 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/06 10:48:02 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The strnstr() function locates the first occurrence of the null-terminated
**	string needle in the string haystack, where not more than len characters
**	are searched.  Characters that appear after a `\0' character are not
**	searched.
*/
#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == *s2)
		{
			while ((s1[i + j] == s2[j]) &&
			(s2[j] != '\0') &&
			(i + j < len))
			{
				if (s2[j + 1] == '\0')
					return ((char *)(s1 + i));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

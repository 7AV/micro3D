/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:41:00 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:19:25 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The strchr() function locates the first occurrence of c (converted
**	to a char) in the string pointed to by s.  The terminating null character
**	is considered to be part of the string; therefore if c is `\0', the
**	functions locate the terminating `\0'.
**
** The strrchr() function is identical to strchr(), except it locates the
** 	last occurrence of c.
**
** RETURN VALUES
** 	The functions strchr() and strrchr() return a pointer to the located
**	character, or NULL if the character does not appear in the string.
*/
#include "libft.h"

char	*ft_strrchr(char *str, int a)
{
	int index;

	if ((char)a == '\0')
		return ((char *)str + ft_strlen(str));
	index = ft_strlen(str);
	while (index >= 0)
	{
		if (*(str + index) == a)
			return ((char *)(str + index));
		index--;
	}
	return (NULL);
}

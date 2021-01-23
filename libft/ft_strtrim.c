/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:14:32 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/15 22:50:50 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  The string to be trimmed.
**	#2.  The reference set of characters to trim.
**
** Return value
** 	The trimmed string.  NULL if the allocation fails.
**
** Description
** 	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
**	specified in ’set’ removed from the beginning and the end of the string.
*/
#include "libft.h"

static int			ft_pnta(const char *s, char *set)
{
	unsigned int	len_s;
	unsigned int	index;

	len_s = ft_strlen((char *)s);
	index = 0;
	while (index < len_s)
	{
		if (ft_strchr(set, s[index]) == 0)
			break ;
		index++;
	}
	return (index);
}

static int			ft_pntb(const char *s, char *set)
{
	unsigned int	len_s;
	unsigned int	index;

	len_s = ft_strlen((char *)s);
	index = 0;
	while (index < len_s)
	{
		if (ft_strchr(set, s[len_s - index - 1]) == 0)
			break ;
		index++;
	}
	return (len_s - index);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	pnt_a;
	unsigned int	pnt_b;
	char			*dst;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	pnt_a = ft_pnta(s1, (char *)set);
	pnt_b = ft_pntb(s1, (char *)set);
	if (pnt_a >= pnt_b)
		return (ft_libstrdup(""));
	dst = ft_substr(s1, pnt_a, pnt_b - pnt_a);
	return (dst);
}

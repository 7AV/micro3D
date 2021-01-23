/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:48:14 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:12:58 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  The string to be split.
**	#2.  The delimiter character.
**
** Return value
** 	The array of new strings resulting from the split.
**	NULL if the allocation fails.
**
** Description
** 	Allocates (with malloc(3)) and returns an array of strings obtained
**	by splitting ’s’ using the character ’c’ as a delimiter.  The array
**	must be ended by a NULL pointer.
*/
#include "libft.h"

static int			ft_splitcount(char const *s, char c)
{
	unsigned int	count;
	unsigned int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
			flag = 1;
		if ((*s == c) && flag)
		{
			count++;
			flag = 0;
		}
		if ((*s != c) && (*(s + 1) == '\0') && flag)
			count++;
		s++;
	}
	return (count);
}

static int			ft_splitlen(char *s, char c)
{
	int				len;

	len = 0;
	while ((*s != c) && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static void			*ft_free(char **s, int i)
{
	while (i--)
	{
		free(s[i]);
	}
	free(s);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	int				index;
	int				w_count;
	char			**dst;

	if (!s)
		return (NULL);
	w_count = ft_splitcount((char *)s, c);
	if (!(dst = (char **)ft_calloc((w_count + 1), sizeof(char*))))
		return (NULL);
	index = 0;
	while (w_count--)
	{
		while ((*s == c) && *s)
			s++;
		dst[index] = ft_substr((char *)s, 0, ft_splitlen((char *)s, c));
		if (!dst[index])
			return (ft_free(dst, index));
		s = s + ft_splitlen((char *)s, c);
		index++;
	}
	dst[index] = NULL;
	return (dst);
}

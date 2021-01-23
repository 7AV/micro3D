/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:30:27 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:10:15 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The strcmp() and strncmp() functions lexicographically compare the null-
**	terminated strings s1 and s2.
**
** The strncmp() function compares not more than n characters.  Because
** 	strncmp() is designed for comparing strings rather than binary data,
**	characters that appear after a `\0' character are not compared.
**
** RETURN VALUES
** 	The strcmp() and strncmp() functions return an integer greater than,
**	equal to, or less than 0, according as the string s1 is greater than,
**	equal to, or less than the string s2.  The comparison is done using unsigned
**	characters, so that `\200' is greater than `\0'.
*/
#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t index;

	index = 0;
	while (((unsigned char)s1[index] == (unsigned char)s2[index]) &&
			(index < n) &&
			s1[index] &&
			s2[index])
	{
		index++;
	}
	if (index == n)
		return (0);
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

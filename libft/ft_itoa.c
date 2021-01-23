/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:40:25 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/15 22:51:16 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  the integer to convert.
**
** Return value
** 	The string representing the integer.  NULL if the allocation fails.
**
** Description
** 	Allocates (with malloc(3)) and returns a string representing the integer
**	received as an argument. Negative numbers must be handled.
*/
#include "libft.h"

static int	ft_count(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		flag;
	char	*dst;

	if (n == -2147483648)
		return (ft_libstrdup("-2147483648"));
	len = ft_count(n);
	if (!(dst = (char *)ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	flag = 0;
	if (n < 0)
	{
		flag++;
		n *= -1;
		*dst = '-';
	}
	dst[len] = '\0';
	while (len--)
	{
		dst[len] = n % 10 + '0';
		n /= 10;
	}
	if (flag == 1)
		*dst = '-';
	return (dst);
}

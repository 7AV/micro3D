/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:59:28 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:22:10 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The memcpy() function copies n bytes from memory area src to memory area
** 	dst. If dst and src overlap, behavior is undefined. Applications in which
** 	dst and src might overlap should use memmove(3) instead.
** RETURN VALUES
** 	The memcpy() function returns the original value of dst.
*/
#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ptr_dst;
	const char	*ptr_src;

	if ((dst == src) || (n == 0))
		return (dst);
	ptr_dst = dst;
	ptr_src = src;
	while (n--)
	{
		*ptr_dst++ = *ptr_src++;
	}
	return (dst);
}

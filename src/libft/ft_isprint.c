/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:44:22 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:16:30 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The isprint() function tests for any printing character,
**	including space (` ').  The value of the argument must be representable
**	as an unsigned char or the value of EOF.
*/
#include "libft.h"

int	ft_isprint(int a)
{
	if ((a >= 32) && (a <= 126))
		return (1);
	return (0);
}

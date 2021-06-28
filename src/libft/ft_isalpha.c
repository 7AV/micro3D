/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:26:32 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/04 19:48:33 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The isalpha() function tests for any character for which isupper(3) or
**	islower(3) is true.  The value of the argument must be representable as
**	an unsigned char or the value of EOF.
*/
#include "libft.h"

static int	ft_isupper(int a)
{
	if ((a >= 'A') && (a <= 'Z'))
		return (1);
	return (0);
}

static int	ft_islower(int a)
{
	if ((a >= 'a') && (a <= 'z'))
		return (1);
	return (0);
}

int			ft_isalpha(int a)
{
	if (ft_islower(a) || ft_isupper(a))
		return (1);
	return (0);
}

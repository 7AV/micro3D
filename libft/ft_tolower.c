/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:14:23 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:16:14 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The tolower() function converts an upper-case letter to the corresponding
**	lower-case letter.  The argument must be representable as an unsigned char
**	or the value of EOF.
*/
#include "libft.h"

int	ft_tolower(int a)
{
	if ((a >= 'A') && (a <= 'Z'))
		return (a - 'A' + 'a');
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:14:23 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:20:07 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The toupper() function converts a lower-case letter to the corresponding
**	upper-case letter.  The argument must be representable as an unsigned char
**	or the value of EOF.
*/
#include "libft.h"

int	ft_toupper(int a)
{
	if ((a >= 'a') && (a <= 'z'))
		return (a - 'a' + 'A');
	return (a);
}

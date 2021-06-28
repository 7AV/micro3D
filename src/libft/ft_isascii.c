/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:17:00 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:22:47 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The isascii() function tests for an ASCII character, which is any character
**	between 0 and octal 0177 inclusive.
*/
#include "libft.h"

int	ft_isascii(int a)
{
	if ((a >= 0) && (a <= 127))
		return (1);
	return (0);
}

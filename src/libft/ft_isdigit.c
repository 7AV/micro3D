/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:41:53 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 20:54:03 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The isdigit() function tests for a decimal digit character.
*/
#include "libft.h"

int	ft_isdigit(int a)
{
	if ((a >= '0') && (a <= '9'))
		return (1);
	return (0);
}

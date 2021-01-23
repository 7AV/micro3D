/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:05:40 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/06 11:08:58 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** 	The atoi() function converts the initial portion of the string pointed
**	to by str to int representation.
*/

#include "libft.h"

static int			ft_isspace(int a)
{
	if (a == ' ' ||
			a == '\t' ||
			a == '\n' ||
			a == '\v' ||
			a == '\f' ||
			a == '\r')
		return (1);
	return (0);
}

int					ft_atoi(const char *str)
{
	int				flag;
	unsigned long	num;

	flag = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		flag = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
		if ((flag > 0) && (num > 9223372036854775807))
			return (-1);
		if ((flag < 0) && (num > 9223372036854775807))
			return (0);
	}
	return (int)(flag * num);
}

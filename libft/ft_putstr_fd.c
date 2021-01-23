/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:48:47 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/03 21:20:52 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parameters
** 	#1.  The string to output.
**	#2.  The file descriptor on which to write.
**
** Return value
** 	None
**
** Description
** 	Outputs the string ’s’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	if ((!str) || (fd < 0))
		return ;
	while (*str)
	{
		ft_putchar_fd(*str++, fd);
	}
}

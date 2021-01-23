/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:02:12 by sbudding          #+#    #+#             */
/*   Updated: 2020/12/10 10:30:30 by sbudding         ###   ########.fr       */
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
** 	Outputs the string ’s’ to the given file descriptor, followed by a newline.
*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if ((!s) || (fd < 0))
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

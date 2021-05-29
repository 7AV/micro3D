/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:34:06 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/27 11:50:30 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_data(t_data *data)
{
	ft_free(data->input);
	ft_free(data->skin->path);
	free(data->skin->text);
}

void	ft_free(char **trash)
{
	int		ind;

	ind = 0;
	while (trash[ind])
	{
		free(trash[ind]);
		ind++;
	}
	free(trash);
}

int		ft_close(t_data *data)
{
	ft_free(data->input);
	ft_free(data->skin->path);
	free(data->skin->text);
	exit(0);
}

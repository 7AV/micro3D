/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:18:43 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/27 11:54:22 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_input_build(t_list **input_head, t_data *data)
{
	int		list_count;
	int		ind;
	t_list	*tmp;

	ind = 0;
	tmp = *input_head;
	list_count = ft_lstsize(tmp);
	(data->input = ft_calloc(list_count + 1, sizeof(char*))) ?
	0 : ft_error(ER_MALLOC);
	while (tmp)
	{
		(data->input[ind] = ft_strdup(tmp->content)) ?
		0 : ft_error(ER_MALLOC);
		tmp = tmp->next;
		ind++;
	}
	data->input[ind] = 0;
}

void	ft_read_input(char *argv, t_data *data)
{
	int		fd;
	char	*line;
	t_list	*input_head;

	(fd = open(argv, O_RDONLY)) <= 0 ? ft_error(ER_FD) : 0;
	line = NULL;
	input_head = NULL;
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&input_head, ft_lstnew(line));
	ft_lstadd_back(&input_head, ft_lstnew(line));
	close(fd);
	ft_input_build(&input_head, data);
	ft_input_parse(data);
	ft_lstclear(&input_head, &free);
}

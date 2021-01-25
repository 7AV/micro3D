/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:18:43 by sbudding          #+#    #+#             */
/*   Updated: 2021/01/25 20:32:03 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_input_build(t_list **input_head, t_data *data)
{
	int		list_count;
	int		ind;
	t_list	*tmp;

	ind = 0;
	list_count = ft_lstsize(*input_head);
	!(data->input = ft_calloc(list_count + 1, sizeof(char *))) ?
	ft_error(ER_MALLOC) : 0;
	tmp = *input_head;
	while (tmp)
	{
		data->input[ind] = tmp->content;
		tmp = tmp->next;
		ind++;
	}
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
}

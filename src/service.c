#include "micro3D.h"

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
	(void)data;
	// ft_free(data->input);
	// ft_free(data->skin->path);
	// free(data->skin->text);
	exit(0);
}

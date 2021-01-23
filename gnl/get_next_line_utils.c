/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:53:03 by sbudding          #+#    #+#             */
/*   Updated: 2020/12/10 10:50:09 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_strchr_ind(char *str, int a)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

char				*ft_strdup(const char *s1)
{
	unsigned int	len;
	unsigned int	i;
	char			*dst;

	len = 0;
	while (s1[len])
		len++;
	if (!(dst = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char				*ft_strcpy(char *dst, const char *src)
{
	int				i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char				*ft_strcat(char *dst, const char *src)
{
	int				a;
	int				b;

	a = 0;
	while (dst[a] != '\0')
		a++;
	b = 0;
	while (src[b] != '\0')
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
	return (dst);
}

char				*ft_strjoin_gnl(char *s1, char *s2)
{
	char			*dst;
	int				a;
	int				b;

	dst = NULL;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return ((s1) ? ft_strdup(s1) : ft_strdup(s2));
	else if (s1 && s2)
	{
		a = 0;
		b = 0;
		while (s1[a] != '\0')
			a++;
		while (s2[b] != '\0')
			b++;
		if (!(dst = (char*)malloc((a + b + 1) * sizeof(char))))
			return (NULL);
		ft_strcpy(dst, s1);
		free(s1);
		ft_strcat(dst, s2);
	}
	return (dst);
}

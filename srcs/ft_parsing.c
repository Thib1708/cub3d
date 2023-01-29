/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:34:18 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/29 10:24:59 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_tab_len(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
		i++;
	return (i);
}

char	*ft_get_path(char *line)
{
	char **split_line;
	char	*path;

	split_line = ft_split(line, " \n");
	free(line);
	path = NULL;
	while (*split_line++)
	{
		if (open(*split_line, O_RDONLY) != -1)
		{
			path = ft_strdup(*split_line);
		}
		// printf("open result : %d\n", open(*split_line, O_RDONLY));
		free(*split_line);
	}
	printf("path :%s\n", path);
	// free(split_line);
	return (path);
}

int	*ft_get_rgb(char *line)
{
	char 	**split_line;
	int		*param;
	int 	i;
	int 	j;

	i = 0;
	split_line = ft_split(line, ", \n");
	if (ft_tab_len(split_line) != 4)
		return (NULL);
	param = malloc(sizeof(int *) * 3);
	while(split_line[++i])
	{
		j = -1;
		while(split_line[i][++j])
			if (!ft_isdigit(split_line[i][j]))
				return (NULL);
		printf("rgb split line : %s\n", split_line[i]);
		param[i - 1] = ft_atoi(split_line[i]);
	}
	return (param);
}

int ft_parsing(char **argv, t_cub3d *cub3d)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'N')
		{
			cub3d->north = ft_get_path(line);
			printf("North path :%s\n\n", cub3d->north);
		}
		else if (line[0] == 'S')
		{
			cub3d->south = ft_get_path(line);
			printf("South path :%s\n\n", cub3d->south);
		}
		else if (line[0] == 'E')
		{
			cub3d->east = ft_get_path(line);
			printf("East path :%s\n\n", cub3d->east);
		}
		else if (line[0] == 'W')
		{
			cub3d->west = ft_get_path(line);
			printf("West path :%s\n\n", cub3d->west);
		}
		if (line[0] == 'F')
			cub3d->floor = ft_get_rgb(line);
		if (line[0] == 'C')
			cub3d->ceiling = ft_get_rgb(line);
	}
	close(fd);
	return (0);
}
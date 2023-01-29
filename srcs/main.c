/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:31:54 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/29 10:25:08 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_cub3d	*cub3d;
	
	cub3d = malloc(sizeof(t_cub3d));
	if (argc == 2)
	{
		ft_parsing(argv, cub3d);
		printf("Parsing map :\n");
		printf("North path : %s\n", cub3d->north);
		printf("South path : %s\n", cub3d->south);
		printf("East path : %s\n", cub3d->east);
		printf("West path : %s\n", cub3d->west);
		printf("Floor color : %d,%d,%d\n", cub3d->floor[0], cub3d->floor[1], cub3d->floor[2]);
		printf("Floor color : %d,%d,%d\n", cub3d->ceiling[0], cub3d->ceiling[1], cub3d->ceiling[2]);
	}
}
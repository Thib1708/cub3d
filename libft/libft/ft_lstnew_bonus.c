/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:27:27 by thibaultgir       #+#    #+#             */
/*   Updated: 2022/11/25 11:40:04 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(int *tab, int size)
{
	t_list	*e;

	e = malloc(sizeof(*e));
	if (!e)
		return (NULL);
	e->tab = tab;
	e->size = size;
	e->next = NULL;
	return (e);
}

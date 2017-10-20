/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:44:18 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/14 13:43:36 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*table;
	int	i;

	if (min >= max)
		return (0);
	table = (int*)malloc((max - min) * sizeof(int));
	if (table == NULL)
		return (0);
	i = 0;
	while (min <= max - 1)
	{
		table[i] = min++;
		i++;
	}
	*range = table;
	return (i);
}

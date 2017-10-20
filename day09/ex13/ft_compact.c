/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:34:25 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/14 09:39:03 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compact(char **tab, int length)
{
	int	index;
	int	size;

	index = 0;
	size = length;
	while (index < length)
	{
		if (!tab[index])
			size--;
	}
	return (size);
}

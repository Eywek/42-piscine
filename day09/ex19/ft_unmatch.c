/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 12:14:05 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/14 13:41:26 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int	index;
	int	i;

	index = 0;
	while (index < length)
	{
		i = 0;
		while ((tab[index] != tab[i] || i == index) && i < length)
			i++;
		if (tab[index] != tab[i])
			return (tab[index]);
		++index;
	}
	return (0);
}

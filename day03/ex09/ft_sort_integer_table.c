/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:19:31 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/05 21:40:13 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_sort_integer_table(int *tab, int size)
{
	int	count;
	int	i;
	int	tmp;

	count = 0;
	while (count < size)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		count++;
	}
	return (tab);
}

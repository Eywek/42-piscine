/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:40:11 by fsabatie          #+#    #+#             */
/*   Updated: 2017/07/23 03:26:13 by mallano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ref.h"

t_char	*ft_create_elem(void)
{
	t_char *list_char;

	list_char = (t_char *)malloc(sizeof(t_char));
	list_char->character = 0;
	list_char->next = NULL;
	return (list_char);
}

void	ft_print_list(t_char *list_start)
{
	while (list_start->next)
	{
		write(1, &list_start->character, 1);
		list_start = list_start->next;
	}
}

void	ft_print_results(int *results, int col, int lines)
{
	int i;
	int printed;

	i = 0;
	printed = 0;
	while (i < 5)
	{
		if (results[i])
		{
			if (printed)
				ft_putstr(" || ");
			ft_putstr("[colle-0");
			ft_putnbr(i);
			ft_putstr("] [");
			ft_putnbr(col);
			ft_putstr("] [");
			ft_putnbr(lines);
			ft_putstr("]");
			printed = 1;
		}
		i++;
	}
	if (!printed)
		ft_putstr("aucune");
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;
	char			nbr;

	n = nb;
	nbr = n + '0';
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		write(1, &nbr, 1);
}

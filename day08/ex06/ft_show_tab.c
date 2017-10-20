/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:30:52 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/17 23:06:08 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

void	ft_print_words_tables(char **tab)
{
	int	index;
	int	i;

	index = 0;
	while (tab[index])
	{
		i = 0;
		while (tab[index][i])
		{
			ft_putchar(tab[index][i]);
			++i;
		}
		ft_putchar('\n');
		index++;
	}
}

void	ft_show_tab(t_stock_par *par)
{
	int	index;
	int	i;

	index = 0;
	while (par[index].str)
	{
		i = 0;
		while (par[index].copy[i])
		{
			ft_putchar(par[index].copy[i]);
			++i;
		}
		ft_putchar('\n');
		ft_putnbr(par[index].size_param);
		ft_putchar('\n');
		ft_print_words_tables(par[index].tab);
		++index;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 01:08:18 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/16 23:56:28 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_util.h"
#include "../ft_opp.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int		get_operation(char *operator)
{
	int	i;
	int	j;

	i = 0;
	while (g_opptab[i].operation)
	{
		j = 0;
		while (operator[j] && g_opptab[i].operation[j] &&
				g_opptab[i].operation[j] == operator[j])
		{
			++j;
			if (!operator[j])
				return (i);
		}
		++i;
	}
	return (-1);
}

int		calculate(int a, int b, int operation)
{
	return ((*g_opptab[operation].function)(a, b));
}

int		main(int argc, char *argv[])
{
	int	res;
	int	operator;

	if (argc != 4)
		return (0);
	operator = get_operation(argv[2]);
	if (operator == -1)
	{
		(*g_opptab[5].function)(0, 0);
		return (0);
	}
	else if (operator == 3 && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	else if (operator == 4 && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	res = calculate(ft_atoi(argv[1]), ft_atoi(argv[3]), operator);
	ft_putnbr(res);
	ft_putchar('\n');
	return (0);
}

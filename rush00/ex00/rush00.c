/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 08:18:09 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/08 09:38:34 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	middle(int x, int y)
{
	int	i;
	int	count;

	if (y > 1)
	{
		count = 0;
		while (count < (y - 2))
		{
			ft_putchar('\n');
			ft_putchar('|');
			i = 0;
			while (i < (x - 2))
			{
				ft_putchar(' ');
				++i;
			}
			if (x > 1)
				ft_putchar('|');
			++count;
		}
	}
}

void	end(int x, int y)
{
	int	i;

	if (x > 0 && y > 1)
	{
		ft_putchar('\n');
		ft_putchar('o');
		i = 0;
		while (i < (x - 2))
		{
			ft_putchar('-');
			++i;
		}
		if (x > 1)
			ft_putchar('o');
	}
	if (x > 0 && y > 0)
		ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x > 0 && y > 0)
		ft_putchar('o');
	i = 0;
	while (i < (x - 2) && y > 0)
	{
		ft_putchar('-');
		++i;
	}
	if (x > 1 && y > 0)
		ft_putchar('o');
	middle(x, y);
	end(x, y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:45:01 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/14 14:51:46 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int	nbr;
	char			t;

	if (nb < 0)
	{
		write(1, "-", 1);
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	t = nbr % 10 + 48;
	write(1, &t, 1);
}

void	display(int hour, char moment_hour, int y, char moment_y)
{
	write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
	ft_putnbr(hour);
	write(1, ".00 ", 4);
	write(1, &moment_hour, 1);
	write(1, ".M. AND ", 8);
	ft_putnbr(y);
	write(1, ".00 ", 4);
	write(1, &moment_y, 1);
	write(1, ".M.\n", 4);
}

void	ft_takes_place(int hour)
{
	int		y;
	char	moment_hour;
	char	moment_y;

	moment_hour = 'A';
	moment_y = 'A';
	y = hour + 1;
	if (hour >= 12)
	{
		moment_hour = 'P';
		if (hour > 12)
			hour -= 12;
	}
	if (hour == 0)
		hour = 12;
	if (y >= 12)
	{
		moment_y = 'P';
		if (y > 12)
			y -= 12;
	}
	if (y == 0)
		y = 12;
	display(hour, moment_hour, y, moment_y);
}

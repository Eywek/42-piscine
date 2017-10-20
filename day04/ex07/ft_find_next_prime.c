/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 09:09:36 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/09 21:26:41 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (nb % i != 0)
	{
		if (i > nb)
			break ;
		++i;
	}
	if (nb == i)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		++nb;
	}
}

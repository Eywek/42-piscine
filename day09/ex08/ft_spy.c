/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 00:49:02 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/14 02:29:36 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_words(char *str1, char *str2)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	while (str2[size])
		size++;
	i = 0;
	j = 0;
	while (str1[i] && str2[j])
	{
		if (str1[i] == str2[j])
		{
			i++;
			j++;
			if (j == size)
				return (1);
		}
		else if (str1[i] == ' ' || str2[i] == '\t')
			i++;
		else
			return (0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		index;
	char	*str;

	index = 1;
	while (index < argc)
	{
		i = 0;
		while (argv[index][i])
		{
			if (argv[index][i] >= 'A' && argv[index][i] <= 'Z')
				argv[index][i] += 32;
			++i;
		}
		if (check_words(argv[index], "president") ||
			check_words(argv[index], "attack") ||
			check_words(argv[index], "powers"))
		{
			write(1, "Alert!!!\n", 9);
			break ;
		}
		++index;
	}
	return (0);
}

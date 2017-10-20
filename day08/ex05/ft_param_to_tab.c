/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 10:38:05 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/17 23:06:22 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

char		*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (src[i])
	{
		++size;
		++i;
	}
	new = malloc(sizeof(char) * size);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int			ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

t_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			index;
	t_stock_par	*params;

	if (!(params = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1))))
		return (0);
	index = 0;
	while (index < ac)
	{
		params[index].size_param = ft_strlen(av[index]);
		params[index].str = av[index];
		params[index].copy = ft_strdup(av[index]);
		params[index].tab = ft_split_whitespaces(av[index]);
		++index;
	}
	params[index].str = 0;
	return (params);
}

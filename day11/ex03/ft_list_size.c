/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:06:25 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/20 00:53:57 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	if (!begin_list)
		return (count);
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		++count;
	}
	return (count);
}

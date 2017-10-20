/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:50:19 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/20 09:34:17 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list, t_list *begin_list2)
{
	t_list	*current;

	if (!begin_list || !*begin_list)
		*begin_list = begin_list2;
	else
	{
		current = *begin_list;
		while (current->next)
			current = current->next;
		current->next = begin_list2;
	}
}

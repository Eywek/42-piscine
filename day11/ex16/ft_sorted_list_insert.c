/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:39:31 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/19 09:14:33 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem(data);
}

void	list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr;
	t_list	*ptr2;
	t_list	*next;

	ptr = *begin_list;
	while (ptr)
	{
		ptr2 = *begin_list;
		while (ptr2->next)
		{
			if ((*cmp)(ptr2->data, ptr2->next->data) > 0)
			{
				next = ptr2->data;
				ptr2->data = ptr2->next->data;
				ptr2->next->data = next;
			}
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	list_push_back(begin_list, data);
	list_sort(begin_list, cmp);
}

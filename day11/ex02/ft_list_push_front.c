/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:02:09 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/20 09:28:57 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *element;

	if (*begin_list)
	{
		element = ft_create_elem(data);
		element->next = *begin_list;
		*begin_list = element;
	}
	else
		*begin_list = ft_create_elem(data);
}

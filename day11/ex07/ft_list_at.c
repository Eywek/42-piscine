/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:02:10 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/20 11:33:08 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int n;

	n = nbr;
	if (begin_list == NULL)
		return (NULL);
	while (n-- && begin_list)
		begin_list = begin_list->next;
	return (n >= -1 ? begin_list : NULL);
}

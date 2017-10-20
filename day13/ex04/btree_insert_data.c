/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:05:21 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/27 10:40:31 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*current;

	if (!root || !*root || !item)
	{
		if (item && root)
			*root = btree_create_node(item);
		return ;
	}
	current = *root;
	if (cmpf(item, current->item) < 0)
	{
		if (current->left)
			btree_insert_data(&current->left, item, cmpf);
		else
			current->left = btree_create_node(item);
	}
	else
	{
		if (current->right)
			btree_insert_data(&current->right, item, cmpf);
		else
			current->right = btree_create_node(item);
	}
}

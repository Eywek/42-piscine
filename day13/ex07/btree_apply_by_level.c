/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:17:19 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/27 10:41:30 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int		ft_btree_level_count(t_btree *root)
{
	int	count;

	count = 0;
	if (!root)
		return (0);
	if (root->left)
		count = ft_max(count, ft_btree_level_count(root->left));
	if (root->right)
		count = ft_max(count, ft_btree_level_count(root->right));
	return (count + 1);
}

void	call(t_btree *root, int current_level, int *levels,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	is_first_elem;

	is_first_elem = 1;
	if (levels[current_level] == 1)
		is_first_elem = 0;
	else
		levels[current_level] = 1;
	applyf(root->item, current_level, is_first_elem);
	if (root->left)
		call(root->left, current_level + 1, levels, applyf);
	if (root->right)
		call(root->right, current_level + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	int	count;
	int	*levels;
	int	i;

	if (!root)
		return ;
	count = ft_btree_level_count(root);
	if (!(levels = (int*)malloc(sizeof(int) * count)))
		return ;
	i = 0;
	while (i < count)
		levels[i++] = 0;
	call(root, 0, levels, applyf);
}

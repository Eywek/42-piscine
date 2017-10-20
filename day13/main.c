/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:45:22 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/27 10:41:54 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_btree.h"
#include <stdio.h>

t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int		btree_level_count(t_btree *root);
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

void	display(void *element)
{
	printf("%s\n", element);
}

void	display_plus(void *item, int current_level, int is_first_elem)
{
	printf("[%d] (%d) %s\n", current_level, is_first_elem, item);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0'))
		return (s1[i] - s2[i]);
	return (0);
}

int main(int argc, char *argv[])
{
	t_btree subsubtree = {NULL, NULL, "3"};
	t_btree subsubtree2 = {NULL, NULL, "4"};
	t_btree subsubtree3 = {NULL, NULL, "6"};
	t_btree subsubtree4 = {NULL, NULL, "7"};
	t_btree subtree = {&subsubtree, &subsubtree2, "2"};
	t_btree subtree2 = {&subsubtree3, &subsubtree4, "5"};
	t_btree tree = {&subtree, &subtree2, "1"};

	printf("tree->item: %s\n", tree.item);
	printf("tree->left->item: %s\n", tree.left->item);
	printf("tree->left->left->item: %s\n", tree.left->left->item);
	printf("tree->left->right->item: %s\n", tree.left->right->item);
	printf("tree->right->item: %s\n", tree.right->item);
	printf("tree->right->left->item: %s\n", tree.right->left->item);
	printf("tree->right->right->item: %s\n", tree.right->right->item);

	////////////////
	printf("-- DISPLAY PREFIX -- OK\n");
	btree_apply_prefix(&tree, &display);
	////////////////
	printf("\n-- DISPLAY INFIX -- OK\n");
	btree_apply_infix(&tree, &display);
	////////////////
	printf("\n-- DISPLAY SUFFIX -- OK\n");
	btree_apply_suffix(&tree, &display);
	////////////////
	printf("\n-- INSERT DATA -- OK\n");
	t_btree *tree2 = &tree;
	btree_insert_data(&tree2, "2", &ft_strcmp);
	btree_apply_prefix(tree2, &display);
	////////////////
	printf("\n-- SEARCH ITEM -- OK\n");
	printf("%s\n", btree_search_item(&tree, "2", &ft_strcmp));
	////////////////
	printf("\n-- LEVEL COUNT -- OK\n");
	printf("%d\n", btree_level_count(&tree));
	////////////////
	printf("\n-- APPLY BY LEVEL -- OK\n");
	//	btree_apply_by_level(&tree, &display_plus);

	t_btree nsubsubtree = {NULL, NULL, "3"};
	t_btree nsubsubtree2 = {NULL, NULL, "4"};
	t_btree nsubsubtree3 = {NULL, NULL, "6"};
	t_btree nsubsubtree5 = {NULL, NULL, "8"};
	t_btree nsubsubtree4 = {NULL, &nsubsubtree5, "7"};
	t_btree nsubtree = {&nsubsubtree, &nsubsubtree2, "2"};
	t_btree nsubtree2 = {&nsubsubtree3, &nsubsubtree4, "5"};
	t_btree node = {&nsubtree, &nsubtree2, "1"};
	btree_apply_by_level(&node, display_plus);
	return (0);
}

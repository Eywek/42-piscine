/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ref.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:02:39 by fsabatie          #+#    #+#             */
/*   Updated: 2017/07/23 03:47:45 by mallano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REF_H
# define FT_REF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define COLLE00 0
# define COLLE01 1
# define COLLE02 2
# define COLLE03 3
# define COLLE04 4

typedef struct		s_char
{
	char			character;
	struct s_char	*next;
}					t_char;

int					ft_get_col(t_char *start);
int					ft_get_lines(t_char *start);
void				ft_putstr(char *str);
t_char				*ft_create_elem(void);
void				ft_print_list(t_char *list_start);
char				*printsquare(int n, char a, char b, char c);
char				*rush(int x, int y, char *tab);
int					ft_strlen(char *str);
char				*concat_str(char *top, char *middle, char *bottom,
					int lines);
char				*rush(int x, int y, char *tab);
char				*printsquare(int n, char a, char b, char c);
char				**ft_get_tests_tab(void);
char				**ft_get_colles(int col, int lines);
int					*ft_compare(char **tocompare, t_char *start);
int					ft_strlistcmp(char *str, t_char *list);
void				ft_print_results(int *results, int col, int lines);
void				ft_putnbr(int nb);
#endif

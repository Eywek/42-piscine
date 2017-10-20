/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 00:41:13 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/23 22:42:50 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

char	*remove_whitespaces(char *str);
int		parse_parenthesis(char **str);
int		primary_expression(char **str);
int		multiplicate_expression(char **str);
int		eval_expr(char *str);
int		do_op(int nb1, int nb2, char op);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putnbr(int nbr);

#endif

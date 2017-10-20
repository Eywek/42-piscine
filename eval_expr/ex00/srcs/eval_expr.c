/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 00:29:43 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/23 22:44:58 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/functions.h"

int		parse_parenthesis(char **str)
{
	int		nbr;
	int		signe;

	nbr = 0;
	signe = 1;
	if ((*str)[0] == '+' || (*str)[0] == '-')
	{
		if ((*str)[0] == '-')
			signe = -1;
		*str = *str + 1;
	}
	if ((*str)[0] == '(')
	{
		*str = *str + 1;
		nbr = primary_expression(str);
		if ((*str)[0] == ')')
			*str = *str + 1;
		return (signe * nbr);
	}
	while ('0' <= (*str)[0] && (*str)[0] <= '9')
	{
		nbr = (nbr * 10) + (*str)[0] - '0';
		*str = *str + 1;
	}
	return (signe * nbr);
}

int		multiplicate_expression(char **str)
{
	int		nb1;
	int		nb2;
	char	operator;

	nb1 = parse_parenthesis(str);
	while ((*str)[0] == '*' || (*str)[0] == '/' || (*str)[0] == '%')
	{
		operator = (*str)[0];
		*str = *str + 1;
		nb2 = parse_parenthesis(str);
		nb1 = do_op(nb1, nb2, operator);
	}
	return (nb1);
}

int		primary_expression(char **str)
{
	int		nb1;
	int		nb2;
	char	operator;

	nb1 = parse_parenthesis(str);
	while ((*str)[0] != '\0' && (*str)[0] != ')')
	{
		operator = (*str)[0];
		*str = *str + 1;
		if (operator == '+' || operator == '-')
			nb2 = multiplicate_expression(str);
		else
			nb2 = parse_parenthesis(str);
		nb1 = do_op(nb1, nb2, operator);
	}
	return (nb1);
}

char	*remove_whitespaces(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			str2[j] = str[i];
			j = j + 1;
		}
		i = i + 1;
	}
	str2[j] = '\0';
	return (str2);
}

int		eval_expr(char *str)
{
	str = remove_whitespaces(str);
	if (str[0] == '\0')
		return (0);
	return (primary_expression(&str));
}

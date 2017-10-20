/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 14:38:01 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/27 16:08:15 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	brainfuck(char *str)
{
	int	tab[2048] = {0};
	int	*ptr;
	int	loop_count;

	ptr = tab;
	loop_count = 0;
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			++(*ptr);
		else if (*str == '-')
			--(*ptr);
		else if (*str == '.')
			write(1, ptr, 1);
		else if (*str == '[' && *ptr == 0)
		{
			loop_count = 1;
			while (loop_count != 0)
			{
				str++;
				if (*str == ']')
					--loop_count;
				if (*str == '[')
					++loop_count;
			}
		}
		else if (*str == ']' && *ptr != 0)
		{
			loop_count = 1;
			while (loop_count != 0)
			{
				str--;
				if (*str == '[')
					--loop_count;
				if (*str == ']')
					++loop_count;
			}
		}
		str++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		brainfuck(argv[1]);
	return (0);
}

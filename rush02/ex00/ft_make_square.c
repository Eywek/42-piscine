/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squares.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 01:35:29 by fsabatie          #+#    #+#             */
/*   Updated: 2017/07/23 03:40:24 by mallano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ref.h"

char	*printsquare(int n, char a, char b, char c)
{
	int		i;
	int		pos;
	char	*str;

	i = 0;
	pos = 0;
	if (!(str = (char*)malloc(sizeof(char) * n + 2)))
		return (0);
	str[pos++] = a;
	if (n > 2)
		while (i++ < n - 2)
			str[pos++] = b;
	if (n > 1)
		str[pos++] = c;
	str[pos++] = '\n';
	str[pos] = '\0';
	return (str);
}

char	*rush(int x, int y, char *tab)
{
	int		i;
	char	*top;
	char	*middle;
	char	*bottom;

	i = 0;
	if (!(top = (char *)malloc(sizeof(char) * (y + 1)))
	|| !(middle = (char *)malloc(sizeof(char) * (x + 1) * (y + 1)))
	|| !(bottom = (char *)malloc(sizeof(char) * (y + 1))))
		return (0);
	if (x > 0)
	{
		if (y > 0)
			top = printsquare(x, tab[0], tab[1], tab[2]);
		if (y > 2)
			middle = printsquare(x, tab[3], ' ', tab[3]);
		if (y > 1)
			bottom = printsquare(x, tab[4], tab[1], tab[5]);
	}
	return (concat_str(top, middle, bottom, y));
}

char	*concat_str(char *top, char *middle, char *bottom, int lines)
{
	int		len;
	char	*str;
	int		pos;
	int		y;

	pos = 0;
	len = ft_strlen(top);
	if (!(str = (char *)malloc(sizeof(char) * lines * len + 1)))
		return (0);
	while (*top)
		str[pos++] = *top++;
	while (lines > 2)
	{
		y = 0;
		while (middle[y])
			str[pos++] = middle[y++];
		lines--;
	}
	while (*bottom)
		str[pos++] = *bottom++;
	str[pos] = '\0';
	return (str);
}

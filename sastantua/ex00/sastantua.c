/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:53:47 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/09 20:03:49 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		count_char_on_endline(int size)
{
	int	char_count;
	int	char_add;
	int	floor_count;
	int	lines;

	char_count = -3;
	floor_count = 0;
	lines = 3;
	char_add = 2;
	while (floor_count < size)
	{
		if (floor_count % 2 == 1)
			char_count += (char_add += 2);
		else
			char_count += char_add;
		char_count = char_count + 2 * lines;
		floor_count++;
		lines++;
	}
	return (char_count);
}

int		is_door(int size, int char_count, int i, int lines[3])
{
	int	door;

	door = size;
	if (size % 2 == 0)
		door -= 1;
	if (i >= char_count / 2 - door / 2 && i <= char_count / 2 + door / 2 &&
			lines[0] >= lines[1] - door && lines[2] == size - 1)
		return (1);
	return (0);
}

int		is_lock(int size, int lines[3], int char_count, int i)
{
	int	door;

	door = size;
	if (size % 2 == 0)
		door -= 1;
	if (is_door(size, char_count, i, lines) &&
			lines[0] == (lines[1] - door / 2) - 1
			&& i == (char_count / 2 + door / 2))
		return (1);
	return (0);
}

void	display_line(int char_count, int size, int lines[3], int floor_count)
{
	int	i;
	int	char_on_endline;

	lines[2] = floor_count;
	char_on_endline = 0;
	char_on_endline = count_char_on_endline(size);
	i = 0;
	while (i < (char_on_endline / 2) - char_count / 2)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('/');
	i = 0;
	while (i++ < char_count)
	{
		if (size >= 5 && is_lock(size, lines, char_count, i))
			ft_putchar('$');
		else if (is_door(size, char_count, i - 1, lines))
			ft_putchar('|');
		else
			ft_putchar('*');
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	sastantua(int size)
{
	int	floor_count;
	int	char_count;
	int	lines[3];
	int	char_add;

	char_add = 4;
	floor_count = -1;
	char_count = -3;
	lines[1] = 3;
	while (++floor_count < size)
	{
		lines[0] = -1;
		while (++lines[0] < lines[1])
		{
			if (floor_count % 2 == 1 && lines[0] == 0)
				char_count += (char_add += 2);
			else if (lines[0] == 0)
				char_count += char_add;
			else
				char_count += 2;
			display_line(char_count, size, lines, floor_count);
		}
		lines[1]++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:28:30 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/21 14:33:18 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

void	display_new_line( unsigned int i, int line_size, unsigned int line_count)
{
	unsigned int k;

	if (i > 0)
		ft_putchar('\n');
	k = (line_count == 0 ? 1 : line_count);
	while ((k *= 10) < 10000000)
		ft_putchar('0');
	ft_putnbr(line_count * 10);
	if (line_count == 0)
		ft_putchar('0');
	ft_putchar(':');
	ft_putchar(' ');
}

void	ft_putnbr_base(int nb, int i)
{
	unsigned int	nbr;
	char			*base;

	base = "0123456789abcdef";
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, ++i);
	if (i == 1)
		ft_putchar('0');
	ft_putchar(base[nbr % 16]);
}

void	display_hexa(char *str)
{
	int	count;

	count = -1;
	while (++count < 16)
	{
		ft_putnbr_base(str[count], 1);
		if (count % 2 == 1)
			ft_putchar(' ');
	}
	ft_putchar(' ');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	line_count;
	int				line_size;
	char			*str;

	line_size = 1;
	line_count = 0;
	str = (char *)addr;
	i = -1;
	while (++i < size)
	{
		if (i == 0)
		{
			display_new_line(i, line_size, line_count);
			display_hexa(str + i);
		}
		if (str[i] >= 32 && str[i] != 127)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		if (line_size == 16)
		{
			++line_count;
			display_new_line(i, line_size, line_count);
			display_hexa(str + i + 1);
			line_size = 0;
		}
		++line_size;
	}
	ft_putchar('\n');
	return (addr);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
int	main(int argc, char *argv[])
{
	argv[1] = "Salut les aminches c'est cool show mem on fait de truc terrible\n\n\n\n\t\v\t\t\t\t\t\t\t\t\t6666666666666666666666666666666666666666666699999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999\t";
	int	*tab;
	tab = malloc(sizeof(int) * 10);
	tab[0] = 4;
	tab[1] = 22;
	tab[2] = 10;
	tab[3] = 8;
	tab[4] = 9;
	tab[5] = 0;
	tab[6] = 34;
	tab[7] = 16;
	tab[8] = 4533;
	tab[9] = 35;
	//ft_print_memory((char*)argv[1], (unsigned int)ft_strlen(argv[1]));
	ft_print_memory(tab, 10);
	return (0);
}

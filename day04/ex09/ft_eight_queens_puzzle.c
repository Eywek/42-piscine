/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 09:50:19 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/07 15:23:25 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_eight_queens_puzzle(void)
{
	int	chessboard[8][8];
	int	column;
	int	pos;
	int	test;
	int	testpos;
	int	queens;
	int	tmp;
	int	ok;

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			chessboard[i][j] = 0;
		}
	} 

	column = 0;
	queens = 0;
	while (column < 8)
	{
		pos = 0;
		tmp = queens;
		ok = 1;
		while (queens != tmp+1)
		{
			if (chessboard[column][pos] == 1)
			{
				printf("FIND QUEEN AT %d - %d\n", column, pos);
				++pos;
				continue ;
			}
			if (chessboard[0][pos] == 1 || chessboard[1][pos] == 1 || chessboard[2][pos] == 1 || chessboard[3][pos] == 1 || chessboard[4][pos] == 1 || chessboard[5][pos] == 1 || chessboard[6][pos] == 1)
			{
				printf("FIND QUEEN AT %d - %d\n", column, pos);
				++pos;
				continue ;
			}
			test = column + 1;
			testpos = pos + 1;
			while (test <= 7 && testpos <= 7)
			{
				if (chessboard[test][testpos] != 1)
				{
					ok = 1;
					break ;
				}
				ok = 0;
				printf("check + AT %d - %d\n", test, testpos);
				test++;
				testpos++;
			}
			test = column - 1;
			testpos = pos - 1;
			while (test >= 0 && testpos >= 0)
			{
				if (chessboard[test][testpos] != 1)
				{
					ok = 1;
					break;
				}
				ok = 0;
				printf("check - AT %d - %d\n", test, testpos);
				test--;
				testpos--;
			}
				/*if (column < 7 && pos < 7 && chessboard[column + 1][pos + 1])
			{
				printf("FIND QUEEN AT %d - %d\n", column, pos);
				++pos;
				continue ;
			}
			if (column > 0 && pos > 0 && chessboard[column - 1][pos - 1])
			{
				printf("FIND QUEEN AT %d - %d\n", column, pos);
				++pos;
				continue ;
			}*/
			if (ok) {
				chessboard[column][pos] = 1;
				queens++;
				printf("QUEEN: %d - %d\n", column, pos);
				break ;
			}
			++pos;
		}
		++column;
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
				printf("%d ", chessboard[i][j]);
			}
			 printf("\n");
		} 
	}

	return (queens);
}

int main(int argc, const char *argv[])
{
	printf("%d\n", ft_eight_queens_puzzle());
	return 0;
}

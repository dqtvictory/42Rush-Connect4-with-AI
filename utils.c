#include "connect4.h"

int	col_to_row(int col)
{
	int	row = 0;
	for (; row < game.nrows; ++row)
	{
		if (game.board[get_idx(row, col)] == EMPTY)
			break;
	}
	return (row);
}
int	get_row(int idx)
{
	return idx / game.ncols;
}

int	get_col(int idx)
{
	return idx % game.ncols;
}

int	get_idx(int row, int col)
{
	return row * game.ncols + col;
}

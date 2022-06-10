#include "connect4.h"

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

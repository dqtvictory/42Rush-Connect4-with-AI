#include "connect4.h"


#define SCORE_0	0
#define SCORE_1	1
#define SCORE_2	4
#define SCORE_3	16
#define SCORE_4	16384

#define TO_WIN	4


// Array to quickly retrieve score
static int	score_array[] = {
	SCORE_0, SCORE_1, SCORE_2, SCORE_3, SCORE_4
};

// Move forward directions: s, se, e, ne
static t_direction	forward[] = {
	{-1, 0}, {-1, 1}, {0, 1}, {1, 1}
};

// Check backward directions: n, nw, w, sw,
static t_direction	backward[] = {
	{1, 0}, {1, -1}, {0, -1}, {-1, -1}
};

// Check if the row r and column c is out of bound
static bool	out_of_bound(int r, int c)
{
	return (r < 0 || r >= game.nrows || c < 0 || c >= game.ncols);
}

bool	winner_move(int r, int c)
{
	for (int i = 0; i < 4; ++i)
	{
		int	count = forward_check(r, c, i, forward) + forward_check(r, c, i, backward) - 1;
		if (count >= TO_WIN)
		{
			game.winner = game.board[get_idx(r, c)];
			return true;
		}
	}
	return false;
}

bool	backward_check(int r, int c, int dir_idx)
{
	int	player = game.board[get_idx(r, c)];
	
	r += backward[dir_idx].dr;
	c += backward[dir_idx].dc;

	if (out_of_bound(r, c))
		return false;
	
	return game.board[get_idx(r, c)] == player;
}

int	forward_check(int r, int c, int dir_idx, t_direction arr[])
{
	int	count = 1;
	int	player = game.board[get_idx(r, c)];

	for (int i = 1; i < TO_WIN; ++i)
	{
		r += arr[dir_idx].dr;
		c += arr[dir_idx].dc;

		if (out_of_bound(r, c))
			return 0;
		
		int	pawn = game.board[get_idx(r, c)];
		if (pawn == player)
		{
			++count;
			continue;
		}
		if (pawn != EMPTY)
			return 0;
		break;
	}

	return count;
}

int evaluate()
{
	if (game.ended)
		return game.winner * SCORE_4;

	int	value = 0;

	for (int r = 0; r < game.nrows; ++r)
	{
		for (int c = 0; c < game.ncols; ++c)
		{
			int	player = game.board[get_idx(r, c)];
			if (player == EMPTY)
				continue;
			
			for (int idx_dir = 0; idx_dir < 4; ++idx_dir)
			{
				if (backward_check(r, c, idx_dir))
					continue;
				value += player * score_array[forward_check(r, c, idx_dir, forward)];
			}
		}
	}

	return value;
}

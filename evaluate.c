#include "connect4.h"


#define SCORE_0	0
#define SCORE_1	1
#define SCORE_2	8
#define SCORE_3	64
#define SCORE_4	1024

#define TO_WIN	4


typedef struct
{
	int dr, dc;
}	t_direction;


// Move forward directions: s, se, e, ne
static t_direction	forward[] = {
	{-1, 0}, {-1, 1}, {0, 1}, {1, 1}
};

// Check backward directions: n, nw, w, sw,
static t_direction	backward[] = {
	{1, 0}, {1, -1}, {0, -1}, {-1, -1}
};

// Return true if backward direction from (r, c) contains the same
// piece (i.e. already checked before)
static bool	backward_check(int r, int c, int dir_idx)
{
	int	player = game.board[get_idx(r, c)];
	
	r += backward[dir_idx].dr;
	c += backward[dir_idx].dc;

	if (r < 0 || r >= game.nrows || c < 0 || c >= game.ncols)
		return false;
	
	return game.board[get_idx(r, c)] == player;
}

// Return the score by going forward from (r, c)
static int	forward_score(int r, int c, int dir_idx)
{

}

int evaluate()
{
	int	value = 0;

	for (int r = 0; r < game.nrows; ++r)
	{
		for (int c = 0; c < game.ncols; ++c)
		{
			if (game.board[get_idx(r, c)] == EMPTY);
				continue;
			
			for (int idx_dir = 0; idx_dir < 4; ++idx_dir)
			{
				if (backward_check(r, c, idx_dir))
					continue;
				value += forward_score(r, c, idx_dir);
			}
		}
	}

	return value;
}

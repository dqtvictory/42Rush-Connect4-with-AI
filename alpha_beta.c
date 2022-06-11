
#include "connect4.h"

#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))

typedef struct
{
	int	best, value;
}	t_pair;


static inline int	max(int x, int y)
{
	return (x > y) ? x : y;
}

static inline int	min(int x, int y)
{
	return (x < y) ? x : y;
}

t_pair	alpha_beta(int depth, int alpha, int beta, int move)
{
	t_pair	result;

	if (!depth || game.ended)
	{
		result.best = move;
		result.value = evaluate();
		return result;
	}

	int	*ab;
	int (*compare)(int, int);

	if (game.player == PLAYER_HUMAN)
	{
		result.value = alpha;
		ab = &alpha;
		compare = max;
	}
	else
	{
		result.value = beta;
		ab = &beta;
		compare = min;
	}

	for (int col = 0; col < game.ncols; ++col)
	{
		if (alpha >= beta)
			break;
		if (!play(col))
			continue;
		int	tmp = compare(result.value, alpha_beta(depth - 1, alpha, beta, col).value);
		undo_play(col);
		if (tmp != result.value)
		{
			result.value = tmp;
			result.best = col;
			*ab = result.value;
		}
	}
	return result;
}

int	ai_play()
{
	return alpha_beta(DEFAULT_DEPTH, -99999999, 99999999, -1).best;
}

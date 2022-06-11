#include "connect4.h"

#define COLOR_HUMAN	"\033[93m"	// Yellow
#define COLOR_AI	"\033[91m"	// Red
#define ENDC		"\033[0m"	// Reset color

#define	SYM_HUMAN	'o'
#define	SYM_AI		'x'
#define	SYM_EMPTY	' '


bool	play(int col)
{
	if (game.board[get_idx(game.nrows - 1, col)] != EMPTY)
		// If last row is filled, column is not playable
		return false;
	
	int	row = 0;
	for (; row < game.nrows; ++row)
		if (game.board[get_idx(row, col)] == EMPTY)
			break;
	
	game.board[get_idx(row, col)] = game.player;
	game.player *= -1;
	++game.count;

	return true;
}

void	undo_play(int col)
{
	if (game.board[get_idx(0, col)] == EMPTY)
		// If first row is empty, nothing to do
		return;
	
	int row = 0;
	for (; row < game.nrows; ++row)
		if (game.board[get_idx(row, col)] == EMPTY)
			break;
	game.board[get_idx(row - 1, col)] = EMPTY;
	game.player *= -1;
	--game.count;
}

void	print_state()
{
	for (int r = game.nrows - 1; r >= 0; --r)
	{
		for (int c = 0; c < game.ncols; ++c)
		{
			int		p = game.board[get_idx(r, c)];
			char	*color = 	(p == PLAYER_HUMAN) ? COLOR_HUMAN :
								(p == PLAYER_AI) ? COLOR_AI : "";
			char	symbol =	(p == PLAYER_HUMAN) ? SYM_HUMAN :
								(p == PLAYER_AI) ? SYM_AI : SYM_EMPTY;
			ft_printf("|%s%c%s", color, symbol, ENDC);
		}
		write(1, "|\n", 2);
	}
	for (int c = 0; c < game.ncols; ++c)
		ft_printf(" %d", c);
	write(1, "\n", 1);
}

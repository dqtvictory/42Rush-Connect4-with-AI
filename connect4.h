#ifndef CONNECT4_H
#define CONNECT4_H

#include <time.h>
#include <stdbool.h>
#include "42gc/ft_gc.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

#define PLAYER_HUMAN	1
#define PLAYER_AI		-1
#define EMPTY			0

#define MIN_ROW	6
#define MIN_COL	7

#define MAX_ROW	20
#define MAX_COL	20

#define DEFAULT_DEPTH	4


typedef struct
{
	int	nrows, ncols;	// board's number of rows and columns
	int	player;			// current player
	int	count;			// play count
	int	*board;			// game state
}	t_game;


// Execute the game loop until game is ended, then return true. If error occurs
// during execution, break out then return false
bool	game_loop();

// The current player plays a move in column col. Return true if the move is valid,
// false otherwise
bool	play(int col);

// Return true if game has ended
bool	game_ended();

// Print the game state
void	print_state();

// AI part

// Return a numerical value for current game state
int	evaluate();

// Undo the last play in column col
void	undo_play(int col);

// Some useful getters

int	get_row(int idx);
int	get_col(int idx);
int	get_idx(int row, int col);

extern char		*g_error;	// global string indicating program's error
extern t_game	game;		// global game struct that can be accessed anywhere

#endif
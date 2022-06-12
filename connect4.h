#ifndef CONNECT4_H
#define CONNECT4_H

#include <time.h>
#include <stdbool.h>
#include "libft/libft.h"

#define PLAYER_HUMAN	1
#define PLAYER_AI		-1
#define EMPTY			0

#define MIN_ROW	6
#define MIN_COL	7

#define MAX_ROW	20
#define MAX_COL	20

#define DEFAULT_DEPTH	6


typedef struct
{
	int		nrows, ncols;	// board's number of rows and columns
	int		player;			// current player
	int		count;			// play count
	int		*board;			// game state
	bool	ended;			// true if game ended
	int		winner;			// if ended, player who wins
}	t_game;

typedef struct
{
	int dr, dc;
}	t_direction;


// Execute the game loop until game is ended, then return true. If error occurs
// during execution, break out then return false
bool	game_loop();
// int	human_play();
// char	*get_line();


// The current player plays a move in column col. Return true if the move is valid,
// false otherwise
bool	play(int col);

// Return true if the move at (r, c) wins the game
bool	winner_move(int r, int c);
bool    winning(int idx);
bool    check(int i);


// Print the game state
void	print_state();

// AI part

// Return the AI's best move for the current game state
int	ai_play();

// Return true if backward direction from (r, c) contains the same
// piece (i.e. already checked before)
bool	backward_check(int r, int c, int dir_idx);

// Return the number of consecutive pawns by going forward in a direction from (r, c)
int	forward_check(int r, int c, int dir_idx, t_direction arr[]);

// Return a numerical value for current game state
int	evaluate();

// Undo the last play in column col
void	undo_play(int col);

// Some useful getters

int	col_to_row(int col);
int	get_row(int idx);
int	get_col(int idx);
int	get_idx(int row, int col);

extern char		*g_error;	// global string indicating program's error
extern t_game	game;		// global game struct that can be accessed anywhere

#endif
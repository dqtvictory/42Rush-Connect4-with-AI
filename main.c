#include "connect4.h"

char	*g_error = NULL;
t_game	game;


// Display the global error message then return 1
static int	print_error_exit()
{
	ft_printf("Error: %s\n", g_error);
	ft_gc_free_all();
	return 1;
}

// Check program's arguments. If something is wrong, g_error is set and return false
static bool	check_args(int ac, char** av)
{
	(void)ac;(void)av;
	return true;
}

// Initialize game struct and allocate necessary resources. If fails for any reason,
// g_error is set and return false
static bool	init_game(int nrows, int ncols)
{
	srand(time(NULL));	// Generate random seed
	game.nrows = nrows;
	game.ncols = ncols;
	game.player = (rand() % 2) ? PLAYER_AI : PLAYER_HUMAN;
	game.count = 0;
	game.board = ft_gc_malloc(sizeof(int) * nrows * ncols);
	if (!game.board)
	{
		g_error = "Cannot allocate game state";
		return false;
	}
	ft_bzero(game.board, sizeof(int) * nrows * ncols);
	return true;
}

int	main(int ac, char** av)
{
	if (!check_args(ac, av))
		return print_error_exit();

	if (!init_game(ft_atoi(av[1]), ft_atoi(av[2])))
		return print_error_exit();

	if (!game_loop())
		return print_error_exit();

	ft_gc_free_all();
	return 0;
}

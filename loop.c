#include "connect4.h"

static int	human_play()
{
	int	move;

	do
	{
		ft_putstr_fd("Enter a valid move: ", 1);
	}
	while (scanf("%d", &move) != 1);

	return move;
}

bool	game_loop()
{
	int	move;

	while (!game.ended)
	{
		if (game.player == PLAYER_HUMAN)
		{
			print_state();
			move = human_play();
			print_state();
		}
		else
		{
			ft_printf("AI thinking...\n");
			move = ai_play();
			ft_printf("AI played %d\n\n", move);
		}
		play(move);
	}

	if (game.winner)
		ft_printf("The winner is %s\n", (game.winner == PLAYER_HUMAN) ? "YOU! Congrats." : "COMPUTER. Haha");

	return true;
}

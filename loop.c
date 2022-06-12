#include "connect4.h"


static char	*get_line()
{
	char	buf[2];
	char	*move = "";
	long	r_byte;

	while (1)
	{
		r_byte = read(0, buf, 1);
		if (!r_byte || buf[0] == '\n')
			break;
		buf[1] = 0;
		move = ft_strjoin(move, buf);
		if (!move)
			return NULL;
	}
	return (move);
}

static int	human_play()
{
	int	move = -1;
	char	*buf;

	while (move < 0)
	{
		ft_putstr_fd("\n\n	Enter a valid move: ", 1);
		buf = get_line();
		if (!buf)
		{
			g_error = "Not enough memory for the game";
			return -1;
		}
		move = ft_atoi(buf);
		if (!(move >= 0 && move < game.ncols))
		{
			move = -1;
			ft_putstr_fd("\n	\033[96mWrong move\033[0m\n", 1);
		}
	}
	return move;
}

bool	game_loop()
{
	int	move = -1;
	print_state();
	while (!game.ended)
	{
		if (game.player == PLAYER_HUMAN)
			move = human_play();
		else
		{
			ft_printf("\n	AI thinking...\n");
			move = ai_play();
			ft_printf("\n	AI played %d\n\n", move);
		}

		if (move >= 0)
		{
			if (play(move))
				print_state();
			else
				ft_printf("Invalid move. Try again\n");
		}
		else
			return false;
	}

	if (game.winner)
		ft_printf("\n	\033[1;36mThe winner is %s\033[0m\n\n", (game.winner == PLAYER_HUMAN) ? "YOU! Congrats." : "COMPUTER. Haha");

	return true;
}

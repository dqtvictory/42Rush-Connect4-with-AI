#include "connect4.h"


static char	*get_line()
{
	char buf[2];
	char *move = "";
	int	r_byte;
	int	i = 0;

	while (1)
	{
		r_byte = read(0, buf, 1);
		if (!r_byte || buf[0] == 10)
			break;
		buf[1] = 0;
		move = ft_strjoin(move, buf);
	}
	return (move);
}

static int	human_play()
{
	int	move = -1;
	char	*buf;

	while (move < 0)
	{
		ft_putstr_fd("Enter a valid move: ", 1);
		buf = get_line();
		move = ft_atoi(buf);
		if (!(move >= 0 && move < game.ncols))
		{
			move = -1;
			ft_putstr_fd("\033[96mWrong move\033[0m\n", 1);
		}
	}
		return move;
}

bool	game_loop()
{
	int	move;
	print_state();
	while (!game.ended)
	{
		if (game.player == PLAYER_HUMAN)
			move = human_play();
		else
		{
			ft_printf("AI thinking...\n");
			move = ai_play();
			ft_printf("AI played %d\n\n", move);
		}
		if (move >= 0)
		{
			int row = col_to_row(move);
			if (play(move))
			{
				print_state();
				if (winning(get_idx(row, move)))
					game.ended = true;
			}
		}
	}

	if (game.winner)
		ft_printf("The winner is %s\n", (game.winner == PLAYER_HUMAN) ? "YOU! Congrats." : "COMPUTER. Haha");

	return true;
}

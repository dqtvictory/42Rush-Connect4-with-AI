#include "connect4.h"

bool    check(int i)
{
    int max = game.ncols > game.nrows ? game.ncols : game.nrows;
    int point_h = 1;    //horizontal check
    int point_v = 1;    //vertical
    int point_s = 1;    //slash
    int point_b = 1;    //backslash
    int brk = 510510;

    for (int j = 1; j < max; j++)
    {
        if (!(brk % 2) && game.board[i + j] == game.board[i] && j < (game.ncols - get_col(i)))
            point_h ++;
        else if (!(brk % 2)) brk /= 2;

        if (!(brk % 3) && game.board[i - j] == game.board[i] && j <= (get_col(i)))
            point_h ++;
        else if (!(brk % 3)) brk /= 3;

        if (!(brk % 5) && game.board[i - j * game.ncols] == game.board[i]
            && get_row(i - j * game.ncols) < get_row(i) && i - j * game.ncols >= 0)
            point_v ++;
        else if (!(brk % 5)) brk /= 5;

        if (!(brk % 7) && game.board[i - j * (game.ncols + 1)] == game.board[i]
            && get_row(i - j * (game.ncols - 1)) >= 0
            && get_col(i - j * (game.ncols - 1)) < get_col(i))
            point_s ++;
        else if (!(brk % 7)) brk /= 7;

        if (!(brk % 11) && game.board[i + j * (game.ncols + 1)] == game.board[i]
            && get_col(i + j * (game.ncols + 1)) > get_col(i)
            && get_row(i + j * (game.ncols + 1)) < game.nrows)
            point_s ++;
        else if (!(brk % 11)) brk /= 11;

        if (!(brk % 13) && game.board[i + j * (game.ncols - 1)] == game.board[i]
            && get_row(i + j * (game.ncols - 1)) < game.nrows
            && get_col(i + j * (game.ncols - 1)) < get_col(i))
            point_b ++;
        else if (!(brk % 13)) brk /= 13;

        if (!(brk % 17) && game.board[i - j * (game.ncols - 1)] == game.board[i]
            && get_row(i - j * (game.ncols - 1)) >= 0
            && get_col(i - j * (game.ncols - 1)) > get_col(i))
            point_b ++;  
        else if (!(brk % 17)) brk /= 17;

        if (point_h >= 4 || point_v >= 4 || point_s >= 4 || point_b >= 4)
        {
            game.winner = game.board[i];
            return true;
        }
    }

    return false;
}

bool    winning(int idx)
{
    if (check(idx))
        return true;

    return false;
}
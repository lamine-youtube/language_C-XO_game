#include <stdio.h>

void draw_board(int *info)
{
    for (int i = 0; i < 3; i++)
    {
        printf("\n------------- \n");

        printf("|");
        for (int j = 0; j < 3; j++)
        {
            if (info[i * 3 + j] == 1)
                printf(" X ");
            else if (info[i * 3 + j] == -1)
                printf(" O ");
            else if (info[i * 3 + j] == 0)
                printf("   ");

            printf("|");
        }
    }
    printf("\n------------- \n");
}

int valid_place(int *info, int chios)
{
    if (chios > 9 || chios < 1)
        return 0;

    if (info[chios - 1] != 0)
        return 0;
    else
        return 1;
}

int win(int *info)
{
    if (
        (info[0] == info[1] && info[1] == info[2] && info[2] != 0) ||
        (info[3] == info[4] && info[4] == info[5] && info[5] != 0) ||
        (info[6] == info[7] && info[7] == info[8] && info[8] != 0) ||
        (info[0] == info[3] && info[3] == info[6] && info[6] != 0) ||
        (info[1] == info[4] && info[4] == info[7] && info[7] != 0) ||
        (info[2] == info[5] && info[5] == info[8] && info[8] != 0) ||
        (info[0] == info[4] && info[4] == info[8] && info[8] != 0) ||
        (info[2] == info[4] && info[4] == info[6] && info[6] != 0))
        return 1;
    else
        return -1;
}

int main()
{
    int info[9] = {0};

    int i;
    for (i = 0; i < 9; i++)
    {
        draw_board(info);

        // check for winner //
        if (win(info) == 1)
        {
            if (i % 2 != 0)
                printf("\nPlayer 01 win");
            else
                printf("\nPlayer 02 win");

            break;
        }

        int chios;
        while (1)
        {
            // print player message //
            if (i % 2 == 0)
            {
                printf("Enter chios Player 01: ");
            }
            else
            {
                printf("Enter chios Player 02: ");
            }

            scanf("%d", &chios);

            if (valid_place(info, chios) == 1)
                break;
        }

        // update the info board //
        if (i % 2 == 0)
        {
            info[chios - 1] = 1;
        }
        else
        {
            info[chios - 1] = -1;
        }
    }

    if (i >= 9)
    {
        draw_board(info);
        printf("\nDraw");
    }

    return 0;
}
#include <stdio.h>

struct Player
{
    int number;
    struct Player *next;
};

int main(void)
{
    int n;
    printf("Number of players: "); scanf("%d", &n);
    struct Player players[n], *player_prev, *player_curr=players+n-1;
    for (int i=0; i<n; i++)
    {
        players[i].number=i+1;
        players[i].next=players+i+1;
    }
    players[n-1].next=players;
    do
    {
        for (int i=0; i<3; i++)
        {
            player_prev = player_curr;
            player_curr = player_curr->next;
        }
        player_prev->next = player_curr->next;
    } while(player_prev != player_prev->next);
    printf("The last alive is %d", player_prev->number);
    return 0;
}

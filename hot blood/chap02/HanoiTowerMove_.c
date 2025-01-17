#include <stdio.h>

void HanoiTowerMove (int, char, char, char);

int main(void)
{

    HanoiTowerMove(4, 'A', 'B', 'C');

    return 0;
}

void HanoiTowerMove (int num, char from, char by, char to){
    if (num == 1)
        printf("원판 1를 %c에서 %c로 이동\n", from, to);
    else
    {
        HanoiTowerMove(num - 1, from, to, by);
        printf("원판 %d를 %c에서 %c로 이동\n", num, from, to);
        HanoiTowerMove(num - 1, by, from, to);
    }
}
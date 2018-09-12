#include <stdio.h>
#include <stdlib.h>
char answ;
int row, coloumn, k,  score1=0 , score2=0, score3=0, score4=0, result;
int matrix[4][4]={0};
void greetings(){
    printf("-----------------------------------------\n");
    printf("|                  WELCOME              |\n");
    printf("|                 2048 GAME             |\n");
    printf("|               MADE BY OMERG           |\n");
    printf("-----------------------------------------\n");
    printf("PRESS ANY KEY TO START THE GAME...");
    answ = getch();
}
char quest(){
    answ = getch();
        return answ;
}
void add_number(){
   while(1){
        row = rand()%4;
        coloumn = rand()%4;
    if(matrix[row][coloumn]==0){
        matrix[row][coloumn]= (((rand() % 2) + 1) * 2);
    break;
    }
    }
}
void move_left(){
   for (row = 0; row < 4; row++)
    {
            for (coloumn = 1; coloumn <4; coloumn++)
            {
                if (matrix[row][coloumn] == 0)
                {
                    continue;
                }
                if (matrix[row][coloumn - 1] == 0 || matrix[row][coloumn - 1] == matrix[row][coloumn])
                {
                    matrix[row][coloumn - 1] = matrix[row][coloumn - 1] + matrix[row][coloumn];
                    matrix[row][coloumn] = 0;
                    score1+= matrix[row][coloumn-1];
                    row = 0;
                    coloumn = 1;
                    break;
                }
            }
    }
}
void move_right(){
    for(row=0;row<4;row++){
        for(coloumn=3;coloumn>=0;coloumn--)
            if(matrix[row][coloumn]==0)
                for(k=coloumn-1;k>=0;k--)
                    if(matrix[row][k]!=0){
                        matrix[row][coloumn]=matrix[row][k];
                        matrix[row][k]=0;
                        coloumn--;
        }
    }
    for(row=0;row<4;row++)
        for(coloumn=3;coloumn>=0;coloumn--)
            if(matrix[row][coloumn]==matrix[row][coloumn-1]){
                matrix[row][coloumn]=2*matrix[row][coloumn];
                score2+= matrix[row][coloumn];
                for(k=coloumn-1;k>0;k--)
                    matrix[row][k]=matrix[row][k-1];
                    matrix[row][0]=0;

        }
}
void move_up(){
    for (row = 1; row < 4; row++)
    {   for (coloumn = 0; coloumn < 4; coloumn++)
        {   if (matrix[row][coloumn] == 0)
            {
                continue;
            }
            if (matrix[row - 1][coloumn] == 0 || matrix[row - 1][coloumn] == matrix[row][coloumn] )
            {
                matrix[row - 1][coloumn] = matrix[row - 1][coloumn] + matrix[row][coloumn];
                matrix[row][coloumn] = 0;
                score3+= matrix[row-1][coloumn];
                row = 0;
                coloumn = 0;
                break;
            }
        }
    }
}
void move_down(){
    for (row = 0; row < 3; row++)
    {
            for (coloumn = 0; coloumn < 4; coloumn++)
             {
                if (matrix[row][coloumn] == 0)
                {
                    continue;
                }
                if (matrix[row + 1][coloumn] == 0 || matrix[row + 1][coloumn] == matrix[row][coloumn])
                {
                    matrix[row + 1][coloumn] = matrix[row + 1][coloumn] + matrix[row][coloumn];
                    matrix[row][coloumn] = 0;
                    score4+= matrix[row+1][coloumn];
                    row = 0;
                    coloumn = 0;
                }
            }
        }
}
void grid(){

    for(row=0; row<4; row++){
            printf("\n");
        for(coloumn=0; coloumn<4; coloumn++){
            matrix[row][coloumn];
            printf("| %d |",matrix[row][coloumn]);
        }
    }
}
void choise(){
    switch(answ)
    {
        case 'a': move_left();
        break;
        case 'd': move_right();
        break;
        case 'w': move_up();
        break;
        case 's': move_down();
        break;

    }
}
void scoresum(){
    result= score1 + score2 + score3 + score4;
    printf("\nExit: e                   Score : %d", result);
}
int main(){

        greetings();
        if(answ!=0)
        {
            system("cls");
            while(1)
            {
                grid();
                scoresum();
                quest();
                choise();
                if(answ == 'e')
                    break;
                add_number();
                system("cls");
            }


    }
    return 0;
}


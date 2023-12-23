#include <stdio.h>

int victoryCheck(const char crosses[][3], int gamer);
int checkPrompt(const char prompt[]);

void inputPrompt(char crosses[][3],const char prompt[], int gamer);

int main(void){
    char crosses[3][3] = {{"---"}, {"---"}, {"---"}};
    char prompt[100];

    int ending = 0;
    int gamer = 1;
    int typeLoop = 0;

    while(ending == 0){
        printf(" \t1\t2\t3\t \n A\t%c\t%c\t%c\t \n B\t%c\t%c\t%c\t \n C\t%c\t%c\t%c\t \n",crosses[0][0], crosses[0][1], crosses[0][2], crosses[1][0], crosses[1][1], crosses[1][2], crosses[2][0], crosses[2][1], crosses[2][2]);       
        printf("\nPlayer %d give your coordinate: ", gamer);
        scanf("%s", prompt);
        while (getchar() != '\n');
        
        while(typeLoop == 0){
            if(checkPrompt(prompt)==1){
                typeLoop = 1;
            }
            else{
                printf("Enter the coordinate in the correct form:  ");
                scanf("%s", prompt);
                while (getchar() != '\n');             
            }
        }

        typeLoop = 0;

        inputPrompt(crosses, prompt, gamer);

        if(victoryCheck(crosses, gamer)==1){
            printf("\nPlayer %d wins!\n", gamer);
            ending = 1;
        }

        if(gamer == 1){
            gamer = 2;
        }
        else{
            gamer = 1;
        }
    
    }

    
    return(0);
}

int checkPrompt(const char prompt[]){
    int returnValue = 0;

    if(prompt[0]=='A' || prompt[0]=='B' || prompt[0]=='C'){
        if(prompt[1]=='1' || prompt[1]=='2' || prompt[1]=='3'){
            returnValue = 1;
        }

    }
    return(returnValue);

}

void inputPrompt(char crosses[][3],const char prompt[], int gamer){
    int row;
    int column;
    switch (prompt[0])
    {
    case 'A':
        row = 0;
        break;
    case 'B':
        row = 1;
        break;
    case 'C':
        row = 2;
        break;
    
    default:
        break;
    }
    switch (prompt[1])
    {
    case '1':
        column = 0;
        break;
    case '2':
        column = 1;
        break;
    case '3':
        column = 2;
        break;
    
    default:
        break;
    }
    if(gamer == 1){
        crosses[row][column] = 'X';
    }
    else{
        crosses[row][column] = 'O';
    }

}

int victoryCheck(const char crosses[][3], int gamer){
    int returnValue = 0;
    char check;
    if(gamer == 1){
        check = 'X';
    }
    else{
        check = 'O';
    }


    for (int i = 0; i < 3; i++){
        if(crosses[i][0]==check && crosses[i][1]==check && crosses[i][2]==check){
            returnValue = 1;
        }
        
    }
    for (int i = 0; i < 3; i++){
        if(crosses[0][i]==check && crosses[1][i]==check && crosses[2][i]==check){
            returnValue = 1;
        }
        
    }
    if(crosses[0][0]==check && crosses[1][1]==check && crosses[2][2]==check){
        returnValue = 1;
    }
    if(crosses[0][2]==check && crosses[1][1]==check && crosses[2][0]==check){
        returnValue = 1;
    }
    return(returnValue);
    
}
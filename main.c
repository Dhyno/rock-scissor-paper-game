#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>


struct data{

    char* things[3];

    short player1_win;
    short player2_win;
    short draw;

    char* player1_name;
    char* player2_name;

    char* player1_input;
    char* player2_input;

    short round;

} game_data;



void container();

void initiate();
void intro();
void set_player();
void play_game();
bool check();
void is_win();

void delete_all();

int main()
{
    while(true){

        container();
        system("cls");

        intro();

        printf("game is over\\n\n\n");

        if(game_data.player1_win>game_data.player2_win)
            printf("player 1 is winnner\n\n");
        else if(game_data.player1_win<game_data.player2_win)
             printf("player 2 is winnner\n\n");
        else
             printf("draw game\n\n");

        printf("start a new game? y/n");

        if(getch()!='y')
            break;

        delete_all();
        system("cls");
    }

    return 0;

}

void container(){

    initiate();
    set_player();

    char repeat;
    while(true)
    {
        system("cls");
        play_game();

        if(!check()){printf("invalid input\n\n");getch();
            continue;
        };

        is_win();
        fflush(stdin);

        printf("\n\n\n\n");

        printf("play again? y/n");
        scanf("%c", &repeat);
        if( repeat !='y' )
            break;
    }

}

void intro(){

    printf("------------------------------------------\n");
    printf("simple rock scissor paper game\n");
    printf("------------------------------------------\n");
    if(game_data.player1_name==NULL)
        printf("player 1\t\tplayer 2\n...........................................\n");
    else{
        printf("%s: %d", game_data.player1_name, game_data.player1_win);
        printf("\t\t%s: %d", game_data.player2_name,game_data.player2_win);
        printf("\t\tgame: %d\n", game_data.round);
        printf("...........................................\n");
    }
    printf("1.rock\t2.scissor\t3.paper\n\n");

}

void initiate(){

    for(int i=0; i<3; i++)
        game_data.things[i]=(char*)malloc(10*sizeof(char));
    strcpy(game_data.things[0],"rock");
    strcpy(game_data.things[1],"scissor");
    strcpy(game_data.things[2],"paper");

    game_data.player1_input=(char*)malloc(10*sizeof(char));
    game_data.player2_input=(char*)malloc(10*sizeof(char));

    game_data.player1_name=NULL;
    game_data.player2_name=NULL;

    game_data.player1_win=0;
    game_data.player2_win=0;
    game_data.draw=0;

    game_data.round=0;
}

void delete_all()
{
    for(int i=0; i<3; i++)
        free(game_data.things[i]);

    free(game_data.player1_input);
    free(game_data.player2_input);

    free(game_data.player1_name);
    free(game_data.player2_name);
}

void set_player(){

    intro();

    game_data.player1_name=(char*)malloc(20*sizeof(char));
    game_data.player2_name=(char*)malloc(20*sizeof(char));

    printf("player 1 Name: ");
    scanf("%s", game_data.player1_name);

    printf("player 2 Name: ");
    scanf("%s", game_data.player2_name);
    system("cls");

}

void play_game(){

    intro();
    printf("player 1: ");
    scanf("%s", game_data.player1_input);

    printf("player 2: ");
    scanf("%s", game_data.player2_input);
}

bool check(){

    bool p1_valid=false;
    bool p2_valid=false;

    for(short i=0; i<3; i++){
        if(!p1_valid)
            p1_valid=(strcmp(game_data.things[i],game_data.player1_input)==0)? true : false;
        if(!p2_valid)
            p2_valid=(strcmp(game_data.things[i],game_data.player2_input)==0)? true : false;

        if(p1_valid && p2_valid) return true;
    }
    return false;
}

void is_win()
{
    game_data.round+=1;
    if(strcmp(game_data.player1_input,game_data.things[0])==0){

        if(strcmp(game_data.player2_input,game_data.things[1])==0){
            printf("player 1 win\n");
            game_data.player1_win+=1;
        }

        else if(strcmp(game_data.player2_input,game_data.things[2])==0){
            printf("player 2 win\n");
            game_data.player2_win+=1;
        }

        return;
    }

    else if(strcmp(game_data.player1_input,game_data.things[1])==0){

       if(strcmp(game_data.player2_input,game_data.things[0])==0){
            printf("player 2 win\n");
            game_data.player1_win+=1;
        }

        else if(strcmp(game_data.player2_input,game_data.things[2])==0){
            printf("player 1 win\n");
            game_data.player2_win+=1;
        }

        return;
    }

    else if(strcmp(game_data.player1_input,game_data.things[2])==0){

        if(strcmp(game_data.player2_input,game_data.things[0])==0){
            printf("player 1 win\n");
            game_data.player1_win+=1;
        }

        else if(strcmp(game_data.player2_input,game_data.things[1])==0){
            printf("player 2 win\n");
            game_data.player2_win+=1;
        }

        return;
    }

    printf("draw game\n");
}











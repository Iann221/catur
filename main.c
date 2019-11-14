#include <stdio.h>
#include "fungsi.h"
#include "tipe_bentukan.h"

#include "print_papan.c"

int main(){
    F.nama = 'K';
    F.poin = 1;
    F.player = 1;
    F.posisiR = 2;
    F.posisiC = 2;

    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            board[i][j].nama = ' ';
        }
    }

    board[1][1].nama = 'P';
    board[1][1].player = 1;

    board[1][2].nama = 'P';
    board[1][2].player = 2;

    board[1][3].nama = ' ';
    board[1][3].player = 1;

    board[2][1].nama = ' ';
    board[2][1].player = 1;

    board[2][3].nama = 'Q';
    board[2][3].player = 1;
    
    board[3][1].nama = 'P';
    board[3][1].player = 2;

    board[3][2].nama = ' ';
    board[3][2].player = 2;

    board[3][3].nama = ' ';
    board[3][3].player = 1;

    CreateEmpty_stack(&history);
    CreateEmpty_stack(&termakan);
    CreateEmpty_list(&list_ada_putih);
    CreateEmpty_list(&list_ada_hitam);
    CreateEmpty_queue(&giliransiapa, 2);



    start();
    PrintPapan(board);

    printf("Masukkan command: ");
    scanf("%s",&command);

    if(command=="MOVE"){
        move(&board, &history, &termakan, &poin_putih, &poin_hitam, &list_ada_putih, &list_ada_hitam, giliransiapa);
    }



    return 0;
}



void start () {
    printf("********************************************************************************\n");
    printf("********************************************************************************\n");
    printf("**                                                                            **\n");
    printf("**                                                                            **\n");
    printf("**               ccccc    hh    hh    eeeeee    ssssss   ssssss               **\n");
    printf("**              cc        hh    hh    ee        ss       ss                   **\n");
    printf("**             cc         hhhhhhhh    eeeeee    ssssss   ssssss               **\n");
    printf("**              cc        hh    hh    ee            ss       ss               **\n");
    printf("**               ccccc    hh    hh    eeeeee    ssssss   ssssss               **\n");
    printf("**                                                                            **\n");
    printf("**                                                                            **\n");
    printf("**                                                                            **\n");
    printf("**                                 Let's Play                                 **\n");
    printf("**                                                                            **\n");
    printf("**                                 1. New Game                                **\n");
    printf("**                                 2. Load Game                               **\n");
    printf("**                                                                            **\n");
    printf("********************************************************************************\n");
    printf("********************************************************************************\n");
}

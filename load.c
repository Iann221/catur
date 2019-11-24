#include "tipe_bentukan.h"
#include "mesin_kata.c"

void load (list *list_ada_putih , list *list_ada_hitam , int *poin_putih , int *poin_hitam , queue *giliran , stack *history , stack *termakan) {
    
    // load list_ada_putih
    char str[50]; // formatnya N|1|2|8|7|;
    char CC;
    static FILE *pita;
    int count = 0;
    int i;
    i = 0;
    int to_int;
    infotype_list temp_list;
    int temp_input;
    int l;
    strcpy(str,"save_file//list_ada_putih.txt");
    START(str);
    while (!IsEOP()) {
        CC = GetCC();
        printf("%c",CC);
        if (CC != '|') {
            i++;
            if ((i % 5) == 1) {
                temp_list.nama = CC;
            }
            else if ((i % 5) == 2) {
                to_int = CC - '0';
                temp_list.player = to_int;
            }
            else if ((i % 5) == 3) {
                ADVKATA();
                temp_input = 0;
                for (l = 1 ; l <= CKata.Length ; l++) {
                    to_int = CKata.TabKata[l] - '0';
                    temp_input = 10*temp_input + to_int;
                }
                temp_list.poin = temp_input;
            }
            else if ((i % 5) == 4) {
                to_int = CC - '0';
                temp_list.posisiR = to_int;
            }
            else {
                to_int = CC - '0';
                temp_list.posisiC = to_int;
                InsVLast(list_ada_putih,temp_list);
            }
        }
        ADV();
    }
    printf("\n");
    printf("%c\n",temp_list.nama);
    printf("%d\n",temp_list.player);
    printf("%d\n",temp_list.poin);
    printf("%d\n",temp_list.posisiR);
    printf("%d\n",temp_list.posisiC);
    printf("\n");
    
    

    // load list_ada_hitam
    i = 0;
    strcpy(str,"save_file//list_ada_hitam.txt");
    START(str);
    while (!IsEOP()) {
        CC = GetCC();
        printf("%c",CC);
        if (CC != '|') {
            i++;
            if ((i % 5) == 1) {
                temp_list.nama = CC;
            }
            else if ((i % 5) == 2) {
                to_int = CC - '0';
                temp_list.player = to_int;
            }
            else if ((i % 5) == 3) {
                ADVKATA();
                temp_input = 0;
                for (l = 1 ; l <= CKata.Length ; l++) {
                    to_int = CKata.TabKata[l] - '0';
                    temp_input = 10*temp_input + to_int;
                }
                temp_list.poin = temp_input;
            }
            else if ((i % 5) == 4) {
                to_int = CC - '0';
                temp_list.posisiR = to_int;
            }
            else {
                to_int = CC - '0';
                temp_list.posisiC = to_int;
                InsVLast(list_ada_hitam,temp_list);
            }
        }
        ADV();
    }
    printf("\n");
    printf("%c\n",temp_list.nama);
    printf("%d\n",temp_list.player);
    printf("%d\n",temp_list.poin);
    printf("%d\n",temp_list.posisiR);
    printf("%d\n",temp_list.posisiC);
    printf("\n");
    
    // load poin_putih , poin_hitam , giliran
    // int poin_putih = 0;
    // int poin_hitam = 0;
    int giliran_siapa;
    strcpy(str,"save_file//poin.txt");
    STARTKATA(str); // window di |
    temp_input = 0;
    for (l = 1 ; l <= CKata.Length ; l++) {
        to_int = CKata.TabKata[l] - '0';
        temp_input = 10*temp_input + to_int;
    }
    *poin_putih = temp_input;
    ADV(); // window di 6
    ADVKATA(); // window di |
    temp_input = 0;
    for (l = 1 ; l <= CKata.Length ; l++) {
        to_int = CKata.TabKata[l] - '0';
        temp_input = 10*temp_input + to_int;
    }
    *poin_hitam = temp_input;
    ADV(); // window di 1
    CC = GetCC();
    to_int = CC - '0';
    giliran_siapa = to_int;
    if (giliran_siapa == 1) {
        Add(giliran, 1);
    }
    else {
        Add(giliran, 2);
    }
    ADV();
    printf("%d",*poin_putih);
    printf("%d",*poin_hitam);
    printf("%d",giliran_siapa);
    
    
    
    }
    // fclose(pita);




//     // load stack history
//     // formatnya P|1|32|5|5|7|7|1|0.;
//     // stack history;
//     stack reverse_history;
//     // CreateEmpty_stack(&history);
//     CreateEmpty_stack(&reverse_history);
//     infotype_stack temp_infostack;
//     strcpy(str,"save_file//history.txt");
//     START(str); // window di P
//     while (!EOP) {
//         CC = GetCC();
//         temp_infostack.nama = CC;
//         ADV(); // window di |
//         ADV(); // window di 1
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.player = to_int;
//         ADV(); // window di |
//         ADV(); // window di 32
//         ADVKATA(); // window di |
//         temp_input = 0;
//         for (l = 1 ; l <= CKata.Length ; l++) {
//             to_int = CKata.TabKata[i] - '0';
//             temp_input = temp_input*10 + to_int;
//         }
//         temp_infostack.poin = temp_input;
//         ADV(); // window di 5
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.posisiR_lama = to_int;
//         ADV(); // window di |
//         ADV(); // window di 5
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.posisiC_lama = to_int;
//         ADV();
//         ADV(); // window di 7
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.posisiR_baru = to_int;
//         ADV();
//         ADV(); // window di 7
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.posisiC_baru = to_int; 
//         ADV();
//         ADV(); // window di 1
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.promotion = to_int;
//         ADV();
//         ADV(); // window di 0
//         temp_infostack.twosteps = to_int;
//         ADV();
//         ADV(); // window di ; atau nama bidak
//         Push(&reverse_history,temp_infostack);
//     }
//     while (!IsEmpty_stack(reverse_history)) {
//         Pop(&reverse_history,&temp_infostack);
//         Push(history,temp_infostack);
//     }
    


//     // load stack termakan
//     // formatnya P|1|32|5|5|7|7|1|0.;
//     // stack termakan;
//     stack reverse_termakan;
//     // CreateEmpty_stack(&termakan);
//     CreateEmpty_stack(&reverse_termakan);
//     // infotype_stack temp_infostack;
//     strcpy(str,"save_file//termakan.txt");
//     START(str); // window di P
//     while (!EOP) {
//         CC = GetCC();
//         temp_infostack.nama = CC;
//         ADV(); // window di |
//         ADV(); // window di 1
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.player = to_int;
//         ADV(); // window di |
//         ADV(); // window di 32
//         ADVKATA(); // window di |
//         temp_input = 0;
//         for (l = 1 ; l <= CKata.Length ; l++) {
//             to_int = CKata.TabKata[i] - '0';
//             temp_input = temp_input*10 + to_int;
//         }
//         temp_infostack.poin = temp_input;
//         ADV(); // window di 5
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.posisiR_lama = to_int;
//         ADV(); // window di |
//         ADV(); // window di 5
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.posisiC_lama = to_int;
//         ADV();
//         ADV(); // window di 7
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.posisiR_baru = to_int;
//         ADV();
//         ADV(); // window di 7
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.posisiC_baru = to_int; 
//         ADV();
//         ADV(); // window di 1
//         CC = GetCC();
//         to_int = CC - '0';
//         temp_infostack.promotion = to_int;
//         ADV();
//         ADV(); // window di 0
//         temp_infostack.twosteps = to_int;
//         ADV();
//         ADV(); // window di ; atau nama bidak
//         Push(&reverse_history,temp_infostack);
//     }
//     while (!IsEmpty_stack(reverse_termakan)) {
//         Pop(&reverse_termakan,&temp_infostack);
//         Push(termakan,temp_infostack);
//     }
// }


// // int main () {
// //     char str[50];
// // 	char CC;
// // 	static FILE *pita;
// //     list A; // list yang dimaksud
// //     CreateEmpty_list(&A); // buat gampang overwritenya
// // 	strcpy(str,"contohList.txt");
// //     pita = fopen(str,"r");
// //     int retval;
// //     retval = fscanf(pita,"%c",&CC);
// //     while (CC != '|') {
// //         printf("%c",CC);
// //         retval = fscanf(pita,"%c",&CC);
// //     }
// //     printf("\n");
// //     fclose(pita);
// //     pita = fopen(str,"r");
// //     retval = fscanf(pita,"%c",&CC);
// //     int temp;
// // 	while (CC != '|') {
// //         if (CC != ' ') {
// //             temp = CC - '0'; // karena disimpan dalam ascii jadi harus dicasting
// //             InsVLast(&A,temp);
// //         }
// //         retval = fscanf(pita,"%c",&CC);
// //     }
// //     address P;
// //     P = First(A);
// //     while (P != Nil) {
// //         printf("%d ",Info(P));
// //         P = Next(P);
// //     }
// // 	printf("\n");
	
// // 	return 0;
// // }
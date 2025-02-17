#include <stdio.h>

int trierTableau(int tab[], int tab2[], int taille){

    int i = 0, stock;
    for(i = 0; i < taille; i++){

        tab[i] = stock;

        if(tab[i] > tab[i+1]){

            tab[i+1] = tab[i];
            stock = tab[i+1];

        }else if(tab[i] < tab[i+1]){

            //printf("R.A.S\n");
            
        }else{

            printf("Non reconnu!\n");
            break;
        }

        printf("Ordre croissant : %d\t", tab[i]);
    }


}


int main(){

    int ascending_tab[5], tab_length = 5, spawn;
    int user_input[5], i = 0;
    printf("Veuillez rentrer 5 valeurs différentes.\n");

    for(i = 0; i < 5; i++){

        scanf("%d", &user_input[i]);
    }

    spawn = trierTableau(user_input, ascending_tab, tab_length);

    /*for(i = 0; i < 5; i++){

        printf("tab: %d\t", trierTableau(user_input, ascending_tab, tab_length));

    }*/

    return 0;
}


















/* exo swap valeurs fonctions avec pointeurs;
int swap(int *a, int *b){

    int swapping;
    swapping = *a;
    *a = *b;
    *b = swapping;



}


int main(){

    int test;
    int user_inputA = 10, user_inputB = 20;
    int *pUser_inputA, *pUser_inputB;
    pUser_inputA = &user_inputA;
    pUser_inputB = &user_inputB;
    test = swap(&user_inputA, &user_inputB);
    printf("a = %d\t b = %d\n", user_inputA, user_inputB);

    return 0;
}*/













/* EXO AFFICHAGE INVERSÉ D'UN TABLEAU DE INT
void inversion(int tab[], int tab2[],int len){

    int i = len, j = 0;

    for(i = len; i >= 0; i--){

        tab2[j] = tab[i];
        j++;
    }

    return;

}

int main(){

    int i = 0;
    int swap[5];
    int user_input[5];
    printf("Rentrez 5 valeurs :\n");

    for(i = 0; i < 5; i++){

        scanf("%d", &user_input[i]);
    }

    inversion(user_input, swap);
    printf("Voici vos valeurs inversées :\n");

    for(i = 0; i < 5; i++){

        printf("%d\t", swap[i]);
    }
    
    return 0;
}*/
#include <stdio.h>

void tab_swap(int tab[], int taille){

    int i, j, temporaire;


        for(i = 0; i < taille; i++){

            for(j = i + 1; j < taille; j++){

                if(tab[i] > tab[j]){

                    temporaire = tab[i];
                    tab[i] = tab[j];
                    tab[j] = temporaire;
                }
            }
        }


}




int main(){

    int tableau[8];
    int i, j, temporaire, length = 8;

    printf("Veuillez saisir 8 valeurs :\n");

    for(i = 0; i < 8; i++){

        scanf("%d", &tableau[i]);
    }

    tab_swap(tableau, length);

    printf("Voici les valeurs que vous avez saisies dans l'ordre croissant :\n");
    
    for(i = 0; i < 8; i++){

        printf("%d\t", tableau[i]);
    }


    return 0;
}
    // for(i = 0; i < 8; i++){

    //     for(j = i + 1; j < 8; j++){

    //         if(tab[i] > tab[j]){

    //             temporaire = tab[i];
    //             tab[i] = tab[j];
    //             tab[j] = temporaire;
    //         }
    //     }
    // }










/*
void trierTableau(int tableau[], int taille) {
    int i, j;
    int plus_petit;
    int swap_temporaire;

    for (i = 0; i < taille - 1; i++) {
        plus_petit = i;
        
        // On cherche le plus petit élément dans le reste du tableau
        for (j = i + 1; j < taille; j++) {
            if (tableau[j] < tableau[plus_petit]) {
                plus_petit = j;
                printf("Test 2eme boucle for!\n");
            }
        }
        
        // On échange UNIQUEMENT si nécessaire
        if (plus_petit != i) {
            swap_temporaire = tableau[i];
            tableau[i] = tableau[plus_petit];
            tableau[plus_petit] = swap_temporaire;
        }
    }
}*/
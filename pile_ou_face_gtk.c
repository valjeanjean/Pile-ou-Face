#include <stdio.h>

float calcul_moyenne(float tab[], int taille){

    int i;
    float stock = 0;  // Changer int en float
    for(i = 0; i < taille; i++){  // Condition correcte pour parcourir tout le tableau
        stock = stock + tab[i];
        printf("tab[%d] = %f\n", i, tab[i]);  // Affichage avec l'indice
        printf("stock = %f\n", stock);  // Affichage avec %f car stock est un float
    }
    
    printf("tab[%d] = %f\n", i, tab[i]);  // Affichage de la dernière valeur (si nécessaire)
    printf("stock = %f\n", stock);  // Affichage de la somme finale

    return stock / taille;  // On peut retourner directement la moyenne
}

int main(){

    float notes[3], calcul1;
    int i = 0;
    printf("Rentrez vos notes :\n");
    for(i = 0; i < 3; i++){
        scanf("%f", &notes[i]);
    }
    calcul1 = calcul_moyenne(notes, 3);
    printf("Votre moyenne est de %f\n", calcul1);

    return 0;
}

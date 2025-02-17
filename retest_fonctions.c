#include <stdio.h>





int main(){

int i, taille = 5, j, stock, stock2, plus_petit;
int tableau[5];

printf("Rentrez 5 valeurs\n");

for(i = 0; i < 5; i++){

    scanf("%d", &tableau[i]);
}


for(i = 0; i < taille - 1; i++){

    plus_petit = i;

    for(j = i + 1; j < taille; i++){

        if(tableau[j] < tableau[plus_petit]){

            plus_petit = j + 1;
        }
    }
}


}




















/* EXO CALCUL PUISSANCE 

long int puissance(int base, int exposant){

    long int i, power = 1;
    for(i = 1; i <= exposant; i++){

        power = power * base;
    }

    return power;
}

int main(){

    int nombre, power;
    printf("Rentrez une valeur :\n");
    scanf("%d", &nombre);
    printf("Rentrez son exposant :\n");
    scanf("%d", &power);
    printf("%d ^ %d = %ld\n", nombre, power, puissance(nombre, power));

    return 0;
}
*/








/* Boucle for, avec i++, à la fin de la boucle mettre j = i, faire une autre
 boucle avec j-- pour l'affichage */ 

















/* Exo compteur voyelle dans une chaine de caractères

int compteVoyelles(char chaine[]){

    int i, compteur_voyelles;
    char voyelles[] = "aAeEiIoOuUyY";

   
        for(i = 0; i < 12; i++){

            if(chaine[i] == 'a'|| chaine[i] == 'A' || chaine[i] == 'e' || chaine[i] == 'E' || chaine[i] == 'i' || chaine[i] == 'I' || chaine[i] == 'o' || chaine[i] == 'O' || chaine[i] == 'u' || chaine[i] == 'U' || chaine[i] == 'y' || chaine[i] == 'Y' ){

                compteur_voyelles++;
                
            }
        }
    

    return compteur_voyelles;
}


int main(){

    char user_input[12];

    printf("Veuillez saisir une chaine de caractère :\n");
    scanf("%s", user_input);
    printf("Il y a %d voyelles dans votre phrase.\n", compteVoyelles(user_input));


    return 0;
}*/






















/* Calcul moyenne

float calcul_moyenne(float tab[], int taille){

    int i;
    float stock = 0;
    for(i = 0; i < taille; i++){

        stock = stock + tab[i];

    }

    return stock / taille;
}

int main(){

    float notes[3], calcul1;
    int i = 0;

    printf("Rentrez vos notes :\n");

        for(i = 0; i < 3; i ++){

            scanf("%f", &notes[i]);
        }

    //calcul1 = calcul_moyenne(notes, 3);
    
    printf("Votre moyenne est de %f\n", calcul_moyenne(notes, 3));
    
    return 0;
}*/
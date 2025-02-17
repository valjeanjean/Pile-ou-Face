#include <stdio.h>
#define pierre 1
#define feuille 2
#define ciseaux 3
#define SUM(x,y)    (x+y)

int verif(int atoiJ1, int atoiJ2){

    int sommeAtoi = 0;
    sommeAtoi = atoiJ1 + atoiJ2;

        if(atoiJ1 == atoiJ2){ // Égalité

            return 0;
        }

        if(sommeAtoi == 3 && atoiJ1 > 1){ // Cas où le coup joué est pierre vs feuille avec J1 jouant feuille (J1 gagne)

            return 1; // J1 gagne

        }else if(sommeAtoi == 3 && atoiJ2 > 1){ // Cas où le coup joué est pierre vs feuille avec J2 jouant feuille (J2 gagne)

            return 2; // J2 gagne
        }

        if(sommeAtoi == 4 && atoiJ1 > 2){ // Cas où le coup joué est ciseaux vs pierre avec J1 jouant ciseaux (J2 gagne car la pierre (1) bat les ciseaux (3))

            return 2;

        }else if(sommeAtoi == 4 && atoiJ2 > 2){ // Cas où le coup joué est ciseaux vs pierre avec J2 jouant ciseaux (J1 gagne car la pierre (1) bat les ciseaux (3))

            return 1;
        }

        if(sommeAtoi == 5 && atoiJ1 > 2){ // Cas où le coup joué est Ciseaux vs Feuille avec J1 jouant Ciseaux (J1 gagne car les ciseaux coupent la feuille)

            return 1;

        }else if(sommeAtoi == 5 && atoiJ2 > 2){

            return 2;
        }

}

int main(){

    int stock = 10, atoi_player1 = -1, atoi_player2 = -1;
    int score_joueur1 = 0, score_joueur2 = 0;
    stock = verif(atoi_player1, atoi_player2);

    if(stock == 0){

        printf("ÉGALITÉ!\n");
        rappelScore();

    }else if(stock == 1){

        printf("Joueur 1 gagne!\n");
        score_joueur1++;
        rappelScore();

    }else if(stock == 2){

        printf("Joueur 2 gagne!\n");
        score_joueur2++;
        rappelScore();
    }



}

   



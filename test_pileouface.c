#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/random.h>
#include <unistd.h> 


#define pile 1
#define face 2
#define quit 0
#define browse_table 4 // constante pour nb à parcourir dans tableau

                // DÉCLARATION & INITIALISATION VARIABLES
/*-----------------------------------------------------------------------------------*/

int score_good_answer = 0, score_wrong_answer = 0, user_test_pile = 0, user_test_face = 0;

                // DÉCLARATION & INITIALISATION TABLEAUX
/*-----------------------------------------------------------------------------------*/

char user_choice[255]; 

/*Tableau différents orthographes PILE*/
char * comparaison_pile[browse_table] = { 

            "pile\n",
            "PiLe\n",
            "PILE\n",
            "pIlE\n",
};

/*Tableau différents orthographes FACE*/
char * comparaison_face[browse_table] = { 

            "face\n",
            "FACE\n",
            "FaCe\n",
            "fAcE\n",
};

/*Tableau différents orthographes FACE*/
char * comparaison_quit[browse_table] = { 

            "quit\n",
            "exit\n",
            "QUIT\n",
            "EXIT\n",
};


                            // FONCTIONS D'AFFICHAGE
/*-----------------------------------------------------------------------------------*/

/*Affichage choix utilisateur*/
void choice(){

    printf("Pile ou Face ?\n");
    printf("1. Pile\n");
    printf("2. Face\n");
    printf("3. Quitter le jeu\n");
    fgets(user_choice, sizeof(user_choice), stdin);
    return;
    //fgets? fgets(p1ShiFuMi, sizeof(p1ShiFuMi), stdin);
}

/* Affichage de début de jeu */
void start_display(){

    printf("######## Pile ou Face ########\n\n");
}

/*Affichage lorsqu'il choisit PILE*/
void pile_display(){

    printf("Vous avez choisi PILE.\n\n");
}

/*Affichage lorsqu'il choisit FACE*/
void face_display(){

    printf("Vous avez choisi FACE.\n\n");
}

void separate_display(){

    printf("|-------------------------------|\n\n");
}

void dice_throw(){

    printf("La pièce est jetée\n\n");
}

/*Compteur de victoires & défaites*/
void is_correct_or_wrong(){

    printf("Réussite : %d\n", score_good_answer);
    printf("Échec : %d\n\n", score_wrong_answer);
}

/*Affichage lorsque le joueur décide de quitter le jeu*/
void leave_display(){

    printf("C'est PERDU, dommage...\n");
    //printf avec rappel du score
    separate_display();
}

/*Affichage de fin de partie*/
void end_display(){

    printf("########### GAME OVER ###########\n");

}

/*---------------------------------------------------------------------------------*/

int boucle_for(){

    int i = 0, is_match_pile = 0;
    for (i = 0; i < browse_table; i++) {

    // Comparaison caractère par caractère
    int j = 0; 

    // On initialise is_match à 1 (on imagine qu'il y a une correspondance)

        // Comparer chaque caractère de user_input avec comparaison[i]
        for (j = 0; comparaison_pile[i][j] != '\0' && user_choice[j] != '\0'; j++) { 

            if (user_choice[j] != comparaison_pile[i][j]) {

                is_match_pile = 0; // Si une différence est trouvée, on met is_match à 0
                break; // On arrête la comparaison dès qu'il y a une différence
            }
        }
            // Si la chaîne est de même longueur et les caractères sont identiques, on sort de la boucle

        if(is_match_pile && user_choice[j] == comparaison_pile[i][j]) {
                
            break; // La correspondance est trouvée
        } 
    }

    
}




                                // FONCTION MAIN
/*---------------------------------------------------------------------------------*/

int main(){

    
    int user_cmp, i = 0, random[255], bot, is_pile, is_face, is_leave, seed = 0, j = 0, is_match_face = 0, is_match_quit = 1, is_match_pile = 0;
    getentropy(random, sizeof(random));

    /* Fonctions d'affichage*/
    start_display();

/* Essayer de mettre la double boucle for, pour vérifier si l'utilisateur à rentrer pile comme string, au dessus?*/

    while(1){

        choice();

        user_cmp = atoi(user_choice);

        
                                // DOUBLE BOUCLE FOR POUR COMPARAISON PILE
        /*---------------------------------------------------------------------------------------*/

        /*for (i = 0; i < browse_table; i++) {
        // Comparaison caractère par caractère

            is_match_pile = 1; // On initialise is_match à 1 (on imagine qu'il y a une correspondance)

            // Comparer chaque caractère de user_input avec comparaison[i]
            for (j = 0; comparaison_pile[i][j] != '\0' && user_choice[j] != '\0'; j++) { 

                if (user_choice[j] != comparaison_pile[i][j]) {

                    is_match_pile = 0; // Si une différence est trouvée, on met is_match à 0
                    break; // On arrête la comparaison dès qu'il y a une différence
                }
            }
                // Si la chaîne est de même longueur et les caractères sont identiques, on sort de la boucle

            if(is_match_pile && user_choice[j] == comparaison_pile[i][j]) {
                    
                break; // La correspondance est trouvée
            } 

        }*/
                            // DOUBLE BOUCLE FOR POUR COMPARAISON FACE
        /*-----------------------------------------------------------------------------------*/

        for (i = 0; i < browse_table; i++) {

            is_match_face = 2;

            for(j = 0; comparaison_face[i][j] != '\0' && user_choice[j] != '\0'; j++){

                if (user_choice[j] != comparaison_face[i][j]) {

                    is_match_face = 0; // Si une différence est trouvée, on marque is_match à 0
                    break; // On arrête la comparaison parce qu'il y a une différence
                }
            }
            
            if(is_match_face && user_choice[j] == comparaison_face[i][j]) {
                
                break; // La correspondance est trouvée
            }
        }


                        // DOUBLE BOUCLE FOR POUR COMPARAISON QUIT
        /*-----------------------------------------------------------------------------------*/

        for (i = 0; i < browse_table; i++) {

            is_match_quit = 0;

            for(j = 0; comparaison_quit[i][j] != '\0' && user_choice[j] != '\0'; j++){

                if (user_choice[j] != comparaison_quit[i][j]) {

                    is_match_quit = 1; // Si une différence est trouvée, on marque is_match à 0
                    break; // On arrête la comparaison parce qu'il y a une différence
                }
            }
            
            if(is_match_quit && user_choice[j] == comparaison_quit[i][j]) {
                
                break; // La correspondance est trouvée
            }
        }









                            // BOUCLE IF SI UNE CORRESPONDANCE EST TROUVÉE
        /*-------------------------------------------------------------------------------------*/
            

        if (is_match_pile) {

            pile_display();
                    
        }else if(is_match_face){

            face_display();

        }else if(user_cmp == pile){

            pile_display();

        /* Si l'utilisateur rentre 2 alors : */
        }else if(user_cmp == face){  

            face_display();

        /* Si l'utilisateur rentre 0 ou 3 : */
        }else if(is_match_quit == 0 || user_cmp == quit || user_cmp == 3){

            leave_display();
            end_display();
            break;
            
        }else{
            
            /* Boucle while pour demander en continu à l'utilisateur de rentrer une valeur correcte */
            while(user_cmp != pile && user_cmp != face && user_cmp != quit || is_match_face){ // LE faire pour écritures littérales pile/face/quitter
                                                                                // + c'est là qu'il faut mettre les autres variables pour que si je met autre chose ça me print non reconnu
                printf("Non reconnu.\n");
                choice();
            }
        }

                                     /* Section pour l'aléatoire */
        /*-------------------------------------------------------------------------------------------*/

        for(i = 0; i < 255; i++){

            seed = seed + random[i];
        }

        // Utilisation du seed pour randomiser le choix
        srand(seed);
        // Génère un nb aléatoire entre 1 & 2 (pile ou face)
        bot = rand() % 2 + 1;

                                    // AFFICHAGE DU LANCER DE DÉ + SLEEP
        /*-------------------------------------------------------------------------------------------*/

        // Appel de fonction d'affichage "Le dé est jeté"
        dice_throw();
        sleep(2);


                        // BOUCLE IF POUR SAVOIR SI C'EST PILE OU FACE
        /*-----------------------------------------------------------------------------------*/

        if(bot == pile){

            printf("C'est pile !\n\n");

        }else if(bot == face){

            printf("C'est face !\n\n");  
        }

                            // BOUCLES IF POUR COMPARAISON JOUEUR/RÉSULTAT
        /*-----------------------------------------------------------------------------------*/

        if(is_match_pile == pile && is_match_pile != bot || user_cmp == pile && user_cmp != bot){ // C'est ici que c'est à modifier, mettre un || ? Faire un fgets spécifique pour les strings? (pile, face, quitter sans faire d'atoi)

            printf("C'est perdu !\n");
            score_wrong_answer++;
            // if score_wrong_answer > is_corrects_or_wrongs();   Pour lorsque l'utilisateur à plus d'un échec, printf échec au pluriel. Pareil pour réussite donc multiplier les trucs
            is_correct_or_wrong();

        }else if(is_match_face == face && is_match_face != bot || user_cmp == face && user_cmp != bot){

            printf("C'est perdu !\n");
            score_wrong_answer++;
            is_correct_or_wrong();

        }else if(is_match_pile == pile && is_match_pile == bot || user_cmp == pile && user_cmp == bot){

            printf("C'est gagné !\n\n");
            score_good_answer++;
            is_correct_or_wrong();

        }else if(is_match_face == face && is_match_face == bot || user_cmp == face && user_cmp == bot){

            printf("C'est gagné !\n\n");
            score_good_answer++;
            is_correct_or_wrong();
        }
        
    }

    return 0;
}
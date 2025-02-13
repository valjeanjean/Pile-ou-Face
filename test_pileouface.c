#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/random.h>
#include <unistd.h> 


#define pile 1
#define face 2
#define quit 3
#define browse_table 4 // constante pour nb à parcourir dans tableau

                // DÉCLARATION & INITIALISATION VARIABLES
/*-----------------------------------------------------------------------------------*/

int score_good_answer = 0, score_wrong_answer = 0;

                // DÉCLARATION & INITIALISATION TABLEAUX
/*-----------------------------------------------------------------------------------*/

/* Tableau entrée utilisateur œ*/
char user_choice[255]; 

/*Tableau différents orthographes PILE*/
char * comparaison_pile[browse_table] = { 

            "pile",
            "PiLe",
            "PILE",
            "pIlE",
};

/*Tableau différents orthographes FACE*/
char * comparaison_face[browse_table] = { 

            "face",
            "FACE",
            "FaCe",
            "fAcE",
};

/*Tableau différents orthographes FACE*/
char * comparaison_quit[browse_table] = { 

            "quit",
            "exit",
            "QUIT",
            "EXIT",
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
    user_choice[strcspn(user_choice, "\n")] = '\0'; 
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

    /*Condition pour savoir s'il faut mettre réussite et échec au pluriel*/
    if(score_good_answer > 1 && score_wrong_answer > 1){

        printf("Réussites : %d\n", score_good_answer);
        printf("Échecs : %d\n\n", score_wrong_answer);

    }else{

        printf("Réussite : %d\n", score_good_answer);
        printf("Échec : %d\n\n", score_wrong_answer);
    }
}

/*Affichage lorsque le joueur décide de quitter le jeu*/
void leave_display(){

    printf("C'est PERDU, dommage...\n");
    separate_display();
}

/*Affichage de fin de partie*/
void end_display(){
    printf("########### GAME OVER ###########\n");

}
                    /* ------- FONCTION DOUBLE BOUCLE FOR PILE ------- */ // METTRE UN TRUC EN DEBUT DE CODE POUR QUE SI USER_INPUT > 4 lettres, le mettre dans le boucle while "non reconnu"
/*----------------------------------------------------------------------------------------------*/

int check_pile(char tab[], int taille){


    int i, j, match_pile = 0;

    for (i = 0; i < taille; i++) {
    // Comparaison caractère par caractère

        match_pile = 1; // On initialise is_match à 1 (on imagine qu'il y a une correspondance)

        // Comparer chaque caractère de user_input avec comparaison[i]
        for (j = 0; comparaison_pile[i][j] != '\0' && tab[j] != '\0'; j++){ 

            if (tab[j] != comparaison_pile[i][j]) {

                match_pile = 0; // Si une différence est trouvée, on met is_match à 0
                break;// On arrête la comparaison dès qu'il y a une différence
            }
        }
            // Si la chaîne est de même longueur et les caractères sont identiques, on sort de la boucle

        if(tab[j] == comparaison_pile[i][j]){
                
            break; // La correspondance est trouvée
        } 
    }
    
    return match_pile;
}

                /* ------- FONCTION DOUBLE BOUCLE FOR FACE ------- */  
/*----------------------------------------------------------------------------------------------*/

int check_face(char tab[], int taille){

    int match_face = 0, i, j;

    for (i = 0; i < taille; i++) {

        match_face = 2;

        for(j = 0; comparaison_face[i][j] != '\0' && tab[j] != '\0'; j++){

            if (tab[j] != comparaison_face[i][j]) {

                match_face = 0; // Si une différence est trouvée, on marque is_match à 0
                break; // On arrête la comparaison parce qu'il y a une différence
            }
        }
        
        if(tab[j] == comparaison_face[i][j]){
            
            break; // La correspondance est trouvée
        }
    }
    return match_face;
}
                /* ------- FONCTION DOUBLE BOUCLE FOR QUIT ------- */ 
/*---------------------------------------------------------------------------------*/

int check_quit(char tab[], int taille){

    int match_quit = 0, i, j;

    for (i = 0; i < taille; i++){

        match_quit = 0;

        for(j = 0; comparaison_quit[i][j] != '\0' && tab[j] != '\0'; j++){

            if (tab[j] != comparaison_quit[i][j]){

                match_quit = 1; // Si une différence est trouvée, on marque is_match à 1
                //printf("Erreur trouvée\n");
                break; // On arrête la comparaison parce qu'il y a une différence
            }
        }
        
        if(tab[j] == comparaison_quit[i][j]){
            
            break; // La correspondance est trouvée
        }
    }
    return match_quit;
}

                                // FONCTION MAIN
/*---------------------------------------------------------------------------------*/

int main(){

    
    int user_cmp, i = 0, j = 0, random[255], bot, seed = 0, is_match_pile = 0, is_match_face = 0, is_match_quit = 1;
    getentropy(random, sizeof(random));

    /* Fonctions d'affichage */
    start_display();
    
    while(1){
        
        choice();
        
        /* Mettre les 3 appels de fonctions juste au dessus de la boucle non reconnu? Après tous les if pour atoi user_cmp? Refaire un if juste pour les is_match ? (Si user choisis de rentrer un string) */
        user_cmp = atoi(user_choice);
        
        if(user_cmp == 0){
            
            is_match_pile = check_pile(user_choice, browse_table);
            is_match_face = check_face(user_choice, browse_table);
            is_match_quit = check_quit(user_choice, browse_table);
        }
        
        // BOUCLE IF SI UNE CORRESPONDANCE EST TROUVÉE
        /*-------------------------------------------------------------------------------------*/
        
        if(user_cmp != pile && user_cmp != face && user_cmp != quit && is_match_quit == 1 && is_match_face == 0 && is_match_pile == 0){ // mettre les usercmp en premier
            
            /* Boucle while pour demander en continu à l'utilisateur de rentrer une valeur correcte */
            while(1){ 
                
                printf("Non reconnu.\n");
                choice();
                if(user_cmp == 0){
            
                    is_match_pile = check_pile(user_choice, browse_table);
                    is_match_face = check_face(user_choice, browse_table);
                    is_match_quit = check_quit(user_choice, browse_table);
                    break;
                }
            }
                    
        }
        
        if(is_match_face){

            face_display();

        }else if(is_match_pile){
            
            pile_display();
            
        }else if(is_match_quit == 0){
            
            leave_display();
            end_display();
            break;
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
        
        
        if(is_match_pile == pile && is_match_pile != bot || user_cmp == pile && user_cmp != bot){ 
            
            printf("C'est perdu !\n");
            score_wrong_answer++;
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
        
        if(score_wrong_answer >= 10){

            leave_display();
            end_display();
            break;
        }
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h> //srand
#include <string.h> //strlen
#include <time.h>
#include <sys/random.h> // ?
#include <unistd.h> // getentropy

//#define unknow -1
#define pile 1
#define face 2
#define quit 3
#define browse_table 5 // constante pour nb à parcourir dans tableau

                // DÉCLARATION & INITIALISATION VARIABLES POUR SCORE
/*-----------------------------------------------------------------------------------*/

int score_good_answer = 0, score_wrong_answer = 0;

                    // DÉCLARATION & INITIALISATION TABLEAUX
/*-----------------------------------------------------------------------------------*/

/* Tableau entrée utilisateur */
char user_choice[255]; 

/* Tableau différents orthographes PILE */
char * comparaison_pile[] = { 

            "pile",
            "PiLe",
            "PILE",
            "masi",
            "pIlE",
};


/* Tableau différents orthographes FACE */
char * comparaison_face[browse_table] = { 

            "face",
            "FACE",
            "FaCe",
            "fAcE",
            "fACE"
};

/* Tableau différents orthographes FACE */
char * comparaison_quit[browse_table] = { 

            "quit",
            "exit",
            "QUIT",
            "EXIT",
            "QUiT"
};


                            // FONCTIONS D'AFFICHAGE
/*-----------------------------------------------------------------------------------*/

/* Affichage choix utilisateur */
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

/* Affichage lorsqu'il choisit PILE */
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

/* Compteur de victoires & défaites */
void is_correct_or_wrong(){

    /* Condition pour savoir s'il faut mettre réussite et échec au pluriel */
    if(score_good_answer > 1 && score_wrong_answer > 1){

        printf("Réussites : %d\n", score_good_answer);
        printf("Échecs : %d\n\n", score_wrong_answer);

    }else{

        printf("Réussite : %d\n", score_good_answer);
        printf("Échec : %d\n\n", score_wrong_answer);
    }
}

/* Affichage lorsque le joueur décide de quitter le jeu */
void leave_display(){

    printf("C'est PERDU, dommage...\n");
    separate_display();
}

/* Affichage de fin de partie */
void end_display(){
    printf("########### GAME OVER ###########\n");

}
                    /* ------- FONCTION DOUBLE BOUCLE FOR PILE ------- */ 
/*----------------------------------------------------------------------------------------------*/

int check_pile(char tab[], int taille){user_choice[strcspn(user_choice, "\n")] = '\0'; 


    int i, j, match_pile = 0;

    for (i = 0; i < taille; i++) {
    // Comparaison caractère par caractère

        match_pile = 1; // On initialise is_match à 1 (on imagine qu'il y a une correspondance)

        // Comparer chaque caractère de user_input avec comparaison[i]
        for (j = 0; comparaison_pile[i][j] != '\0' && tab[j] != '\0'; j++){ 

            if (tab[j] != comparaison_pile[i][j]) {

                match_pile = 0; // Si une différence est trouvée, on met is_match à 0
                break;
            }
        }

        // Si la chaîne est de même longueur et les caractères sont identiques, on sort de la boucle
        if(tab[j] == comparaison_pile[i][j]){
                
            break; 
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

    /* Fonction d'affichage */
    start_display();
    
    while(1){
        
        choice();
        
        user_cmp = atoi(user_choice);
        
        if(user_cmp == 0){
            
            is_match_pile = check_pile(user_choice, browse_table);
            is_match_face = check_face(user_choice, browse_table);
            is_match_quit = check_quit(user_choice, browse_table);
        }
        
            /* Boucle while pour demander en continu à l'utilisateur de rentrer une valeur correcte */
        /*----------------------------------------------------------------------------------------------*/
        
        if(user_cmp != pile && user_cmp != face && user_cmp != quit && is_match_quit == 1 && is_match_face == 0 && is_match_pile == 0){ // mettre les usercmp en premier
            
            while(1){ 
                
                printf("\nNon reconnu.\n\n");
                choice();
                if(user_cmp == 0){
            
                    is_match_pile = check_pile(user_choice, browse_table);
                    is_match_face = check_face(user_choice, browse_table);
                    is_match_quit = check_quit(user_choice, browse_table);
                    break;
                }
            }
                    
        }
        

                                // BOUCLE IF SI UNE CORRESPONDANCE EST TROUVÉE
        /*----------------------------------------------------------------------------------------------*/

        if(is_match_face){

            face_display();

        }else if(is_match_pile){
            
            pile_display();
            
        }else if(is_match_quit == 0 || user_cmp == 3){
            
            leave_display();
            end_display();
            break;
        }

                                    /* Section pour l'aléatoire */
        /*-------------------------------------------------------------------------------------*/

        for(i = 0; i < 255; i++){

            seed = seed + random[i];
        }

        // Utilisation du seed pour randomiser le choix
        srand(seed);     
        // Génère un nb aléatoire entre 1 & 2 (pile ou face)
        bot = rand() % 2 + 1;
        
                                    // AFFICHAGE DU LANCER DE DÉ + SLEEP
        /*-------------------------------------------------------------------------------------------*/
        
        // Appel fonction d'affichage "Le dé est jeté"
        dice_throw();
        sleep(2);
        
        
                        // BOUCLE IF POUR CONNAITRE LE RÉSULTAT ALÉATOIRE
        /*-----------------------------------------------------------------------------*/
        
        if(bot == pile){
            
            printf("C'est pile !\n\n");

        }else if(bot == face){
            
            printf("C'est face !\n\n");  
        }

                        // BOUCLES IF POUR COMPARAISON CHOIX JOUEUR/RÉSULTAT
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
        
        /* Si l'utilisateur enregistre 10 échecs, affichage de fin de partie */
        if(score_wrong_answer >= 10){

            leave_display();
            end_display();
            break;
        }
    }
    
    return 0;
}





            /*------------//EXEMPLE//------------*/

                // int get_choice(){
                //     char buf[255];
                //     fgets(buf, sizeof(buf), stdin);
                //     buf[strlen(buf)-1] = 0;
                    
                //     // si text ou 0
                //     if(atoi(buf) == 0){
                //         // text ou 0
                //         if(strcmp(buf,"0") == 0){
                //             return unknow;
                //         }else{
                //             //text
                //             return get_choice_from_text(buf);
                //         }
                //     }else{
                //         // si chiffre
                //         return get_choice_from_digit();

                //     }
                //     // si text
                //         // to lower case
                //             // f(text) reutrn PILE FACE OU ...
                    

                // }

                // int choice = get_choice();
                // int ennemy = get_random_choice();
                // switch (choice)
                // {
                // case pile:
                //     /* code */
                //     printResult(choice,ennemy);
                //     break;

                // case face:
                //     printResult(choice,ennemy);
                //     break;
                // case quit:
                //     printResult(choice,ennemy);

                //     break;
                
                // default:

                //     break;
                // }
<h1>Pile ou Face</h1>

<h2>Description</h2>

Le projet "Pile ou Face" est un jeu en ligne de commande (CLI) en langage C. Il simule un jeu de pile ou face où l'utilisateur peut choisir entre "Pile" ou "Face", et un tirage aléatoire de la pièce détermine si l'utilisateur a gagné ou perdu. Le jeu continue jusqu'à ce que l'utilisateur choisisse de quitter ou qu'il atteigne 10 échecs.

Le programme respecte les contraintes suivantes :

    L'utilisateur peut entrer des choix via des commandes numériques ou textuelles (ex: "pile", "face", "quit").
    Un délai de suspense est ajouté entre la demande de choix et le résultat.
    Le score de réussites et d'échecs est suivi tout au long de la partie.
    Le jeu s'arrête si l'utilisateur entre 0 pour quitter ou atteint 10 échecs.
    Un message "GAME OVER" est affiché à la fin du jeu.

<h3>Fonctionnalités</h3>

    Choix de l'utilisateur : L'utilisateur peut entrer un choix entre :
        1 pour "Pile"
        2 pour "Face"
        0 pour quitter le jeu
    Affichage du résultat : La pièce est lancée, et l'ordinateur affiche si l'utilisateur a gagné ou perdu, avec une animation de suspense (trois points s'affichent avec une pause de 0.5s entre chaque).
    Score de la partie : Le nombre de réussites et d'échecs est affiché après chaque tour.
    Gestion des erreurs : Le jeu accepte plusieurs variantes de saisie comme "pile", "face", "quit", etc., en plus des options numériques.
    Fin du jeu : Le jeu se termine si l'utilisateur choisit de quitter ou atteint 10 échecs.

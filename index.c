#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livre{
    char titre[50];
    char auteur[50];
    int annee;
    int disponible;
    int id;
}Livre;

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    int emprunts;
    int idlivre; 
} Utilisateur;

Livre tab[50];
Utilisateur users[50];
int idLivre[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
int n=0;
int nbUsers=0;  

/* prototypes */
int posLivre(int id, Livre tab[]);
int posUser(int id, Utilisateur users[]);

void Ajouter (Livre tab[])
{
    printf("Combien de livres voulez-vous ajouter? ");
    scanf("%d", &n);
    getchar(); // Clear buffer
    
    for (int i = 0; i < n; i++){
        printf("\nEntrez le titre du livre %d: ", i+1);
        fgets(tab[i].titre, 50, stdin);
        tab[i].titre[strcspn(tab[i].titre, "\n")] = 0; // Remove newline
        
        printf("Entrez l'auteur du livre %d: ", i+1);
        fgets(tab[i].auteur, 50, stdin);
        tab[i].auteur[strcspn(tab[i].auteur, "\n")] = 0;
        
        printf("Entrez l'année de publication du livre %d: ", i+1);
        scanf("%d", &tab[i].annee);
        getchar(); // Clear buffer
        
        tab[i].disponible = 1;
        tab[i].id = i+1;
    }
}

void Supprimer(Livre tab[]){
    int id;
    printf("Entrez l'id du livre à supprimer: ");
    scanf("%d", &id);

    int p = posLivre(id, tab);

    if (p != -1){
        for (int i = p; i < n-1; i++){
            tab[i] = tab[i+1];
        }
        n--;
        printf("Livre supprimé avec succès\n");
    }
    else{
        printf("Livre non trouvé\n");
    }
}

int posLivre(int id, Livre tab[]){
    for (int i = 0; i < n; i++){
        if (tab[i].id == id)
            return i;
    }
    return -1;
}

void Modifier(Livre tab[]){  
    int id;
    printf("Entrez l'id du livre à modifier: ");
    scanf("%d", &id);
    getchar(); // Clear buffer

    int p = posLivre(id, tab);

    if (p != -1){
        printf("Entrez le nouveau titre du livre: ");
        fgets(tab[p].titre, 50, stdin);
        tab[p].titre[strcspn(tab[p].titre, "\n")] = 0;
        
        printf("Entrez le nouvel auteur du livre: ");
        fgets(tab[p].auteur, 50, stdin);
        tab[p].auteur[strcspn(tab[p].auteur, "\n")] = 0;
        
        printf("Entrez la nouvelle année: ");
        scanf("%d", &tab[p].annee);
        getchar(); // Clear buffer
        
        printf("Livre modifié avec succès\n");
    }
    else{
        printf("Livre non trouvé\n");
    }
}

void Rechercher(Livre tab[]){  
    char titre[50];
    getchar(); // Clear buffer
    printf("Entrez le titre du livre à rechercher: ");
    fgets(titre, 50, stdin);
    titre[strcspn(titre, "\n")] = 0;

    for (int i = 0; i < n; i++){
        if (strcmp(tab[i].titre, titre) == 0){
            printf("Livre trouvé: %s, %s, %d - %s\n",
                   tab[i].titre, tab[i].auteur, tab[i].annee,
                   tab[i].disponible ? "Disponible" : "Emprunté");
            return;
        }
    }

    printf("Livre non trouvé\n");
}

void Afficher(Livre tab[]){  
    if (n == 0) {
        printf("Aucun livre dans la bibliothèque\n");
        return;
    }
    
    for (int i = 0; i < n; i++){
        printf("Livre %d: %s, %s, %d - %s\n",
               tab[i].id, tab[i].titre, tab[i].auteur, tab[i].annee,
               tab[i].disponible ? "Disponible" : "Emprunté");
    }
}

/* ===== USERS ===== */

void Add(Utilisateur users[]){
    int nb;
    printf("Combien d'utilisateurs voulez-vous ajouter? ");
    scanf("%d", &nb);
    getchar(); // Clear buffer
    
    for (int i = nbUsers; i < nbUsers + nb; i++){
        printf("\nEntrez le nom de l'utilisateur %d: ", i+1);
        fgets(users[i].nom, 50, stdin);
        users[i].nom[strcspn(users[i].nom, "\n")] = 0;
        
        printf("Entrez le prénom de l'utilisateur %d: ", i+1);
        fgets(users[i].prenom, 50, stdin);
        users[i].prenom[strcspn(users[i].prenom, "\n")] = 0;
        
        users[i].id = i+1;
        users[i].emprunts = 0;
        users[i].idlivre = 0;
    }
    
    nbUsers += nb;
}

void Drop(Utilisateur users[]){
    int id;
    printf("Entrez l'id à supprimer: ");
    scanf("%d", &id);

    int p = posUser(id, users);

    if (p != -1){
        for (int i = p; i < nbUsers-1; i++){
            users[i] = users[i+1];
        }
        nbUsers--;
        printf("Utilisateur supprimé avec succès\n");
    }
    else{
        printf("Utilisateur non trouvé\n");
    }
}

int posUser(int id, Utilisateur users[]){
    for (int i = 0; i < nbUsers; i++){
        if (users[i].id == id)
            return i;
    }
    return -1;
}

void Update(Utilisateur users[]){
    int id;
    printf("Entrez l'id à modifier: ");
    scanf("%d", &id);
    getchar(); // Clear buffer

    int p = posUser(id, users);

    if (p != -1){
        printf("Nouveau nom: ");
        fgets(users[p].nom, 50, stdin);
        users[p].nom[strcspn(users[p].nom, "\n")] = 0;
        
        printf("Nouveau prénom: ");
        fgets(users[p].prenom, 50, stdin);
        users[p].prenom[strcspn(users[p].prenom, "\n")] = 0;
        
        printf("Utilisateur modifié avec succès\n");
    }
    else{
        printf("Utilisateur non trouvé\n");
    }
}

void Search(Utilisateur users[]){
    char nom[50];
    getchar(); // Clear buffer
    printf("Nom à rechercher: ");
    fgets(nom, 50, stdin);
    nom[strcspn(nom, "\n")] = 0;

    for (int i = 0; i < nbUsers; i++){
        if (strcmp(users[i].nom, nom) == 0){
            printf("Utilisateur trouvé: %s %s (ID: %d, Emprunts: %d)\n",
                   users[i].nom, users[i].prenom, users[i].id, users[i].emprunts);
            return;
        }
    }

    printf("Utilisateur non trouvé\n");
}

void Display(Utilisateur users[]){
    if (nbUsers == 0) {
        printf("Aucun utilisateur\n");
        return;
    }
    
    for (int i = 0; i < nbUsers; i++){
        printf("Utilisateur %d: %s %s (Emprunts: %d)\n",
               users[i].id, users[i].nom, users[i].prenom, users[i].emprunts);
    }
}

void emprunter(Utilisateur users[], Livre tab[]){
    int idUser, idLivre;
    printf("Entrez l'id de l'utilisateur: ");
    scanf("%d", &idUser);
    printf("Entrez l'id du livre: ");
    scanf("%d", &idLivre);

    int pUser = posUser(idUser, users);
    int pLivre = posLivre(idLivre, tab);

    if (pUser != -1 && pLivre != -1){
        if (tab[pLivre].disponible){
            users[pUser].emprunts++;
            users[pUser].idlivre = idLivre;
            tab[pLivre].disponible = 0;
            printf("Emprunt réussi\n");
        }
        else{
            printf("Livre non disponible\n");
        }
    }
    else{
        printf("Utilisateur ou livre non trouvé\n");
    }
}

void rendre(Utilisateur users[], Livre tab[]){
    int idUser, idLivre;
    printf("Entrez l'id de l'utilisateur: ");
    scanf("%d", &idUser);
    printf("Entrez l'id du livre: ");
    scanf("%d", &idLivre);

    int pUser = posUser(idUser, users);
    int pLivre = posLivre(idLivre, tab);

    if (pUser != -1 && pLivre != -1){
        if (users[pUser].emprunts > 0 && users[pUser].idlivre == idLivre){
            users[pUser].emprunts--;
            users[pUser].idlivre = -1;  // Changed to -1 to indicate no book
            tab[pLivre].disponible = 1;
            printf("Retour réussi\n");
        }
        else{
            printf("Aucun emprunt correspondant trouvé\n");
        }
    }
    else{
        printf("Utilisateur ou livre non trouvé\n");
    }
}

void AfficherEmprunts(Utilisateur users[], Livre tab[]){
    int found = 0;
    for (int i = 0; i < nbUsers; i++){
        if(users[i].emprunts > 0){
            int livrePos = posLivre(users[i].idlivre, tab);
            if (livrePos != -1) {
                printf("Utilisateur %d: %s %s a emprunté '%s' de %s\n",
                       users[i].id, users[i].nom, users[i].prenom,
                       tab[livrePos].titre, tab[livrePos].auteur);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("Aucun emprunt en cours\n");
    }
}

int main(){
    int choix;
    int menuPrincipal;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1: Gestion des livres\n");
        printf("2: Gestion des utilisateurs\n");
        printf("3: Gestion des emprunts\n");
        printf("4: Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &menuPrincipal);
        getchar(); // Clear buffer

        switch(menuPrincipal) {
            case 1: // Gestion des livres
                do {
                    printf("\n--- GESTION DES LIVRES ---\n");
                    printf("1 Ajouter\n2 Supprimer\n3 Modifier\n4 Rechercher\n5 Afficher\n6 Retour\n");
                    printf("Votre choix: ");
                    scanf("%d", &choix);
                    getchar(); // Clear buffer

                    switch(choix){
                        case 1: Ajouter(tab); break;
                        case 2: Supprimer(tab); break;
                        case 3: Modifier(tab); break;
                        case 4: Rechercher(tab); break;
                        case 5: Afficher(tab); break;
                        case 6: printf("Retour au menu principal\n"); break;
                        default: printf("Choix invalide\n");
                    }
                } while(choix != 6);
                break;

            case 2: // Gestion des utilisateurs
                do {
                    printf("\n--- GESTION DES UTILISATEURS ---\n");
                    printf("1 Ajouter\n2 Supprimer\n3 Modifier\n4 Rechercher\n5 Afficher\n6 Retour\n");
                    printf("Votre choix: ");
                    scanf("%d", &choix);
                    getchar(); // Clear buffer

                    switch(choix){
                        case 1: Add(users); break;
                        case 2: Drop(users); break;
                        case 3: Update(users); break;
                        case 4: Search(users); break;
                        case 5: Display(users); break;
                        case 6: printf("Retour au menu principal\n"); break;
                        default: printf("Choix invalide\n");
                    }
                } while(choix != 6);
                break;

            case 3: // Gestion des emprunts
                do {
                    printf("\n--- GESTION DES EMPRUNTS ---\n");
                    printf("1-Emprunter un livre\n");
                    printf("2-Rendre un livre\n");
                    printf("3-Afficher les emprunts\n");
                    printf("4-Retour\n");  
                    printf("Votre choix: ");
                    scanf("%d", &choix);

                    switch(choix){
                        case 1: emprunter(users, tab); break;
                        case 2: rendre(users, tab); break;
                        case 3: AfficherEmprunts(users, tab); break;
                        case 4: printf("Retour au menu principal\n"); break;
                        default: printf("Choix invalide\n");
                    }
                } while (choix != 4);
                break;

            case 4:
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide\n");
        }
    } while(menuPrincipal != 4);

    return 0;
}
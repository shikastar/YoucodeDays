#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
const int N = 5;

bool memeNom(char *s, char *t) {
    if (!s || !t) return 0;
    int i = 0;
    while (s[i] && t[i]) {
        if (s[i] != t[i]) return 0;
        i++;
    }
    return (s[i] == t[i]);
}

int getProduit(char *produits[], char *nom) {
    for (int i = 0; i < N; i++) {
        if (memeNom(nom, produits[i])) return i;
    }
    return -1;
}

void    afficherMenu(char **produits, float *prix) {
    printf("========================LISTES DE PRODUITS==========================\n");
    for (int i = 0; i < N; i++) printf("nom : %s, prix : %.2f\n", produits[i], prix[i]);
}


int main() {
    char *produits[] = {"danone", "biscuit", "eau", "lipton", "bimo"};
    float prix[] = {100, 150, 500, 200, 450.5};

    afficherMenu(produits, prix);
    
    printf("Veuillez entrez nombre totales de produis achetes: ");
    int produitsTotales; scanf("%d", &produitsTotales);
    
    float montantApayer = 0;
    for (int i = 0; i < produitsTotales; i++) {
        printf("Veullez Entrer nom de produit %d: ", i + 1);
        char produit[MAX_SIZE];
        scanf("%s", produit);
        printf("Veullez Entrer la quantite achetes du produit %d: ", i + 1);
        int quantite;
        scanf("%d", &quantite);
        int idx = getProduit(produits, produit);
        if (idx == -1)
            printf("Il n'ya pas de produits de nom \'%s\'.\n", produit);
        else {
            float prixApayer = 0, pourcentage = 0;
            while (quantite--) {
                prixApayer += (prix[idx] - prix[idx] * pourcentage / 100.0);
                pourcentage += 2.0; 
            }
            printf("Montant a payer pour le produit %s est : %.2f\n", produits[i], prixApayer);
            montantApayer += prixApayer;
        }
    }
    printf("Montant total a payer : %.2f DHS.\n", montantApayer);
}
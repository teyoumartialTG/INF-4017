#include <iostream>
#include <climits>
using namespace std;
 
// Valeurs (stockées dans le array `v`)
// Pondérations (stockées dans le array `w`)
// Nombre total d'éléments distincts `n`
// Capacité sac à dos `W`
int knapsack(int v[], int w[], int n, int W)
{
    // cas de base : capacité négative
    if (W < 0) {
        return INT_MIN;
    }
 
    // cas de base : il ne reste plus d'éléments ou la capacité devient 0
    if (n < 0 || W == 0) {
        return 0;
    }
 
    // Cas 1. Incluez l'élément actuel `v[n]` dans le sac à dos et répétez pour
    // éléments restants `n-1` avec une capacité réduite `W-w[n]`
    int include = v[n] + knapsack(v, w, n - 1, W - w[n]);
 
    // Cas 2. Exclure l'élément actuel `v[n]` du sac à dos et le répéter pendant
    // éléments restants `n-1`
    int exclude = knapsack(v, w, n - 1, W);
 
    // renvoie la valeur maximale que nous obtenons en incluant ou en excluant l'élément actuel
    return max(include, exclude);
}
 
// 0–1 problème de sac à dos
int main()
{
    // entrée : un ensemble d'éléments, chacun avec un poids et une valeur
    int v[] = { 20, 5, 10, 40, 15, 25 };
    int w[] = { 1, 2, 3, 8, 7, 4 };
 
    // capacité sac à dos
    int W = 10;
 
    // nombre total d'éléments
    int n = sizeof(v) / sizeof(v[0]);
 
    cout << "Valeur du sac a dos  " << knapsack(v, w, n - 1, W);
 
    return 0;
}
#ifndef PUITS_H
#define PUITS_H

#include <iostream>
#include <QPainter>
using namespace std;

class puits
{
    protected:
        int m_largeur = 10;
        int m_hauteur = 22;
        int m_puits[26][14];
        int m_i;
        int m_j;

    public:
        // Constructeur
        puits();
        puits(int largeur, int hauteur);

        // Affichage
        void affichage(QPainter *feuilleDessin);
        void affichagePuits();

        // Traiter la ligne
        bool ligneComplete(int ligne);
        void supprimmerLigne(int ligne);
        bool fin();

        // Mutateurs
        void setI(int i);
        void setJ(int j);
        void setCasePuits(int x, int y, int typeCase);

        // Accesseurs
        int getI();
        int getJ();
        int getCasePuits(int x, int y);
        int getLargeur();
        int getHauteur();
};

#endif // PUITS_H

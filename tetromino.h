#ifndef TETROMINO_H
#define TETROMINO_H

#include <iostream>
#include <QPainter>
using namespace std;

class tetromino
{
    protected:
        int m_x ;
        int m_y ;
        int m_type;
        int m_orientation;
        QColor m_couleur;
        int m_tabTetromino[4][4][4];

    public:
        // Constructeurs
        tetromino();
        tetromino(int x, int y, QColor couleur,int type, int orientation);

        // Affichage
        void affichage(QPainter * p);
        void affichageSuivant(QPainter * p);
        void affichagePrevu(QPainter * p);

        // Méthode de rotation et deplacement
        void rotationG();
        void rotationD();
        void deplacer(int x, int y);

        // Mutateurs
        void setX(int x);
        void setY(int y);
        void setType(int type);
        void setCouleur(QColor couleur);
        void setOrientation(int o);

        // Accesseurs
        int getX();
        int getY();
        int getType();
        QColor getCouleur();
        int getTabTetromino(int i, int j);
        int getTabTetromino(int o,int i, int j);
        int getOrientation();
};

#endif // TETROMINO_H

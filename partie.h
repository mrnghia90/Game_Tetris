#ifndef PARTIE_H
#define PARTIE_H

#include <iostream>
#include <QTimer>
using namespace std;

#include "puits.h"
#include "partie.h"
#include "tetromino.h"
#include "tetromino_i.h"
#include "tetromino_j.h"
#include "tetromino_l.h"
#include "tetromino_o.h"
#include "tetromino_s.h"
#include "tetromino_t.h"
#include "tetromino_z.h"
class partie
{
protected:
    // Du coeur d'une partie
    tetromino *m_tetromino_actuel;
    tetromino *m_tetromino_suivant;
    puits *m_puits;

    // type des tetrominos aléatoire
    int tetro_random_actuel;
    int tetro_random_suivant;

    bool m_resultat = false;

    // Traiter la ligne
    int m_nbLignesCompletees = 0;
    int m_niveau = 0;
    int m_score = 0;
    int m_lignesTraitees = 0;

    // Statistiques

    int m_duree = 0;
    bool m_estEnPause = false;

public:

    // Constructeurs
    partie();

    // Vérifier des déplacements
    bool collision();
    bool deplacerGauchePossible();
    bool deplacerDroitePossible();
    bool deplacerBasPossible();

    // Vérifier des rotations
    bool rotationGauchePossible();
    bool rotationDroitePossible();

    // Accesseurs
    tetromino* getTetrominoActuel();
    tetromino* getTetrominoSuivant();
    puits* getPuits();
    int getNiveau();
    int getScore();
    int getLignesTraitees();
    int getDuree();
    bool getEnPause();


    // Mutateurs
    void setTetrominoActuel(tetromino *t);
    void setTetrominoSuivant(tetromino *t);
    void setPuits(puits *p);
    void setNiveau(int niv);
    void setScore(int sc);
    void setLigneTraitees(int l);


    /*
    void pause();
    void volume();

    */
};


#endif // PARTIE_H

#include "partie.h"

// Constructeur
partie::partie()
{
    // Création tetromino actuel
    srand(time(NULL));
    tetro_random_actuel = (rand() % 7) + 1;

    switch(tetro_random_actuel)
    {
        case 1: {m_tetromino_actuel = new tetromino_i(300, 50, QColor(255, 64, 129), 1,0);break;}
        case 2: {m_tetromino_actuel = new tetromino_j(300, 50, QColor(238, 255, 65), 2,0);break;}
        case 3: {m_tetromino_actuel = new tetromino_l(300, 50, QColor(234, 128, 252), 3,0);break;}
        case 4: {m_tetromino_actuel = new tetromino_o(300, 50, QColor(83, 109, 254), 4,0);break;}
        case 5: {m_tetromino_actuel = new tetromino_s(300, 50, QColor(178, 255, 89), 5,0);break;}
        case 6: {m_tetromino_actuel = new tetromino_t(300, 50, QColor(255, 138, 101), 6,0);break;}
        case 7: {m_tetromino_actuel = new tetromino_z(300, 50, QColor(29, 233, 182), 7,0);break;}
    }

    // Création tetromino suivant
    tetro_random_suivant = (rand() % 7) + 1;

    switch(tetro_random_suivant)
    {
        case 1: {m_tetromino_suivant = new tetromino_i(300, 50, QColor(255, 64, 129), 1,0);break;}
        case 2: {m_tetromino_suivant = new tetromino_j(300, 50, QColor(238, 255, 65), 2,0);break;}
        case 3: {m_tetromino_suivant = new tetromino_l(300, 50, QColor(234, 128, 252), 3,0);break;}
        case 4: {m_tetromino_suivant = new tetromino_o(300, 50, QColor(83, 109, 254), 4,0);break;}
        case 5: {m_tetromino_suivant = new tetromino_s(300, 50, QColor(178, 255, 89), 5,0);break;}
        case 6: {m_tetromino_suivant = new tetromino_t(300, 50, QColor(255, 138, 101), 6,0);break;}
        case 7: {m_tetromino_suivant = new tetromino_z(300, 50, QColor(29, 233, 182), 7,0);break;}
    }

    // Allouer le puits
    m_puits = new puits(14,26);
}


bool partie::collision()
{
    bool res = false;
        for (int i = 0;i< 4;i++)
        {
            for (int j = 0;j< 4;j++)
            {
                if (m_tetromino_actuel->getTabTetromino(i,j)==1)
                {
                    // Retrouver coordonnée dans la matrice m_puits (x,y) à partir de coordonnée d'interface graphique (getX, getY) et coordonnée matrice tabTetromino (i,j)
                    int x = m_tetromino_actuel->getY()/20 +i-1 ;
                    int y = m_tetromino_actuel->getX()/20 +j+3;

                    if (m_puits->getCasePuits(x,y) != 0)
                    {
                        res = true;
                    }
                }
            }
        }
        return res;
}





// Vérification deplacerment à gauche
bool partie::deplacerGauchePossible()
{
    bool res = true;
        for (int i = 0;i< 4;i++)
        {
            for (int j = 0;j< 4;j++)
            {
                if (m_tetromino_actuel->getTabTetromino(i,j)==1)
                {
                    // Retrouver coordonnée dans la matrice m_puits (x,y) à partir de coordonnée d'interface graphique (getX, getY) et coordonnée matrice tabTetromino (i,j)
                    int x = m_tetromino_actuel->getY()/20 + i-1;
                    int y = m_tetromino_actuel->getX()/20 + j + 3;

                    if (m_puits->getCasePuits(x,y) != 0)
                    {
                        res = false;
                    }
                }
            }
        }
        return res;
}

// Vérification deplacerment à droite
bool partie::deplacerDroitePossible()
{
    bool res = true;
    for (int i = 0;i< 4;i++)
    {
        for (int j = 0;j< 4;j++)
        {
            if (m_tetromino_actuel->getTabTetromino(i,j)==1)
            {
                // Retrouver coordonnée dans la matrice m_puits (x,y) à partir de coordonnée d'interface graphique du tetromino actuel (getX, getY) et ses coordonnées matrice tabTetromino (i,j)
                int x = m_tetromino_actuel->getY()/20 + i-1;
                int y = m_tetromino_actuel->getX()/20 + j + 5;

                if (m_puits->getCasePuits(x,y) != 0)
                {
                    res = false;
                }
            }
        }
    }
    return res;
}

// Vérification deplacerment en bas
bool partie::deplacerBasPossible()
{
    bool res = true;
    for (int i = 0;i< 4;i++)
    {
        for (int j = 0;j< 4;j++)
        {
            if (m_tetromino_actuel->getTabTetromino(i,j)==1)
            {
                // Retrouver coordonnée dans la matrice m_puits (l,c) à partir de coordonnée d'interface graphique du tetromino actuel (getX, getY) et ses coordonnées matrice tabTetromino (i,j)
                int l = (-50 + m_tetromino_actuel->getY() +i*20)/20 + 3;
                int c = (-240 + m_tetromino_actuel->getX() +j*20)/20 + 2;

                if (m_puits->getCasePuits(l,c) != 0)
                {
                    res = false;
                }
            }
        }
    }
//        // Création tetromino actuel
//        delete m_tetromino_actuel;
//        m_tetromino_actuel = m_tetromino_suivant;
//        // Si on peut encore déplacer en bas, on va continuer sinon on arrete
//        if (deplacerBasPossible()){

//            tetro_random_actuel = (rand() % 7) + 1;
//            switch(tetro_random_actuel)
//            {
//                case 1: {m_tetromino_suivant = new tetromino_i(300, 50, QColor(255, 64, 129), 1,0);break;}
//                case 2: {m_tetromino_suivant = new tetromino_j(300, 50, QColor(238, 255, 65), 2,0);break;}
//                case 3: {m_tetromino_suivant = new tetromino_l(300, 50, QColor(234, 128, 252), 3,0);break;}
//                case 4: {m_tetromino_suivant = new tetromino_o(300, 50, QColor(83, 109, 254), 4,0);break;}
//                case 5: {m_tetromino_suivant = new tetromino_s(300, 50, QColor(178, 255, 89), 5,0);break;}
//                case 6: {m_tetromino_suivant = new tetromino_t(300, 50, QColor(255, 138, 101), 6,0);break;}
//                case 7: {m_tetromino_suivant = new tetromino_z(300, 50, QColor(29, 233, 182), 7,0);break;}
//            }
//        }
//        else{

//        }

    return res;
}

// Vérification rotation à droite.
bool partie::rotationDroitePossible()
{
    bool res = true;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int l = (-50 + m_tetromino_actuel->getY() +i*20)/20 +2;
            int c = (-240 + m_tetromino_actuel->getX() +j*20)/20 +2;
            if ((m_tetromino_actuel->getTabTetromino((m_tetromino_actuel->getOrientation() + 3)%4,i, j) == 1)
                    && m_puits->getCasePuits(l,c)!=0)
            {
                res = false;
            }

        }
    }
    return res;
}

// Vérification rotation à gauche.
bool partie::rotationGauchePossible()
{
    bool res = true;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int l = (-50 + m_tetromino_actuel->getY() +i*20)/20 +2;
                int c = (-240 + m_tetromino_actuel->getX() +j*20)/20 +2;
                if ((m_tetromino_actuel->getTabTetromino((m_tetromino_actuel->getOrientation() + 1)%4,i, j) == 1)
                        && m_puits->getCasePuits(l,c)!=0)
                {
                    res = false;
                }
            }
        }
    return res;
}

// Accesseurs
tetromino* partie::getTetrominoActuel()
{
    return m_tetromino_actuel;
}

tetromino* partie::getTetrominoSuivant()
{
    return m_tetromino_suivant;
}

puits* partie::getPuits()
{
    return m_puits;
}

bool partie::getEnPause()
{
    return m_estEnPause;
}

int partie::getNiveau(){
    return m_niveau;
}

int partie::getScore(){
    return m_score;
}

int partie::getLignesTraitees(){
    return m_lignesTraitees;
}

int partie::getDuree(){
    return m_duree;
}

// Mutateurs
void partie::setTetrominoActuel(tetromino *t)
{
    delete m_tetromino_actuel;
    m_tetromino_actuel = t;
}

void partie::setTetrominoSuivant(tetromino *t)
{
    m_tetromino_suivant = t;
}

void partie::setPuits(puits *p)
{
    m_puits =p;
}

void partie::setNiveau(int niv){
    m_niveau = niv;
}

void partie::setScore(int sc){
    m_score = sc;
}

void partie::setLigneTraitees(int l){
    m_lignesTraitees = l;
}

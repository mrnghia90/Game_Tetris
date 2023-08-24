#include "tetromino.h"

// Constructeur défault
tetromino::tetromino()
{
    for (int r = 0; r < 4; r++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_tabTetromino[r][i][j] = 0;
            }
        }
     }
}

// Constructeur normal

// Explication des paramètres dans le constructeur :
// x,y : coordonnée dans l'interface graphique
// couleur : la couleur d'un tetromino en fonction de son type
// type : la forme d'un tetromino I,J,L,O,S,T,Z
// orientation : l'orientation d'un tetromino

// Préconditions :
// x,y : on fixe la position d'un tetromino par défaut à la coordonnée (300,50). On remarque que l'origine est (0,0) en haut à gauche.
// couleur : on choisit une des couleurs en composition RGB (xx,xx,xx) ou xx des entiers positifs.
// type : à valeur dans {1,2,3,4,5,6,7}
// orientattion :  à valeur dans {0,1,2,3}
tetromino::tetromino(int x, int y, QColor couleur,int type, int orientation)
{
    m_x = x;
    m_y = y;
    m_couleur = couleur;
    m_type = type;
    m_orientation = orientation;

    // On considère le tetromino se trouve dans une matrice 3d (m_tabTetromino) avec la taille 4x4x4
    // le premier coordonnée r c'est l'orientaion
    // le couple (i,j) est considéré comme coordonnée d'une matrice 2d où m_tabTetromino(i,j) est une cas.
    // ce cas vaut 1 si c'est un cas du tetromino et 0 sinon. Cette condition sera vérifié dans la constructeur des classes dérivées.
    // Dans le constructeur de classe tetromino on initialise = 0 dans tous cas de la matrice 3d.

    for (int r = 0; r < 4; r++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_tabTetromino[r][i][j] = 0;
            }
        }
     }
}

// Affichage
void tetromino::affichage(QPainter * p)
{
    for(int i=0 ; i<4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if (m_tabTetromino[m_orientation][i][j]==1)
            {
                p->setPen(QPen(Qt::white));
                p->drawRect(m_x + (j + 3)*20,m_y + i*20, 1*20, 1*20);
                p->fillRect(m_x + (j + 3)*20 + 1,m_y + i*20 + 1,1*20 - 1,1*20 - 1,QBrush(m_couleur));
            }
        }
    }
}

// Affichage le tetromino suivant
void tetromino::affichageSuivant(QPainter * p)
{

    for(int i=0 ; i<4 ; i++)
    {

        for(int j = 0 ; j < 4 ; j++)
        {
            if (m_tabTetromino[m_orientation][i][j]==1)
            {
                p->setPen(QPen(Qt::white));
                p->drawRect(50 + (j + 3)*20,250 + i*20, 1*20, 1*20);
                p->fillRect(50 + (j + 3)*20 + 1,250 + i*20 + 1,1*20 - 1,1*20 - 1,QBrush(m_couleur));
            }
            else {

            }
        }
        p->setPen(QPen(QColor(255, 109, 0)));
        p->drawRect(80,200, 140, 140);
    }
}

/*
// Affichage le tetromino prévu
void tetromino::affichagePrevu(QPainter * p)
{
    while (deplacerBasPossible())
    {
        parti->getTetrominoActuel()->deplacer(0,20);
    }
    for(int i=0 ; i<4 ; i++)
    {

        for(int j = 0 ; j < 4 ; j++)
        {
            if (m_tabTetromino[m_orientation][i][j]==1)
            {
                p->setPen(QPen(Qt::white));
                p->drawRect(50 + (j + 3)*20,250 + i*20, 1*20, 1*20);
                p->fillRect(50 + (j + 3)*20 + 1,250 + i*20 + 1,1*20 - 1,1*20 - 1,QBrush(m_couleur));
            }
            else {

            }
        }
        p->setPen(QPen(QColor(255, 109, 0)));
        p->drawRect(80,200, 140, 140);
    }
}
*/

// Méthodes de rotations
// si l'orientation = {0,1,2} lorsque la rotation à droite est affectué, elle augmente 1 unité.
// si l'orientation = 3, elle devient 0 après la rotation.
void tetromino::rotationD()
{
    if (getOrientation() < 3)
    {
        setOrientation(getOrientation() + 1);
    }
    else {
        setOrientation(0);
    }
}

// si l'orientation = {1,2,3} lorsque la rotation à droite est affectué, elle diminue 1 unité.
// si l'orientation = 0, elle devient 3 après la rotation.
void tetromino::rotationG()
{
    if (getOrientation() > 0)
    {
        setOrientation(getOrientation() - 1);
    }
    else {
        setOrientation(3);
    }
}

// Méthode de deplacement
// Précondition :
// x à valeur dans {-20,20} , -20 pour déplacer à gauche, 20 pour déplacer à droit
// y ne prend que la valeur 20 car on ne peut que déplacer en bas.
void tetromino::deplacer(int x, int y)
{
    m_x += x;
    m_y += y;
}

// Mutateurs
void tetromino::setX(int x)
{
    m_x = x;
}

void tetromino::setY(int y)
{
    m_y = y;
}

void tetromino::setType(int type)
{
    m_type = type;
}

void tetromino::setCouleur(QColor couleur)
{
    m_couleur = couleur;
}

void tetromino::setOrientation(int o){
    m_orientation = o;
}

// Accesseurs
int tetromino::getX()
{
    return this->m_x;
}

int tetromino::getY()
{
    return this->m_y;
}

int tetromino::getType()
{
    return this->m_type;
}

QColor tetromino::getCouleur()
{
    return this->m_couleur;
}

int tetromino::getTabTetromino(int i,int j)
{
    return m_tabTetromino[m_orientation][i][j];
}

int tetromino::getOrientation(){
    return m_orientation;
}


int tetromino::getTabTetromino(int o,int i,int j)
{
    return m_tabTetromino[o][i][j];
}



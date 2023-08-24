#include "tetromino_s.h"

// Constructeur
tetromino_s::tetromino_s(int x, int y, QColor couleur,int type, int orientation) : tetromino(x, y, couleur, type, orientation)
{
    m_x = x;
    m_y = y;
    m_couleur = couleur;
    m_type = type;
    m_orientation = orientation;

    m_tabTetromino[0][0][2] = 1;
    m_tabTetromino[0][0][3] = 1;
    m_tabTetromino[0][1][1] = 1;
    m_tabTetromino[0][1][2] = 1;

    // orientation 1
    m_tabTetromino[1][0][2] = 1;
    m_tabTetromino[1][1][2] = 1;
    m_tabTetromino[1][1][3] = 1;
    m_tabTetromino[1][2][3] = 1;

    // orientation 2
    m_tabTetromino[2][1][2] = 1;
    m_tabTetromino[2][1][3] = 1;
    m_tabTetromino[2][2][1] = 1;
    m_tabTetromino[2][2][2] = 1;

    // orientation 3
    m_tabTetromino[3][0][1] = 1;
    m_tabTetromino[3][1][1] = 1;
    m_tabTetromino[3][1][2] = 1;
    m_tabTetromino[3][2][2] = 1;
}

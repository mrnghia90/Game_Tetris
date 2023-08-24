#ifndef TETROMINO_J_H
#define TETROMINO_J_H

#include "tetromino.h"

class tetromino_j : public tetromino
{
    public:
        // Constructeurs
        tetromino_j();
        tetromino_j(int x, int y, QColor couleur,int type, int orientation);
};

#endif // TETROMINO_J_H

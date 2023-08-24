#ifndef TETROMINO_L_H
#define TETROMINO_L_H

#include "tetromino.h"

class tetromino_l : public tetromino
{
    public:
        // Constructeurs
        tetromino_l();
        tetromino_l(int x, int y, QColor couleur,int type, int orientation);
};

#endif // TETROMINO_L_H

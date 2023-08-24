#ifndef TETROMINO_I_H
#define TETROMINO_I_H

#include "tetromino.h"

class tetromino_i : public tetromino
{
    public:
        // Constructeurs
        tetromino_i();
        tetromino_i(int x, int y, QColor couleur,int type, int orientation);
};

#endif // TETROMINO_I_H

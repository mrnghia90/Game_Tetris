#ifndef TETROMINO_S_H
#define TETROMINO_S_H

#include "tetromino.h"

class tetromino_s : public tetromino
{
    public:
        // Constructeurs
        tetromino_s();
        tetromino_s(int x, int y, QColor couleur,int type, int orientation);
};

#endif // TETROMINO_S_H

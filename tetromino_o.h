#ifndef TETROMINO_O_H
#define TETROMINO_O_H

#include "tetromino.h"

class tetromino_o : public tetromino
{
    public:
        // Constructeurs
        tetromino_o();
        tetromino_o(int x, int y, QColor couleur,int type, int orientation);
};

#endif // TETROMINO_O_H

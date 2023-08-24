#ifndef TETROMINO_T_H
#define TETROMINO_T_H


#include "tetromino.h"

class tetromino_t : public tetromino
{
    public:
        // Constructeurs
        tetromino_t();
        tetromino_t(int x, int y, QColor couleur,int type, int orientation);
};

#endif // TETROMINO_T_H

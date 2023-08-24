#ifndef TETROMINO_Z_H
#define TETROMINO_Z_H

#include "tetromino.h"

class tetromino_z : public tetromino
{
    public:
        // Constructeur
        tetromino_z();
        tetromino_z(int x, int y, QColor couleur,int type, int orientation);
};

#endif // TETROMINO_Z_H

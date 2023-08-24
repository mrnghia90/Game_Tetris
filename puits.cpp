#include "puits.h"

// Constructeur
puits::puits(int largeur, int hauteur){
    m_largeur = largeur;
    m_hauteur = hauteur;

    // Intialiser matrice m_puits
    for(int i = 0; i<hauteur;i++)
    {
        for(int j = 0;j <largeur; j++)
        {
            if ((j < 2) || (j > m_largeur -3) || (i > m_hauteur-3) || (i < 1))
                m_puits[i][j]=8;
            else
                m_puits[i][j]=0;
        }
    }

}

// Affichage
void puits::affichage(QPainter *feuilleDessin)
{
    // Affichage de puits
    feuilleDessin->setPen(QPen(QColor(255, 109, 0)));
    for(int i=0; i<=10; i++){
        if (i%2 == 1)
        {
            feuilleDessin->drawRect(300 + i*20 + 1,50, 20, 440);
            feuilleDessin->fillRect(300 + i*20 + 1,50, 20, 440,QColor(249, 251, 231));
        }
        else
        {   if (i != 10){
                feuilleDessin->drawRect(300 + i*20 + 1,50, 20, 440);
                feuilleDessin->fillRect(300 + i*20 + 1,50, 20, 440,QColor(251, 233, 231));
            }
        }
    }
    feuilleDessin->setPen(QPen(QColor(255, 109, 0)));
    feuilleDessin->drawLine(300+1,50+1,300+1,490+1);
    feuilleDessin->drawLine(300+1,50+1,300+ 10*20+1,50+1);
    feuilleDessin->drawLine(300+1,490+1,300+ 10*20+1,490+1);

    // Affichage de puits coloré des cases en fonction de type de tetromino actuel (correspond à sa couleur)
    for(int i = 2; i<m_hauteur-2;i++)
    {
        for(int j = 2;j<m_largeur-2; j++)
        {
            if(m_puits[i][j]!=0 ){
                feuilleDessin->setPen(QPen(Qt::white));
                feuilleDessin->drawRect(260+20*j,10+20*(i), 20 ,20);
                switch(m_puits[i][j]){
                    case 1:{feuilleDessin->fillRect(260+20*j+1,10+20*(i)+1, 20-1 ,20-1,QColor(255, 64, 129));break;}
                    case 2:{feuilleDessin->fillRect(260+20*j+1,10+20*(i)+1, 20-1 ,20-1,QColor(238, 255, 65));break;}
                    case 3:{feuilleDessin->fillRect(260+20*j+1,10+20*(i)+1, 20-1 ,20-1,QColor(234, 128, 252));break;}
                    case 4:{feuilleDessin->fillRect(260+20*j+1,10+20*(i)+1, 20-1 ,20-1,QColor(83, 109, 254));break;}
                    case 5:{feuilleDessin->fillRect(260+20*j+1,10+20*(i)+1, 20-1 ,20-1,QColor(178, 255, 89));break;}
                    case 6:{feuilleDessin->fillRect(260+20*j+1,10+20*(i)+1, 20-1 ,20-1,QColor(255, 138, 101));break;}
                    case 7:{feuilleDessin->fillRect(260+20*j+1,10+20*(i)+1, 20-1 ,20-1,QColor(29, 233, 182));break;}
                }
            }
        }
    }
}

// Traiter la ligne compléte
// Précontion :
bool puits::ligneComplete(int ligne)
{
    int cpt = 0;
    bool res = true;
    int i = 0;
    while(res && i < m_largeur){
        if (m_puits[ligne][i] == 0){
            res = false;
        }
        cpt++;
        i++;
    }
    return (cpt == m_largeur);
}

// Pour i de ligne à 1, par pas de -1
// Pour c de 0 à 10 (parcours des colonnes) :
//      puits[i][c] = puits[i-1][c]  // Une ligne reçoit le contenu de la ligne du dessus
//
// Cas de la ligne 0
// For c de 0 à 10
//      puits[0][c] = 0 ;
void puits::supprimmerLigne(int ligne)
{
    for (int i = ligne;i > 1;i--)
    {
        for (int c = 2; c< m_largeur - 2;c++){
            m_puits[i][c] = m_puits[i-1][c];
        }
    }
    // Cas ligne = 0
    for (int c = 2; c< m_largeur - 2;c++){
        m_puits[0][c] = 0;
    }
}

//
bool puits::fin()
{
    bool res = false;
    int i = 0;
    while(res == false && i < m_largeur)
    {
        if (m_puits[m_hauteur-1][i] == 1)
        {
            res = true;
        }
        i++;
    }
    return res;
}

// Mutateurs
void puits::setI(int i)
{
    m_i = i;
}

void puits::setJ(int j)
{
    m_j = j;
}


void puits::setCasePuits(int x, int y, int typeCase)
{
    m_puits[x][y] = typeCase;
}


// Accesseurs
int puits::getI()
{
    return m_i;
}

int puits::getJ()
{
    return m_j;
}

int puits::getCasePuits(int x, int y)
{
    return m_puits[x][y];
}

int puits::getLargeur()
{
    return m_largeur;
}
int puits::getHauteur()
{
    return m_hauteur;
}

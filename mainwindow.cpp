#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parti = new partie();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));



    nbIntTimer = 0;
    delete parti->getTetrominoActuel();

}

MainWindow::~MainWindow()
{
    delete timer;
    delete parti;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *) {
    // Declarer la feuille de dessin
    QPainter feuilleDessin(this);

    // Affichage le puits
    parti->getPuits()->affichage(&feuilleDessin);

    if (start == true){
        // Affichage le tetromino actuel et le puits actualisé
        parti->getTetrominoActuel()->affichage(&feuilleDessin);

        // Affichage le tetromino suivant
        parti->getTetrominoSuivant()->affichageSuivant(&feuilleDessin);
    }

    // Affichage des Statistiques
    this->ui->lb_nv_val->setText(QVariant(parti->getNiveau()).toString());
    this->ui->lb_score_val->setText(QVariant(parti->getScore()).toString());
    this->ui->lb_ligne_val->setText(QVariant(parti->getLignesTraitees()).toString());
    this->ui->lb_duree_val->setText(QVariant(nbIntTimer).toString());

}

void MainWindow::keyPressEvent ( QKeyEvent * event ) {
    switch(event->key())
    {
        case Qt::Key_Up  :
            {
                if (pause == false){
                    // Tant que nombre rotation est limité dans 4 fois et rotation à droite impossible. On décalage à gauche.
                    int n = 0;
                    while (n < 4 && !parti->rotationDroitePossible())
                    {
                        if (parti->deplacerGauchePossible())
                        {
                            parti->getTetrominoActuel()->deplacer(-20,0);
                        }
                        n++;
                    }
                    // Tant que nombre rotation tiest limité dans 4 fois et rotation à gauche impossible. On décalage à gauche.
                    int i=0;
                    while (i < 4 && !parti->rotationGauchePossible())
                    {
                        if (parti->deplacerDroitePossible())
                        {
                            parti->getTetrominoActuel()->deplacer(20,0);
                        }
                        i++;
                    }

                    // Si la rotation à droite est vérifié, on effectuer la rotation à droite.
                    if (parti->rotationDroitePossible())
                    {
                        parti->getTetrominoActuel()->rotationD();
                    }
                    else{
                        // Si la rotation à gauche est vérifié, on effectuer la rotation à gauche.
                        if (parti->rotationGauchePossible())
                            {
                                parti->getTetrominoActuel()->rotationG();
                            }
                    }
                }
                this->repaint();
            }
            break;

        case Qt::Key_Right :
            {
                // Si le déplacement à droite est vérifié, on effectuer le déplacement à droite.
                if (parti->deplacerDroitePossible() && pause == false)
                {
                    parti->getTetrominoActuel()->deplacer(20,0);
                }
            }
            break;

        case Qt::Key_Left :
            {
                // Si le déplacement à gauche est vérifié, on effectuer le déplacement à gauche.
                if (parti->deplacerGauchePossible() && pause == false)
                {
                    parti->getTetrominoActuel()->deplacer(-20,0);
                }
            }

            break;
        case Qt::Key_Down :
            {
                // Si le déplacement en bas est vérifié, on descend.
                if (parti->deplacerBasPossible() && pause == false)
                {
                    parti->getTetrominoActuel()->deplacer(0,20);
                }
            }
            break;
        case Qt::Key_Space :
            {
                // Si le déplacement en bas est vérifié, on chute librement.
                while (parti->deplacerBasPossible() && pause == false)
                {
                    parti->getTetrominoActuel()->deplacer(0,20);
                }
            }
            break;
    }

    this->repaint();
    //update();
}

void MainWindow::update() {
    nbIntTimer++;
    if (parti->deplacerBasPossible()) {
        parti->getTetrominoActuel()->deplacer(0,20);
    }

    else{
        // Lorsque un tetromino est bien posé. On va actualiser son type sur matrice de puits.
        for(int i = 0; i< 4;i++)
        {
            for(int j = 0;j < 4; j++)
            {
                if (parti->getTetrominoActuel()->getTabTetromino(i,j)==1)
                {
                    {
                        // Retrouver coordonnée dans la matrice m_puits (l,c) à partir de coordonnée d'interface graphique du tetromino actuel (getX, getY) et ses coordonnées matrice tabTetromino (i,j)
                        int l = (-50 + parti->getTetrominoActuel()->getY() +i*20)/20 + 2;
                        int c = (-240 + parti->getTetrominoActuel()->getX() +j*20)/20 + 2;
                        parti->getPuits()->setCasePuits(l,c,parti->getTetrominoActuel()->getType());
                    }
                }
            }
        }
        // Traitement les lignes commplétées et score
        int nb_ligneASupprimmer = 0;
        for(int i = 1; i< parti->getPuits()->getHauteur()-2; i++){
            if (parti->getPuits()->ligneComplete(i)){
                parti->getPuits()->supprimmerLigne(i);
                nb_ligneASupprimmer++;
            }
        }
        // Cumuler des points
        switch (nb_ligneASupprimmer) {
            case 1 : {parti->setScore(parti->getScore()+40);break;}
            case 2 : {parti->setScore(parti->getScore()+120);break;}
            case 3 : {parti->setScore(parti->getScore()+300);break;}
            case 4 : {parti->setScore(parti->getScore()+1200);break;}
        }

        // Cumuler des lignes totales
        parti->setLigneTraitees(parti->getLignesTraitees()+nb_ligneASupprimmer);

        // Vérifier niveau : supposons pour passer en niveau 1, on doit avoir 2000 points
        int p0 = 200;

        if (parti->getScore() >= p0*(parti->getNiveau() + 1) && parti->getNiveau() < 5){
            parti->setNiveau(parti->getNiveau()+1);
        }
        else{
            parti->setNiveau(parti->getNiveau()+0);
        }

        // Set la vitesse en fonction du niveau    delete parti->getTetrominoSuivant();



        switch(parti->getNiveau()){
            case 0: {vitesse = 1000;break;}
            case 1: {vitesse = 800;break;}
            case 2: {vitesse = 600;break;}
            case 3: {vitesse = 400;break;}
            case 4: {vitesse = 200;break;}
            case 5: {vitesse = 100;break;}
        }

        timer->start(vitesse);

        // Création tetromino actuel
        parti->setTetrominoActuel(parti->getTetrominoSuivant());

        if (parti->collision()){
            cout << "Perdu" << endl;
            timer->stop();
        }

        tetro_random = (rand() % 7) + 1;
        switch(tetro_random)
        {
            case 1: {parti->setTetrominoSuivant(new tetromino_i(300, 50, QColor(255, 64, 129), 1,0)); break;}
            case 2: {parti->setTetrominoSuivant(new tetromino_j(300, 50, QColor(238, 255, 65), 2,0));break;}
            case 3: {parti->setTetrominoSuivant(new tetromino_l(300, 50, QColor(234, 128, 252), 3,0));break;}
            case 4: {parti->setTetrominoSuivant(new tetromino_o(300, 50, QColor(83, 109, 254), 4,0));break;}
            case 5: {parti->setTetrominoSuivant(new tetromino_s(300, 50, QColor(178, 255, 89), 5,0));break;}
            case 6: {parti->setTetrominoSuivant(new tetromino_t(300, 50, QColor(255, 138, 101), 6,0));break;}
            case 7: {parti->setTetrominoSuivant(new tetromino_z(300, 50, QColor(29, 233, 182), 7,0));break;}
        }
    }

    this->repaint();
}

void MainWindow::on_start_clicked(){
    delete parti;
    delete timer;
    parti = new partie();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    nbIntTimer = 0;


    // Set la vitesse en fonction du niveau    delete parti->getTetrominoSuivant();
    if (parti->getNiveau() <= 5){
        switch(parti->getNiveau()){
            case 0: {vitesse = 1000;break;}
            case 1: {vitesse = 800;break;}
            case 2: {vitesse = 600;break;}
            case 3: {vitesse = 400;break;}
            case 4: {vitesse = 200;break;}
            case 5: {vitesse = 100;break;}
        }
    }
    timer->start(vitesse);

    this->ui->lb_nv_val->clear();
    this->ui->lb_score_val->clear();
    this->ui->lb_ligne_val->clear();
    this->ui->lb_duree_val->clear();

    start = true;
    this->repaint();
}

void MainWindow::on_pause_clicked(){
    if (pause == false){
        timer->stop();
        pause = true;
    }
     else{
        timer->start(vitesse);
        pause = false;
    }
}

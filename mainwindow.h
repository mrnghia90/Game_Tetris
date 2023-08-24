#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include "partie.h"
#include <QVariant>
#include <QString>

#include "puits.h"
#include "partie.h"
#include "tetromino.h"
#include "tetromino_i.h"
#include "tetromino_j.h"
#include "tetromino_l.h"
#include "tetromino_o.h"
#include "tetromino_s.h"
#include "tetromino_t.h"
#include "tetromino_z.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update();
    void on_start_clicked();
    void on_pause_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    void paintEvent(QPaintEvent *);
    void keyPressEvent ( QKeyEvent * event );
    void out_lb_score_val();
    partie * parti;
    int tetro_random;
    int nbIntTimer;
    int vitesse = 1000;
    bool start = false;
    bool pause = false;
};
#endif // MAINWINDOW_H

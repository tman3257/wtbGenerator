#ifndef WTB_H
#define WTB_H

#include <QtGui/QMainWindow>
#include <Qt\qdebug.h>
#include "ui_wtb.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class wtb : public QMainWindow
{
    Q_OBJECT

public:
    wtb(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~wtb();

    enum FactionTypes{
        Cygnar,
        Menoth,
        Khador,
        Cryx,
        Retribution,
        Mercs,
        Convergence,
        Trolls,
        Circle,
        Skorne,
        Legion,
        Minions
    };

private:
    Ui::wtbClass ui;

public slots:
    void rollCygnar(){ roll(Cygnar); }
    void rollMenoth(){ roll(Menoth); }
    void rollKhador(){ roll(Khador); }
    void rollCryx(){ roll(Cryx); }
    void rollRet(){ roll(Retribution); }
    void rollMercs(){ roll(Mercs); }
    void rollConvergence(){ roll(Convergence); }
    void rollTrolls(){ roll(Trolls); }
    void rollCircle(){ roll(Circle); }
    void rollSkorne(){ roll(Skorne); }
    void rollLegion(){ roll(Legion); }
    void rollMinions(){ roll(Minions); }
    void accept();
    void reroll();
    void newRound();

public:
    


    std::vector<std::vector<std::string>> factions;
    std::vector<std::string> curCasters;
    int randFaction;
    int randCaster;
    FactionTypes m_CurFaction;
    int m_NumCasters;
    

    void roll(FactionTypes curFaction);
    
};

#endif // WTB_H

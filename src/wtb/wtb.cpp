#include "wtb.h"

wtb::wtb(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    
    ui.setupUi(this);    
    connect(ui.cygnarButton, SIGNAL(released()),this, SLOT(rollCygnar()));
    connect(ui.menothButton, SIGNAL(released()),this, SLOT(rollMenoth()));
    connect(ui.khadorButton, SIGNAL(released()),this, SLOT(rollKhador()));
    connect(ui.cryxButton, SIGNAL(released()),this, SLOT(rollCryx()));
    connect(ui.retButton, SIGNAL(released()),this, SLOT(rollRet()));
    connect(ui.mercsButton, SIGNAL(released()),this, SLOT(rollMercs()));
    connect(ui.conButton, SIGNAL(released()),this, SLOT(rollConvergence()));
    connect(ui.trollButton, SIGNAL(released()),this, SLOT(rollTrolls()));
    connect(ui.circleButton, SIGNAL(released()),this, SLOT(rollCircle()));
    connect(ui.skorneButton, SIGNAL(released()),this, SLOT(rollSkorne()));
    connect(ui.legionButton, SIGNAL(released()),this, SLOT(rollLegion()));
    connect(ui.minionsButton, SIGNAL(released()),this, SLOT(rollMinions()));
    connect(ui.acceptButton, SIGNAL(released()), this, SLOT(accept()));
    connect(ui.rerollButton, SIGNAL(released()), this, SLOT(reroll()));
    connect(ui.newRoundButton,SIGNAL(released()),this,SLOT(newRound()));
    connect(ui.playerListButton,SIGNAL(released()),this,SLOT(showPlayerListWindow()));

    std::string line;
    std::ifstream casterFile("casters.txt");
    int curFaction = 0;
    std::vector<std::string> caster;
    m_NumCasters = 0;

    if(casterFile.is_open())
    {
        while (getline(casterFile,line))
        {
            if(line.at(0) == '#')
            {
                factions.insert(factions.begin() + curFaction,caster);                
                caster.clear();
                if(line.substr(1,line.length()-1).compare("Cygnar") == 0)
                {
                    curFaction = Cygnar;
                }
                else if(line.substr(1,line.length()-1).compare("Menoth") == 0)
                {
                    curFaction = Menoth;
                }
                else if(line.substr(1,line.length()-1).compare("Khador") == 0)
                {
                    curFaction = Khador;
                }
                else if(line.substr(1,line.length()-1).compare("Cryx") == 0)
                {
                    curFaction = Cryx;
                }
                else if(line.substr(1,line.length()-1).compare("Retribution") == 0)
                {
                    curFaction = Retribution;
                }
                else if(line.substr(1,line.length()-1).compare("Mercenaries") == 0)
                {
                    curFaction = Mercs;
                }
                else if(line.substr(1,line.length()-1).compare("Convergence") == 0)
                {
                    curFaction = Convergence;
                }
                else if(line.substr(1,line.length()-1).compare("Trolls") == 0)
                {
                    curFaction = Trolls;
                }
                else if(line.substr(1,line.length()-1).compare("Circle") == 0)
                {
                    curFaction = Circle;
                }
                else if(line.substr(1,line.length()-1).compare("Skorne") == 0)
                {
                    curFaction = Skorne;
                }
                else if(line.substr(1,line.length()-1).compare("Legion") == 0)
                {
                    curFaction = Legion;
                }
                else if(line.substr(1,line.length()-1).compare("Minions") == 0)
                {
                    curFaction = Minions;
                }

            }
            else
            {
                caster.push_back(line);
            }
            
        }
        factions.insert(factions.begin() + curFaction,caster);
        factions.pop_back();
    }

    srand((unsigned)time(0));    
}

wtb::~wtb()
{
    
}

void wtb::roll(FactionTypes curFaction)
{
    randFaction = std::rand() % factions.size();
    int size = factions.size();
    int castersize = factions.at(randFaction).size();
    randCaster = std::rand() % factions.at(randFaction).size();
    m_CurFaction = curFaction;

    if(randFaction == curFaction)
    {
        roll(curFaction);
        return;
    }

    if(factions.at(randFaction).size() == 0)
    {
        roll(curFaction);
        return;
    }

    for(int i = 0; i < curCasters.size(); i ++)
    {
        if(curCasters.at(i).compare(factions.at(randFaction).at(randCaster)) == 0)
        {
            roll(curFaction);
            return;
        }
    }
    

    
    switch(randFaction)
    {
        case Cygnar:
        {
            ui.factionResult->setText("<font color = 'blue'>Cygnar</font>");
            ui.casterResult->setText("<font color = 'blue'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Menoth:
        {
            ui.factionResult->setText("<font color='orange'>Menoth</font>");
            ui.casterResult->setText("<font color = 'orange'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Khador:
        {
            ui.factionResult->setText("<font color='red'>Khador</font>");
            ui.casterResult->setText("<font color = 'red'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Cryx:
        {
            ui.factionResult->setText("<font color='green'>Cryx</font>");
            ui.casterResult->setText("<font color = 'green'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Retribution:
        {
            ui.factionResult->setText("<font color='teal'>Retribution</font>");
            ui.casterResult->setText("<font color = 'teal'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Mercs:
        {
            ui.factionResult->setText("<font color='brown'>Mercenaries</font>");
            ui.casterResult->setText("<font color = 'brown'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Convergence:
        {
            ui.factionResult->setText("<font color='teal'>Convergence</font>");
            ui.casterResult->setText("<font color = 'teal'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Trolls:
        {
            ui.factionResult->setText("<font color='blue'>Trolls</font>");
            ui.casterResult->setText("<font color = 'blue'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Circle:
        {
            ui.factionResult->setText("<font color='green'>Circle</font>");
            ui.casterResult->setText("<font color = 'green'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Skorne:
        {
            ui.factionResult->setText("<font color='red'>Skorne</font>");
            ui.casterResult->setText("<font color = 'red'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Legion:
        {
            ui.factionResult->setText("<font color='purple'>Legion</font>");
            ui.casterResult->setText("<font color = 'purple'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
        case Minions:
        {
            ui.factionResult->setText("<font color='green'>Minions</font>");
            ui.casterResult->setText("<font color = 'green'>" +QString::fromStdString(factions.at(randFaction).at(randCaster))+"</font>");
            break;
        }
    }

    ui.acceptButton->setEnabled(true);
    
}

void wtb::accept()
{
    curCasters.push_back(factions.at(randFaction).at(randCaster));
    if(ui.playerNameBox->text().compare("") == 0)
    {
        ui.playerNameBox->setText("Player " + QString::fromStdString(std::to_string((long long)m_NumCasters)));
    }
    playerMap[ui.playerNameBox->text().toStdString()] = factions.at(randFaction).at(randCaster);
    ui.factionResult->setText("Caster added to round!");
    ui.casterResult->setText("PICK YOUR FACTION");
    m_NumCasters++;
    ui.numCastersLabel->setText(QString::number(m_NumCasters));
    ui.playerNameBox->setText("");
    ui.acceptButton->setDisabled(true);

}

void wtb::reroll()
{
    roll(m_CurFaction);
}

void wtb::newRound()
{
    curCasters.clear();
    playerMap.clear();
    ui.factionResult->setText("New Round Started!");
    ui.casterResult->setText("PICK YOUR FACTION");
    ui.numCastersLabel->setText("0");
    ui.playerNameBox->setText("");
    m_NumCasters = 0;
}

void wtb::showPlayerListWindow()
{
    wchar_t* command = L"open";
    wchar_t* file = L"PlayerList.html";
    writePlayerFile();
    ShellExecute(NULL, command, file, NULL, NULL, SW_SHOWNORMAL);
}

void wtb::writePlayerFile()
{
    std::ofstream file("PlayerList.html");

    if(file.is_open())
    {
        file << "<html>";
        file << "   <body>";
        file << "       <table border=\"1\" style=\"width:50%\">";

        std::map<std::string, std::string>::iterator it;
        
        for(it = playerMap.begin(); it != playerMap.end() ; it ++)
        {
            file << "           <tr>";
            file << "               <td>" + it->first + "</td>";
            file <<"                <td>" + it->second + "</td>";
            file << "           </tr>";
        }

        file << "       </table>";
        file << "   </body>";
        file << "</html>";
        file.close();
    }
    else
    {
        std::cout << "Unable to open file.";
    }
    return;
}
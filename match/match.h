#ifndef MATCH_H
#define MATCH_H
#include "commons.h"
#include "coach/coach.h"
#include "detection/data_manager.h"

class Match
{
public:
    // Cor no nosso time
    Commons::Color team_color = Commons ::YELLOW;
    // Implementação do coach
    Coach *coach;
    // Looping de iteração onde o match ira enviar para o Coach
    SSLVisionClientThread *visionThread;
    virtual void loop(noplan_detection *detection)=0;
    // Inicialização de parametros iniciais referentes a partida
    virtual void setup()=0;
    // Define o coach e já faz inicialização se preciso
    virtual void define_coach(Coach *coach, noplan_detection *detection)=0;
};

#endif // MATCH_H

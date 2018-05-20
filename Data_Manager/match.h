#ifndef MATCH_H
#define MATCH_H
#include "commons.h"
#include "coach.h"
#include "data_manager.h"

class Match
{
public:
    // Cor no nosso time
    Commons::Color team_color = Commons::YELLOW;
    // Implementação do coach
    Coach coach;
    // Looping de iteração onde o match ira enviar para o Coach
    SSLVisionClientThread *visionThread;
    void loop(noplan_detection detection);
    // Inicialização de parametros iniciais referentes a partida
    void setup();
    // Define o coach e já faz inicialização se preciso
    void define_coach(Coach coach);
};

#endif // MATCH_H

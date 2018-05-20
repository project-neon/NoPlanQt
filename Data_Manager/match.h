#ifndef MATCH_H
#define MATCH_H
#include "commons.h"
#include "coach.h"
#include "data_manager.h"

class Match
{
public:
    // Cor no nosso time
    Commons::Color team_color = Commons::BLUE;
    // Implementação do coach
    Coach coach;
    // Looping de iteração onde o match ira enviar para o Coach
    SSLVisionClientThread *visionThread;
    void loop();
    // Inicialização de parametros iniciais referentes a partida
    void setup();
};

#endif // MATCH_H

#include "match.h"

class DummyMatch : public Match {
    void defineCoach(Coach coach) {
        this->coach = coach;
    }
    // Faz iteração do Coach
    void loop() {

    }
    // Cria o coach e recebe dados da UI
    void setup() {

    }
};

int main(int argc, char **argv) {
    Match match = DummyMatch();

}

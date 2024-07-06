#include <iostream>
#include <vector>
#include <string>

using namespace std;

//PADEL: um set são 6 jogos

class JogoPadel {
    int pontosA;
    int pontosB;
 

public:
     JogoPadel () {
        cout << "novo jogo";
        pontosA = 0;
        pontosB = 0;
    }
    void start(){
        cout << "inicia";
    }
};

class SetPadel {
    vector<JogoPadel> jogos;

  public:
    SetPadel () {
        cout << "novo Set";
        JogoPadel jogo;
        jogo.start();
        jogos.push_back(jogo);
    }
};

int main(){
    SetPadel padel;

}
#include <iostream>  
using namespace std;  
#include <string>  
//#include "classes.h"  
#include <stdexcept>  
  
class Game {  
  
public:  
    Game(int heaps, int players): myheaps(heaps), myplayers(players), c(new int[heaps]),  
    playermatrix(new Player*[players]) {}  
    ~Game() {}  
    void addHeap(int coins) {if (l>=myheaps) throw logic_error("invalid heap");   c[l++]=coins; }  
    void addPlayer(Player *player) {if (k>=myplayers) throw logic_error("invalid player");  
        playermatrix[k++]=player;}  
    void play(ostream &out)  
    {  
State s= State(myheaps,c,myplayers);  
int j=0;  
while (!s.winning()){  
    cout<<"State: "<<s<<endl;           //out  
Move h=playermatrix[j]->play(s);  
    cout<<*playermatrix[j]<<" "<<h<<endl;      //out  
s.next(h);  
    if (!s.winning()) {  
        j++; j%=(myplayers);  
    }  
  
    }  
cout<<"State: "<<s<<endl;  
cout<<*playermatrix[j]<<" "<<"wins"<<endl;  
    }  
    int getPlayers() const { return myplayers; }  
    const Player *getPlayer(int p) const { if (p>=myplayers) throw logic_error("invalid player");  
        return playermatrix[p];}  
  
private:  
  int myheaps;  
  int myplayers;  
  int *c;  
    Player **playermatrix;  
    int k=0;  
  int l=0;  
};  

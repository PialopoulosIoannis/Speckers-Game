#include <iostream>  
using namespace std;  
#include <stdexcept>  
  
  
class Move {  
  
public:  
    Move(int sh, int sc, int th, int tc);  
  
    int getSource() const;  
    int getSourceCoins() const;  
    int getTarget() const;  
    int getTargetCoins() const;  
  
    friend ostream& operator<<(ostream &out, const Move &move);  
  
private:  
    int sourceh, sourcec, targeth, targetc;  
  
};  
  
Move:: Move(int sh, int sc, int th, int tc) {  
    sourceh = sh;  
    sourcec = sc;  
    targeth = th;  
    targetc = tc;  
  
}  
int Move::getSource() const {  
    return sourceh;  
}  
int Move::getSourceCoins() const {  
    return sourcec;  
}  
int Move::getTarget() const {  
    return targeth;  
}  
int Move::getTargetCoins() const {  
    return targetc;  
}  
  
ostream& operator<<(ostream &out, const Move &move) {  
    out<<"takes " <<move.getSourceCoins();  
    out<<" coins from heap ";  
    out<<move.getSource();  
    out<<" and puts ";  
    if (move.getTargetCoins()!=0) {  
        out<<move.getTargetCoins();  
        out<<" coins to heap ";  
        out<<move.getTarget();  
    }  
    else out<<"nothing";  
    return out;  
}  
  
class State {  
public:  
  
    State(int h, const int c[], int n) {  
        heaps=h;  
        players=n;  
        a = new int[heaps];  
        for (int i=0; i<heaps; i++)  
            a[i]=c[i];  
  
        whoplaysnow=0;  
    }  
  
  
    ~State() { delete[] a; }  
  
    void next(const Move &move) {  
       // cout<<move;  
  
  
        if (move.getSource() < 0 || move.getSource() >= heaps) throw logic_error("invalid heap");  
        if (move.getTarget() < 0 || move.getTarget() >= heaps) throw logic_error("invalid heap");  
       if (move.getSourceCoins() <= 0 || move.getSourceCoins() > a[move.getSource()]) throw logic_error("invalid coins");  
       if (move.getTargetCoins() < 0) throw logic_error("invalid coins");  
        if (move.getTargetCoins()>=move.getSourceCoins()) throw logic_error("invalid coins");  
    a[move.getSource()]-=move.getSourceCoins();  
    a[move.getTarget()]+=move.getTargetCoins();  
        whoplaysnow++;  
        if (whoplaysnow==players)  
            whoplaysnow=0;  
    }  
    bool winning() const {  
        for (int i=0; i<heaps; i++)  
            if (a[i]!=0) return false;  
        return true;  
    }  
    int getHeaps() const { return heaps; }  
    int getCoins(int h) const {  
        if (h < 0 || h >= heaps) throw logic_error("invalid heap");  
        return a[h];  
    }  
  
    int getPlayers() const { return players; }  
    int getPlaying() const {return whoplaysnow;}  
  
    friend ostream & operator << (ostream &out, const State &state) {  
for (int i=0; i<state.heaps; i++) {  
    out<<state.a[i];  
    if (i!=state.heaps-1)  
        out<<", ";  
}  
    out<<" with "<<state.whoplaysnow<<"/"<<state.players<<" playing next";  
  
        return out;  
  
    }  
  
private:  
    int heaps;  
    int players;  
    int* a;  
    int whoplaysnow;  
  
  
};  

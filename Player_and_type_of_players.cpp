#include <iostream>  
using namespace std;  
#include <string>  
//#include "movestate.h"  
  
  
  
  
  
class Player {  
  
public:  
        Player(const string &n):  name(n) {}   //constructor  
  virtual ~Player() {};  
virtual const string & getType() const=0;  
virtual Move play(const State &s) =0;  
    friend ostream & operator << (ostream &out, const Player &player)  
{  
    out<< player.getType()<<" player "<< player.name;  
    return out;  
}  
  
  
  
private:  
    string name;  
};  
  
  
class GreedyPlayer : public Player  {  
  
public:  
    GreedyPlayer(const string &n)  :  Player(n), type("Greedy") {}  
    const string & getType() const override{ return type; }  
Move play(const State &s) override {  
int l=0;  
for (int i=0; i<s.getHeaps(); i++) {  
  
    if (s.getCoins(l)<s.getCoins(i) && s.getCoins(i)!=0) l=i;  
  
}  
        int all=s.getCoins(l);  
  
Move k(l,all,1,0);  
        return k;  
    }  
private:  
    string type;  
};  
  
class SpartanPlayer : public Player {  
  
public:  
  
SpartanPlayer(const string &n) :  Player(n), type("Spartan") {}  
    const string & getType() const override{ return type; }  
    Move play(const State &s) override {  
  
        int l=0;  
        for (int i=0; i<s.getHeaps(); i++) {  
            if (s.getCoins(l)<s.getCoins(i) && s.getCoins(i)!=0 ) l=i;  
        }  
  
  
        Move k(l,1,1,0);  
        return k;  
  
    }  
private:  
    string type;  
};  
  
class SneakyPlayer : public Player {  
  
public:  
    SneakyPlayer(const string &n) :  Player(n), type("Sneaky") {}  
    const string & getType() const override{ return type; }  
  
    Move play(const State &s) override {  
        int l=0;  
        while (s.getCoins(l)==0) l++;  
        for (int i=0; i<s.getHeaps(); i++) {  
  
            if (s.getCoins(l)>s.getCoins(i) && s.getCoins(i)!=0) l=i;  
        }  
  
        int all=s.getCoins(l);  
        Move k(l,all,1,0);  
        return k;  
    }  
private:  
    string type;  
};  
  
  
class RighteousPlayer : public Player {  
public:  
  
    RighteousPlayer(const string &n) : Player(n), type("Righteous") {}  
    const string & getType() const override{ return type; }  
Move play(const State &s) override {  
        int l=0;  
        for (int i=0; i<s.getHeaps(); i++) {  
            if (s.getCoins(l)<s.getCoins(i) && s.getCoins(i)!=0) l=i;  
        }  
        int take;  
        if (s.getCoins(l)%2==1) {take=(s.getCoins(l)/2)+1;} else take=(s.getCoins(l)/2);  
  
  
  
  
        int p=0;  
  
        for (int i=0; i<s.getHeaps(); i++) {  
            if (s.getCoins(p)>s.getCoins(i) ) p=i;  
        }  
  
  
        Move k(l,take,p,take-1);  
        return k;  
    }  
private:  
   string type;  
};  

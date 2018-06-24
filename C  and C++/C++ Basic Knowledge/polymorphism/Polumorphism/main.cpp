#include <iostream>
using namespace std;

class Game
{
   int g;
   public:
       Game()
       {
          g = 1;
       }
       virtual void show()
       {
          cout <<g;
       }
};

class Anim: public Game
{
   int k;
   public:
       Anim()
       {
          k = 2;
       }
       virtual void show()
       {
          cout <<k;

        }
};


int main()
{
    Game *g;
    //g->show();
    Anim a; g = &a; g->show();
    while(1);
    return 0;
}

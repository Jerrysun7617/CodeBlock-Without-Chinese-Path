#include <iostream>
#include <memory>
using namespace std;

class song{
private:
    string name;
public:
    song(){}
    song(string n)
    {
        name = n;
    }
    void printname(void){
        cout<<name<<endl;
    }
};

int main()
{
    song * sg = new song("song01");
    sg->printname();

    //unique_ptr<song> sg2 = song("song02"); //不能这么申请
    unique_ptr<song> sg2(new song);

    unique_ptr<song> cp = move(sg2);

    cp->printname();

    delete sg;
    //delete sg2;
    //unique_ptr<song> sg3(sg2);
    getchar();
    return 0;
}

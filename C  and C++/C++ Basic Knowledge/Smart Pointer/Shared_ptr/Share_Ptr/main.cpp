#include <iostream>
#include <memory>
using namespace std;

class song{
private:
    string name;
public:
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

    unique_ptr<song> sg2(new song("song02"));
    sg2->printname();


    auto sp1 = make_shared<song>("song03");
    sp1->printname();


    shared_ptr<song> sp2(new song("song4"));

    sp2->printname();
    shared_ptr<song> sp5(sp1);

    //sp5 = make_shared<song>("song5");
    sp5->printname();

    getchar();
    return 0;
}

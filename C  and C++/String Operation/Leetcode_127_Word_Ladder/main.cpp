#include <iostream>
#include <vector>
using namespace std;
//start: 18:13
//end:
#define Others
struct diff{
    char str;
    int num;
    int position;
};
struct diff different_num(string s1, string v1){
    struct diff numi = {' ',0,0};
    for(int i = 0 ; i < s1.size();i++)
        if(s1[i] != v1[i]){
            numi.num++;
            numi.position = i;
            numi.str = v1[i];
        }
    return numi;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

#ifdef Others
     vector<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail;
                ptail = &head;
            }
            vector<string> temp;
            for (auto itr = phead -> begin(); itr != phead -> end(); itr++) {
                string word = *itr;
                wordDict.erase(word);
                for (int p = 0; p < (int)word.length(); p++) {
                    char letter = word[p];
                    for (int k = 0; k < 26; k++) {
                        word[p] = 'a' + k;
                        if (ptail -> find(word) != ptail -> end())
                            return dist;
                        if (wordDict.find(word) != wordDict.end()) {
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            dist++;
            swap(*phead, temp);
        }
        return 0;

#else
    if(beginWord.size() <=1 || endWord.size() <=1 || wordList.size()<=1 )
        return 0;
    char * zifu = new char[beginWord.size()+ 1];
    struct diff test  = {' ',0,0};
    //cout<<different_num(beginWord,endWord)<<endl;
    int steps = 0;
   //while(1)
    {
        //if(beginWord.compare(endWord) == 0)
        //    break;
         int i = 0;
         bool flag = true;
         for(vector<string>::iterator itr = wordList.begin();itr < wordList.end(); i++)
         {
             if()
             test = different_num(beginWord,*itr);
            if( test.num == 1){
                     //cout<<beginWord<<"   "<<*itr <<endl;
                //cout<<test.num<<"  "<<test.position<<"   "<<test.str<<endl;
                //for(int i = 0; i < endWord.size(); i++){
                    //cout<<test.str<<"   "<<(char)endWord[i] <<endl;
                   // if(test.str == (char)endWord[i])
                        {
                        //cout<<test.str<<"   "<<(char)endWord[i] <<endl;
                        beginWord[test.position] = test.str;
                        wordList.erase(itr);//        ->erase(wordList[i]);
                        steps++;
                        flag = false;
                        //cout<<beginWord <<endl;
                       //cout<<*itr <<endl;
                       // while(1);
                      // break;
                   // }
                }
                //cout<<*itr <<endl;
            }

            if(flag){
                itr++;
            }
            else{
                flag = true;
            }
            //cout<<*itr <<endl;
        }
    }
    delete [] zifu;
    //ladderLength();

    if(beginWord.compare(endWord) != 0)
        steps  = 0;
    return steps;
#endif
}

int main()
{
    //cout << "Hello world!" << endl;

    while(1){
        string beginWord = "hit";
        string endWord = "cog";
        string init[6] =  {"hot","dot","dog","lot","log","cog"};
        vector<string> wordList(init,init+6);
        cout<<ladderLength(beginWord,endWord,wordList)<<endl;

        while(1);
    }
    return 0;
}

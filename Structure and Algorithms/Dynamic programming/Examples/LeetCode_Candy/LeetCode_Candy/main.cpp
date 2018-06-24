#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

*/
/****************随机无重复数 int****************/
vector<int> get_rand_norepeat_int(int min, int max){
   vector<int> temp;
    for (int i = min; i <= max; ++i)
        temp.push_back(i);

    //关键函数 在 #include <algorithm>里
    random_shuffle(temp.begin(), temp.end());

    return temp;
}
int candy(vector<int> &ratings) {
    int len = ratings.size();
    if(len <= 1)
        return 1;
     int sum = 0;
     vector<int> vec(len,1);

     for(int i = 1; i < len; i++)
     {
         if( ratings[i] > ratings[i-1])
            vec[i] = vec[i-1] + 1;
     }

     for(int i = len - 1; i >=1;i--)
     {
         if(ratings[i] < ratings[i-1] ){
                if(i !=  1)
                {
                    //cout<<ratings[i-1]<<" "<<ratings[i-2]<<" "<<vec[i-1]<<" "<<vec[i-2]<<endl;
                    if((ratings[i-1] > ratings[i-2]) && (vec[i-1] > vec[i-2])&& (vec[i-1] > vec[i]))
                      {

                      }
                    else
                      vec[i - 1] = vec[i] + 1;
                }
                else
                {
                    vec[i - 1] = vec[i] + 1;
                }
         }
     }

     for(int i = 0; i < len; i++)
     {
         cout<<ratings[i]<<"  "<<vec[i]<<endl;
         sum += vec[i];
     }

    return sum;
}

int main()
{
    int num[6] = {1,3,4,3,2,1};
    vector<int> vec(num,num+6);// = get_rand_norepeat_int(0,10);

    cout<<candy(vec)<<endl;

    while(1);

    return 0;
}

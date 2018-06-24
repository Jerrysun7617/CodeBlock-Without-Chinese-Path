#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
/*
There are N gas stations along a circular route, where the amount of gas at station i isgas[i].
You have a car with an unlimited gas tank and it costscost[i]of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Note:
The solution is guaranteed to be unique.
*/
/****************随机重复数 int****************/
int get_rand(int min, int max){
    return (rand() % (max-min + 1))+ min;
}
/****************随机无重复数 int****************/
vector<int> get_rand_norepeat_int(int min, int max){
   vector<int> temp;
    for (int i = min; i <= max; ++i)
        temp.push_back(i);

    //关键函数 在 #include <algorithm>里
    random_shuffle(temp.begin(), temp.end());

    return temp;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    for(int i = 0; i < gas.size();i++)
        cout<<gas[i]<<" ";
    cout<<endl;
    for(int i = 0; i < cost.size();i++)
        cout<<cost[i]<<" ";
    cout<<endl;


    int len_gas = gas.size();
    int len_cost = cost.size();

    int index = -1;
    int travel = 0;
    gas.insert(gas.end(),gas.begin(),gas.end());
    cost.insert(cost.end(),cost.begin(),cost.end());
    //cost + cost;

    for(int i = 0; i < len_gas;i++){
        travel = i;
        int cur_gas = gas[i];
        int ending = true;
         for(int j = i; j < len_cost+i;j++){
            cur_gas -= cost[j];
            if(cur_gas < 0)
            {
                ending = false;
                break;
            }
            if(j+1 <= len_cost+i)
            {
                cur_gas += gas[j+1];
            }
         }
         if(ending)
            return travel;
    }
    return index;
}
#ifdef Wrong_way
    for(int i = 0; i < len_gas;i++){
        travel = i;
        int cur_gas = gas[i];
        int ending = true;
       for(int j = i; j < len_cost;j++)
            if(cur_gas < cost[j])
            {
                ending = false;
                break;
            }
            else{
                cur_gas -= cost[j];
                if(cur_gas < 0)
                {
                    ending = false;
                    break;
                }
                if(cur_gas < gas[j+1] && j+1 <= len_cost)
                {
                    cur_gas += gas[j+1];
                }
            }
        if(ending){
            for(int j = 0; j < i;j++){
                cur_gas += gas[j];
                if(cur_gas < cost[j])
                {
                    ending = false;
                    break;
                }
                else{
                    cur_gas -= cost[j];
                    if(cur_gas < 0)
                    {
                        ending = false;
                        break;
                    }
                    if(cur_gas < gas[j+1] && j+1 <i)
                    {
                        cur_gas += gas[j+1];
                    }
                }
            }
        }

        if(ending)
            return travel;
    }
#endif

int main()
{
    int num[10] = {1,2,3,4,5,3,9,9,1,2};
    int num1[10] = {3,4,5,1,2,8,7,1,10,5};
    vector<int> gas(num,num+5),cost(num1,num1+5);// = get_rand_norepeat_int(0,10);
    /*
    for(int i = 0; i < 5;i++)
        gas.push_back(get_rand(2,5));

    for(int i = 0; i < 5;i++)
        cost.push_back(get_rand(1,3));
    */
    cout<<canCompleteCircuit(gas,cost)<<endl;

    while(1);

    return 0;
}

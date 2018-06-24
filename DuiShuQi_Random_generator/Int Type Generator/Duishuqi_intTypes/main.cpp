#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
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
/* This is the correct ways*/
int solve_01(int m, int n) {
    int ans = 0, flag;
    for(int h = m; h <= n; h++) {
        int s = h;
        int a[10]={0};
        //memset(a, 0, sizeof(a));
        flag = 0;
        while(s) {
            int k = s % 10;
            a[k]++;
            s /= 10;
        }
        for(int i = 0; i <= 9; i++) {
            if(a[i] >= 2) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) ans++;
    }
    return ans;
}

bool judge_number(int zh){
    vector<int> vec;
    while(zh > 0)
    {
        vec.push_back(zh%10);
        zh /= 10;
    }

    for(int i = 0;i < vec.size() - 1;i++)
        for(int j = i+1;j < vec.size();j++)
            if(vec[i] == vec[j])
                return false;

    return true;
}

/* This is my way needed to be tested*/
int solve_02(int n1,int n2){
    int num = 0;
    for(int i = n1;i <= n2; i++){
        if(judge_number(i))
            num++;
    }
    return num;
}
/*
··这里是is equal方法，对比练功方法产生的结果是否一样，
    如果相等则返回true， 如果不相等则返回false
*/
bool is_equal(int an01,int an02){
    if(an01 == an02)
        return true;
    else
        return false;
}
int main() {

    vector<int> random_num = get_rand_norepeat_int(0,10);
    int test_num = 500;
    int n1,n2;
    while(--test_num){
         n1 = get_rand(0,5000);
         n2 = get_rand(n1+1,5001);
         cout<<"Test num: "<<n1<<" "<<n2<<endl;
        if(!is_equal(solve_01(n1,n2),solve_02(n1,n2)))
            break;
    }
    if(test_num)
        cout<<n1<<" "<<n2<<endl;
    else
        cout<<"Get a correct anwser!"<<endl;

    while(1);
    return 0;
}

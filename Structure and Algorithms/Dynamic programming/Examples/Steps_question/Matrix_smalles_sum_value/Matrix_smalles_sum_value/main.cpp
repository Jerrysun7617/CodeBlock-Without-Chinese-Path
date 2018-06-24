#include <iostream>
#include <vector>
using namespace std;

/*********
start: 19:55
Prediction: 18:15
end:
*********/

int getMin(vector<vector<int> > map, int n, int m) {
    // write code here
    vector<int> fir(m,0);
    vector<vector<int>> vec;
    for(int i = 0; i < n; i++){
        vec.push_back(fir);
    }

    //first
     vec[0][0]  = map[0][0];
    for(int i = 1; i < m ;i++)
        vec[0][i] = map[0][i] +  vec[0][i-1] ;
    for(int i = 1; i < n ;i++)
        vec[i][0] = map[i][0] + vec[i -1][0];

    if(n == 0 )
        return vec[0][m-1];
    if(m==0)
        return  vec[n-1][0];

    for(int j = 1;j < n ; j++)
        for(int i = 1; i< m ; i++)
        {
            if(vec[j-1][i] > vec[j][i-1])
                vec[j][i] = vec[j][i-1] + map[j][i];
            else
                vec[j][i] = vec[j-1][i] + map[j][i];
        }
        /*
    for(int j = 0;j < n ; j++){
        for(int i = 0; i< m ; i++)
            cout<<vec[j][i]<<" ";
        cout<<endl;
    }
    */
    return vec[n-1][m-1];
}
int main()
{
    //cout << "Hello world!" << endl;
    int n,m;
    while(cin>>n>>m){
        vector<int> fir(m,0);
        vector<vector<int>> vec;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++)
                cin>>fir[j];
            vec.push_back(fir);
        }
        cout<<getMin(vec,n,m)<<endl;
    }

    return 0;
}

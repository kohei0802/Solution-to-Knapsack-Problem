#include <iostream>
#include <vector>
using namespace std;

//Add Dp feature later
vector<vector<long long>> dp;


//w[i] -> item i's weight
vector<long long> w(51, 0);
//v[i] -> item i's value
vector<long long> v(51, 0);

int knapsack(int N, long long W, long long val);

int main()
{
    // N -> No. of items  W -> weight limitation
    int N;
    long long W; 
    cin>>N>>W;
    w.assign(N+1, 0);
    v.assign(N+1, 0);
    //insert input to weight & value lists
    for (int i=1; i<=N; i++) {
        cin >> w[i];
        cin >> v[i];
    }
    
    cout << knapsack(N, W, 0) << endl;

    return 0;
}


int knapsack(int N, long long W, long long val = 0) {
    static long long Max = 0;
    
    //Max value is compared at the base case
    if (N==0) {
        Max = max(val, Max);
        return 0; 
        //return value is arbitary
    }
    
    //Max value is compared after weight <=0
    if (W==0) {
        Max = max(val, Max);
        return 0;
        //return value is arbitary
    }
    
    //not bought
    knapsack(N-1, W, val);
    //bought
    if (W >= w[N]){
        knapsack(N-1, W - w[N], val + v[N]);
    }
    
    return Max;
}


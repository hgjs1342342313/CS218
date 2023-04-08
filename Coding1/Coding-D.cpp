#include<iostream>
#include<vector>

using namespace std;

int main(){
    int w, n;
    cin>>w>>n;
    vector<int> weight;
    vector<int> value;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        weight.push_back(a);
        value.push_back(b);
    }
    vector<int> dp;
    for(int i=0; i<=w; i++){
        dp.push_back(0);
    }
    for(int i=0; i<n; i++){
        for(int j=w; j>=weight[i]; j--){
            dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[w]<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[10004]  ={0};
        for(int i = 0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]>i+1) break;
            cnt++;
        }
        printf("%d\n",cnt);
    }
}
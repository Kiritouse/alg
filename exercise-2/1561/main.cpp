#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef __int64  i64d;
const int MAXSIZE = 1000000001;
int cando(i64d x,i64d n,i64d m,i64d a[],i64d b[]){
	i64d positions_need = 0;
	for(int i = 0;i<n;i++){
		i64d need_temp = x*a[i]/b[i];
		if(x*a[i]%b[i]!=0){
			need_temp++;
		}
		positions_need+=need_temp;
		if(positions_need>m) return 0;
	}
	return  positions_need<=m;
}
int main(int argc, char** argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		i64d n, m, ans;
		scanf("%I64d %I64d", &n, &m);
		i64d arr[1003] = {0};
		i64d brr[1003] = {0};
		memset(arr,0,sizeof(arr));
		memset(brr,0,sizeof(brr));
		for (int i = 0; i < n; i++) {
			scanf("%I64d", &arr[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%I64d", &brr[i]);
		}
		i64d low = 0,high = MAXSIZE-1,mid,maxans = 0;
		while(low<=high){
			mid = (low+high)/2;
			if(cando(mid,n,m,arr,brr)){
				maxans = mid;
				low = mid+1;
			}else{
				high = mid-1;
			}
		}
		printf("%I64d\n",maxans);

		
	}


}

#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		long long  a, b, m;
		cin>>a>>b>>m;
		bool marked[100007] = {0};
		marked[m] = false;
		marked[0] = true;
		long long  sn = 0;
		for(int i = 1;i<=m;i++){
			sn = (a * sn + b) % m;   //不开longlong见祖宗!!!!!!
			marked[sn] = true;
			if (sn == 0) {  //代表重复了
				break;
			}
		}
		for (int i = 0; i <= m; i++) {
			if (!marked[i]) {
				 printf("%d\n",i);
				break;
			}
		}
	}
}


/*
*/

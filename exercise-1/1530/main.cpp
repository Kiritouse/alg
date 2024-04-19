#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int countSubAndgetnum(const char * str, const char * sub,int * num) {
	int lenstr = strlen(str);
	int lensub = strlen(sub);
	int cnt  = 0;
	for(int i = 0;i<lenstr;i++){
		if(str[i] == ' ') continue;
		if(str[i] == 'P'){ //首次找到P
			cnt++;
			//移动到子串末尾
			i+=lensub;
		}
	}
	
	sscanf(str,"%d",num);
	return cnt;
}
int main() {
	char str[50] = {0};
	const char *who[2] = {"Alice","Bob"};
	const char *sub = "PAPER";
	int cntGame= 1;
	int aliceScore = 0;
	int bobScore = 0;
	int whoturn = 0;
	int ischange = 0;
	while(scanf("%[^\n]",str)!=EOF){  //正则表达式,匹配所有不是换行符的字符
		getchar();
		if(!ischange)
		printf("%s start game %d\n",who[whoturn],cntGame);
		int score = 0;
		int cntscore = (countSubAndgetnum(str,sub,&score))*5;
		if(score==cntscore){  //如果这一回合的喊的人(whoturn)赢了就输出赢了,下一回合还是他喊
			printf("%s win game %d\n",who[whoturn],cntGame);
			cntGame++;
			if(whoturn==0) aliceScore++;
			if(whoturn==1) bobScore++;
			ischange = 0;
			continue;//跳过这一回合
		}
		else{  //如果与喊的分数不同,那么就交换下一个
			whoturn ++;
			if(whoturn>=2) whoturn%=2;
			printf("Change to %s\n",who[whoturn]);
			ischange = 1;
			continue;
		}
	}
	printf("Game over %d:%d\n",aliceScore,bobScore);
	
}

#include <stdio.h>
#include <string.h>

bool isPalindrome(int len,char * str){
	int left = 0;
	int right = len+1;
	while(left<right){
		++left;
		--right;
		if(str[left]=='#'||str[right]=='#'){
			continue;
		}
		if(str[left]!=str[right]){
			return false;
		}
	}
	
	return true;
}
int main(){
	char str[1007] = {0};
	while(gets(str+1)){  //这里用scanf会缓冲区溢出,OutPut Limit Exceed,所以显示这个考虑下是不是溢出了
		char strtemp[1007] = {0};
		int len = strlen(str+1);
		int cnt = 0;
		for(int location = 1;location<=len+1;location++){
			int j = 1;
			strtemp[location] = '#';//等下判断回文的时候直接跳过就行
			for(int i = 1;i<=len;i++){ //枚举里面原本的每个字母
				if(j==location)j++; //第j个已经插入了
				strtemp[j++]=str[i];
			}
			if(isPalindrome(len+1,strtemp)){
				cnt++;
			}
			memset(strtemp,0,sizeof(strtemp));
		}
		memset(str,0,sizeof(str));
		printf("%d\n",cnt);
	}
}

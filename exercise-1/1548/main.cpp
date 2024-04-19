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
	while(gets(str+1)){  //������scanf�Ỻ�������,OutPut Limit Exceed,������ʾ����������ǲ��������
		char strtemp[1007] = {0};
		int len = strlen(str+1);
		int cnt = 0;
		for(int location = 1;location<=len+1;location++){
			int j = 1;
			strtemp[location] = '#';//�����жϻ��ĵ�ʱ��ֱ����������
			for(int i = 1;i<=len;i++){ //ö������ԭ����ÿ����ĸ
				if(j==location)j++; //��j���Ѿ�������
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

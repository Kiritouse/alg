#include <bits/stdc++.h>
using namespace std;
typedef struct block{
    int index;  //砖块的编号
    char str[5]; //每个砖块的实际位置
}Block;
bool checkConnect(char ch1,char ch2){
    //一个大写一个小写且是同一个字母 abs(ch1-ch2)=32
    if(abs(ch1-ch2)==32) return true;
    else return false;
}
void turn(char str[]){ //顺时针旋转某个字符串
    char temp[5] = {0};
    for(int i = 0;i<4;i++){
        int next = i+1;
        if(next>=4) next%=4;
        temp[next] = str[i];
    }
    strncpy(str,temp,4);

}
bool check(Block blocks[]){
    //如果以坐标为0,顺时针对每个编号进行计数
    //方块在编号为0的地方,看下标为2和3的突起
    //方块在编号为1的地方,看下标为0和3的突起
    //方块在编号为2的地方,看下标为0和1的突起
    //方块在编号为3的地方,看下标为1和2的突起

    //(0,2)<->(1,0);
    //(0,3)<->(3,1);
    
    //(1,0)<->(0,2);
    //(1,3)<->(2,1);

    //(2,1)<->(1,3)
    //(2,0)<->(3,2)

    //(3,1)<->(1,3)
    //(3,2)<->(2,0)
    int src0,src1,src2,src3;
    for(int i = 0;i<4;i++)
    { //遍历每个index,获取原始下标
        if(blocks[i].index==0) src0 = i;
        else if(blocks[i].index==1) src1 = i;
        else if(blocks[i].index==2) src2 = i;
        else if(blocks[i].index==3) src3 = i;
    }
    //遍历每个砖块的旋转
    for(int it0 = 0;it0<4;it0++) {  
                for(int it1 = 0;it1<4;it1++){
                    for(int it2 = 0;it2<4;it2++){
                        for(int it3 = 0;it3<4;it3++){
                            if(checkConnect(blocks[src0].str[2],blocks[src1].str[0])==false
                                ||checkConnect(blocks[src0].str[3],blocks[src3].str[1])==false
                                ||checkConnect(blocks[src2].str[1],blocks[src1].str[3])==false
                                ||checkConnect(blocks[src2].str[0],blocks[src3].str[2])==false){  
                                        //如果无法相连
                                        turn(blocks[src3].str);  //转动
                            }
                            else return true;
                        }
                        turn(blocks[src2].str);
                    }
                    turn(blocks[src1].str);
                }
                turn(blocks[src0].str);
    }
    return false;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
       Block blocks[4];
           scanf("%s",blocks[0].str);
           scanf("%s",blocks[1].str);
           scanf("%s",blocks[2].str);
           scanf("%s",blocks[3].str);
       
        int cnt = 0;
        
            for(int it0 = 0;it0<4;it0++){ 
                for(int it1 = 0;it1<4;it1++){
                    for(int it2 = 0;it2<4;it2++){
                        for(int it3 = 0;it3<4;it3++){
                            
                            if(it0!=it1&&it0!=it2&&it0!=it3
                                && it1!=it2&&it1!=it3
                                && it2!=it3
                                ){
                                  blocks[0].index = it0;  
                                  blocks[1].index =  it1;
                                  blocks[2].index = it2;
                                  blocks[3].index = it3;
                                    if(check(blocks)){
                                        printf("Yes\n");
                                        goto flag;
                                    }                             
                                }
                        }
                    }
                }
            }
            printf("No\n");
            flag: ;
    }
    return 0;
}
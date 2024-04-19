# 1531

> # 奇怪的数字[#](https://acm.xtu.edu.cn/exam/index.php/problem/exam_read/id/1531/exam_id/461#_1)
>
> ## 题目描述[#](https://acm.xtu.edu.cn/exam/index.php/problem/exam_read/id/1531/exam_id/461#_2)
>
> 我们想找这样的整数n，我们将n的数码中取出一个作为数x，其他的数码组合成另外一个数y，使得n=x×y。比如，整数126，我们取数码6，另外两个数码组成数21,126=6×21。
>
> ## 输入[#](https://acm.xtu.edu.cn/exam/index.php/problem/exam_read/id/1531/exam_id/461#_3)
>
> 没有输入
>
> ## 输出[#](https://acm.xtu.edu.cn/exam/index.php/problem/exam_read/id/1531/exam_id/461#_4)
>
> 按大小顺序依次输出这样的整数（数值不超过1000000）。

因为是找出所有,所以我们直接从小到大遍历

而如果是判断类可以按照题目正向思考

遍历x,然后遍历y,注意y>=10开始,然后组合成10*y+x,这样就包含了所有的数码了

计算*n*的数码是否和10⋅*y*+*x*的数码是否相同 即可 其中**10*y+x**这一步很巧妙

巧妙地利用了题意,只需要判断数码是否相同就行,与顺序无关

# 1542

> ## 题目描述[#](https://acm.xtu.edu.cn/exam/index.php/problem/exam_read/id/1542/exam_id/461#_2)
>
> 数列 S 是由生成式 sn=(a⋅sn−1+b)modm,s0=0 产生的，我们定义f(S)=min{x∉S∣x∈N}。
>
> 现在给你数列S的参数a,b,m,求f(S)。
>
> ## 输入[#](https://acm.xtu.edu.cn/exam/index.php/problem/exam_read/id/1542/exam_id/461#_3)
>
> 第一行是一个整数T(1≤T≤1000)，表示样例的个数。 第二行是三个整数a,b,m(0≤a,b≤105,1≤m≤105)。
>
> ## 输出[#](https://acm.xtu.edu.cn/exam/index.php/problem/exam_read/id/1542/exam_id/461#_4)
>
> 依次每行输出一个样例的结果。

注意下a*(sn-1)这里有可能爆int,所以不开long long的锅

注意分析时间复杂度,这里得要O(n)或者在O(nlogn)的复杂度

# 1549

>  题意 
>
> 求正整数集合内取两个不相同的元素，其和为2的幂次的方案数。*n*≤105，元素最大10^9

给一个整数集合,找到所有和为2的幂的整数
集合s<=10^5,猜测时间复杂度是O(n)或者O(nlogn),O(n)明显不可能
如果要用logn,则必然会出现一分为二的算法,猜测可以用二分查找,而又有两个变化的值,k和s里的元素,根据范围可以确定到k只需要到30即可,这样就不算在时间复杂度n里,因为是常数

> 发现用普通pow会超时,可能是因为效率不搞
>
> 用快速幂刚好过.
>
> ```c++
> ll fastpow(ll a, ll n) {
> 	ll sum = 1;
> 	while (n) {
> 		if (n & 1) {
> 			sum *= a;
> 		}
> 		a *= a;
> 		n >>= 1;
> 	}
> 	return sum;
> }
> ```
>
> 

# 1553,1559

倒是用到了sprintf和sscanf,这类输出到字符串,和在字符串中读取特定数据到某一变量中的函数,倒是挺好用的

# 1530 Game

用到了字符指针用来表示字符串,注意如果指向的字符串不会变的话一定要用const  char * str  = "测试字符串";

还有指针数组

const char* charr[size]  ={

"测试1",

"测试2",

}

这个也相当好用

之前想用strstr来匹配字符串,后来发现如果用这个只会发挥匹配子串的开始位置,这样会把其所有的都打印出来,不行

```cpp
while(scanf("%[^\n]",str)!=EOF){  //正则表达式,匹配所有不是换行符的字符
    
} //这个输入形式也非常好用,如果没给样例数,请一定要加上!=EOF
//按Ctrl+z+回车就可以结束这个循环
    
```

# 1538 打字机

> 这道题用String里的插入之类的要方便不少
>
> erase(pos,删除多少个)  //这里就是删除下标为pos的字符,并且将后面的往前面移动
>
> insert(pos,string类型的字符串) //这里一定要用string,不要用char类型,不然这样的话插入后就不能将原先的位置及其后面的字符全部向后移动
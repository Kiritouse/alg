# reverse()

> 翻转某个类里的元素
>
> void reverse(class.fist,class.last);
>
> - 回文串里用到了

![img](https://picx.zhimg.com/80/v2-7f20d57e51316a02ef64576609b89772_1440w.webp?source=2c26e567)

# string

## 求长度

```c++
string str;
str.length();
str.size();
```

## 输入

### c++

```cpp
string str;
geline(cin,str);// 读入一行字符串,包含空格,遇到回车结束

char str[100];
cin.getline(str,sizeof(str)); //输入字符数组

string str;
cin>>str; //读入一连串的字符,遇到空格或换行(回车结束)

string str;
scanf("%s",&str);//遇到空格结束,c++中最好别用
```

###  c

```cpp
getchar() //输入一个字符
gets();//读取一行字符串包括空格,似乎这个缓冲区非常大?,几乎不会爆缓冲区
scanf();//以空格为分割,遇到空格就结束
```

## 分割字符串

```cpp
str.sub(下标,截取长度)
```

## 查找指定子字符串出现的位置

```cpp
size_t pos = str.find("World");
```

## 替换字符串中的一部分

```cpp
str.replace(7, 5, "Universe"); // 替换从下标7开始的5个字符为"Universe"
```

## 在指定位置插入字符串

```cpp
str.insert(5, "Beautiful "); // 在下标5处插入字符串"Beautiful "
```

> 例如，如果你有一个字符串`str`，其内容为`"Hello, World!"`，然后你调用`str.insert(5, "Beautiful ")`，那么`str`的内容将变为`"HelloBeautiful , World!"`。注意原有的逗号和空格被移动到了`"Beautiful "`之后。

## 复制字符串

```cpp
string str3(str1) 
str3=str1;
strcpy(chararr1,chararr2);//复制2到1
```

## 排序sort

```cpp
sort(s.begin(),s.end());默认升序
sort(s.begin(),s.end(),greater<T>());//降序排序
```

## 添加字符

```cpp
s.push_back('a');
```

## c语言中

### 复制字符串

```cpp
strcpy(s1,s2);//复制s2到s1中
```

### 连接字符串

```cpp
strcat(s1,s2);
//连接字符串 s2 到字符串 s1 的末尾。
//连接字符串也可以用 + 号
```

### 返回字符串长度

```cpp
strlen(s1);  这里可以使用s1+1,这样从第一个下标开始算,遇到\0结束
```

### 查找字符串

```cpp
strchr(s1, ch);
strstr(s1,s2);
//返回一个指针,指向ch或者s2中第一次出现的位置
```


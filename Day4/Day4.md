# 编译器

## 一、预处理指令逻辑

### 1.1、`#ifdef` 和 `#ifndef`

- `#ifdef`  和 `#ifndef` 都需要有配套的 `#endif` 

- `#ifdef` 表示如果定义了这个宏，那么执行下面的内容
- `#ifndef` 表示如果没有定义这个宏，那么执行下面的内容



下面的例子展示了 `#ifndef` 的用法，如果没有定义这个宏，那么定义这个宏，再包含头文件，这样可以有效防止重复包含头文件。

```c++
// head1.h
#include <iostream>

// 包含 head2.h
#ifndef _HEAD2_
#define _HEAD2_
#include "head2.h"
#endif

// head2.h
#include <iostream>

// 包含 head1.h
#ifndef _HEAD1_
#define _HEAD1_
#include "head1.h"
#endif

// 主函数 
#include <iostream>
#include "head1.h"
#include "head2.h"

int main() {
    return ;
}

```



- 当 `#ifdef` 和 `#ifndef` 条件不满足时，可以执行 `#else` 的内容



上面代码可以等效转化为

```c++
// head1.h
#include <iostream>

// 包含 head2.h
#ifdef _HEAD2_
#else
#define _HEAD2_
#include "head2.h"
#endif

// head2.h
#include <iostream>

// 包含 head1.h
#ifdef _HEAD1_
#else
#define _HEAD1_
#include "head1.h"
#endif

// 主函数 
#include <iostream>
#include "head1.h"
#include "head2.h"

int main() {
    return ;
}
```





### 1.2、`if` ...`elif`...`else`

- `if` ...`elif`...`else` 与普通的 `if` 语句一样



例如，一个利用 `if` ...`elif`...`else` 来控制不同版本号的菜单界面

```c++
#include <iostream>
#define VERSION 10

#IF VERSION == 10
void Menu() {
    
}
#ELIF VERSION == 8
void Menu() {
    
}
#ELIF VERSION == 9
void Menu() {
    
}
#ELIF VERSION == 11
void Menu() {
    
}
#ELSE
void Menu() {
    
}
```



## 二、预定义宏

### 2.1、标准预定义宏

标准预定义宏即每个编译器都有的宏

| 宏           | 说明                                                         |
| ------------ | ------------------------------------------------------------ |
| \__DATE__    | 源文件的编译日期                                             |
| \__TIME__    | 当前转换单元的转换时间                                       |
| \__FILE__    | 所在源文件的名称                                             |
| \__LINE__    | 当前的行号                                                   |
| \__cplusplus | 当翻译单元为C++时，\__cplusplus定义为一个整数文本，否则为未定义 |



### 2.2、 MSVC 的预定义宏

MSVC预定义宏即Windows下的预定义宏，例如Visual Studio中就有

| 宏             | 说明                                                    |
| -------------- | ------------------------------------------------------- |
| _CHAR_UNSIGNED | 如果 char 类型为无符号，该宏定义为1，否则为未定义       |
| \__COUNTER__   | 从 0 开始，整个项目中，每次使用都会递增 1               |
| _DEBUG         | 如果是 Debug 模式，则定义为 1，Release 模式为未定义     |
| \__FUNCTION__  | 函数名称，不包含修饰                                    |
| \__FUNCDNAME__ | 函数名称，包含修饰名                                    |
| \__FUNCSIG__   | 包含了函数签名的函数名                                  |
| _WIN32         | 当编译为32位ARM，64位ARM，X68或X64定义为 1 否则为未定义 |
| _WIN64         | 当编译为64位ARM或x64定义为 1 否则未定义                 |
| \__TIMESTAMP__ | 最后一次源代码修改的时间和日期                          |



## 三、#define

### 3.1、直接定义常量

直接定义即无脑替换，例如

```c++
// 直接将代码中所有 MAX 替换为 10000
#define MAX 10000

// 甚至可以定义 int 为 double
#define int double
```

由于自由性太高，所以一般定义常量使用 `const int MAX = 10000`



### 3.2、定义复杂表达式宏

```c++
// 类似调用函数的用法，代码中的SUM(X,Y)替换为X+Y的结果
#define SUM(X,Y) X+Y

#define AVE(X,Y) (X+Y)/2

#define BIGGER(X,Y) ((X)>(Y)?(X):(Y))
```

 



\#可以将一个标识符参数字符串化

```c++
#define SHOW(X) std::cout << #X
// 如果调用 SHOW(X); 等同于std::cout << "X";
```



\##可以连接两个标识符

```c++
#define T1(X,Y) void X##Y() {std::cout << #Y}

// 可以在 函数定义处 T1(test, 1)，编译器自动替换为函数，相当于定义了函数名为test1的函数，内容为输出 1
// 在主函数中可以直接调用test1这个函数
```



### 3.3、取消宏定义

- \#undef 宏的名字
- 作用是取消这个宏的定义

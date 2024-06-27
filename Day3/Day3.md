## Day 3

### 1、函数模板和重载

#### 2.1、函数模板的弊端

有代码如下：

```c++
template<typename T>
T bigger(T a, T b) {
    return a > b ? a : b;
}

int main() {
    int num1 = 100, num2 = 200;
    int *a = &num1, *b = &num2;
    
    int num = *bigger(a, b);
}
```



该函数返回值为 `int` 类型，但是返回为地址大的，而不是值大的，换句话说，由于传进去的是地址，所以在函数中比较的是地址。



#### 2.2、函数模板的例外情况

为了避免这种情况，我们可以为模板函数写一种例外情况，即代码改为：

```c++
template<typename T>
T bigger(T a, T b) {
    return a > b ? a : b;
}

template<>
int* bigger(int* a, int* b) {
    return *a > *b ? a : b;
}
```



- 函数模板例外情况的定义，也要符合函数模板（即函数返回值，参数类型要和模板一致的情况下，T类型可以为任何类型）



#### 2.3、函数模板的重载

函数模板和普通函数一样，可以重载

```c++
template<typename T>
T bigger(T a, T b) {
	return a > b ? a : b;
}

template<typename T>
T bigger(T a, T b, T c) {
	return bigger(a, b) > bigger(b, c) ? bigger(a, b) : bigger(b, c);
}
```



#### 2.4、函数调用的优先级

当一个函数，同时有函数模板，函数模板的例外情况和同名的普通函数的情况下。

优先考虑普通函数，如果普通函数的参数列表和提供的参数对应不上，则考虑函数模板的例外情况，最后考虑函数模板。



### 2、auto->decltype

#### 2.1、auto

`auto` 可以声明一个变量，让编译器根据变量的值来推断变量的类型。



可以根据这个特性，声明变量与函数（不推荐，因为可读性差）



`auto` 的几个特性：

- `auto` 不能保留 `const` 属性

```c++
const int num1 = 0;
auto num2 = num1;
// 此时 num2 为 int 类型，而非 const int 类型
```



- `auto` 会优先推断为值类型，而非引用类型

```c++
int num1 = 5;
const int& lnum1 = num1;
auto num2 = lnum1;
// 此时 num2 为 int 类型,而非 int& 类型
```



- `auto` 利用函数返回值来推断类型时，函数会执行

```c++
auto x = min(1 , 2);
// 此时 min(1, 2) 函数会真的执行
```





#### 2.2、 decltype

`decltype`函数也可以得出一个表达式的类型，语法为：`decltype(表达式)` 



但是编译器处理 `decltype` 关键时有三原则：

- 如果`decltype` 内的表达式没有经过任何运算，那么得出数据类型同表达式内的数据类型，并且可以保留 `const` 和 引用类型。

```c++
int num1;
int* num2;
int& num3 = num1;
const int num4;

decltype(num1) num;		// 相当于 int num;
decltype(num2) num;		// 相当于 int* num;
decltype(num3) num;		// 相当于 int& num;
decltype(num4) num;		// 相当于 const int num;
```

- 如果 `decltype` 函数经历了运算，那么得出的数据类型是根据运算结果是否有固定的内存地址（左值）来决定的，如果有，则为该类型的引用类型，如果没有，则为该类型。

```c++
int num1 = 100, num2 = 200;
int* num3 = &num1;

// 有运算，运算结果没有地址
decltype(num1 + num2) num;	// 相当于 int num;

// *也是运算，运算结果有地址
decltype(*num3) num;		// 相当于 int& num;

// []也是运算，虽然num3[]越界，但是是运算，也有地址
decltype(num3[x]) num;		// 相当于 int& num;
```

- 如果 `decltype` 内的表达式是一个函数，那么得出的数据类型是根据函数的返回值来确定的。但是 `decltype` 不会真的执行表达式的计算。





#### 2.3、auto->decltype

##### 2.3.1、拖尾函数

有如下函数：

```c++
// 有如下函数
auto Bigger(int& num1, int& num2) {
    return num1 > num2 ? num1 : num2;
}

int main() {
    int num1 = 100, num2 = 666;
    Bigger(num1, num2) = 500;
}
```



由于 `auto` 优先推断为值类型，所以该函数会报错，因为返回值类型被强转为 `int` ，而返回值为一个右值，不能赋值，如果想让函数返回值为引用类型，可将函数改为：

```c++
auto Bigger(int& num1, int& num2)->decltype(num1 > num2 ? num1 : num2)
{
    return num1 > num2 ? num1 : num2;
}
```

由于 `decltype` 可以保留引用类型，而不会报错，这就是拖尾函数。



在 C++14 中，优化写法，上述函数可以写为：

```c++
decltype(auto) Bigger(int& num1, int& num2) {
    return num1 > num2 ? num1 : num2;
}
```


#include <iostream>
#define Swap(a, b) {int temp = (a); (a) = (b); (b) = temp;}
//加括号这样可以防止在宏定义中引用时发生错误。

/*
宏定义中的 "Swap" 宏展开后，实际上是将括号中的表达式替换为交换后的值。如果不使用括号将 "a" 和 "b" 括起来，可能会导致在宏定义中使用时出现问题。

例如，如果在 "Swap" 宏定义中使用 "Swap(x, y+1)"，则展开后会变为 "int temp = (x); (x) = (y+1); (y+1) = temp;"，这显然不是正确的交换语句。

因此，加上括号是为了确保变量被视为单个表达式，并在宏定义中正确地执行交换操作。
*/
using namespace std;

int dataa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//"dataa" 是一个全局变量，因此在 Perm 函数中可以直接访问和修改。
int num = 0;
//num用来记录总数
void Perm(int begin, int end) {
    if (begin == end) {
        for (int j = 0; j < end; j++) {//打印输出
            cout << dataa[j] << " ";
        }
        cout << endl;
        num++;
    }
    else {
        for (int i = begin; i < end; i++) {
            Swap(dataa[begin], dataa[i]);//交换
            Perm(begin + 1, end);//递归
            Swap(dataa[begin], dataa[i]);//恢复
        }
    }
}
/*

输出样式：
123456789
123456798
123456879
。。。。。。。。。。。。
*/
int main() {
    Perm(0, 9);
    cout << num << endl;
    return 0;
}

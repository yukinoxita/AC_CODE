//
// Created by zhengwei.
//

/*
标题：算式900


小明的作业本上有道思考题：

  看下面的算式：

  (□□□□-□□□□)*□□=900

  其中的小方块代表0~9的数字，这10个方块刚好包含了0~9中的所有数字。
  注意：0不能作为某个数字的首位。

小明经过几天的努力，终于做出了答案！如下：
(5012-4987)*36=900

用计算机搜索后，发现还有另外一个解，本题的任务就是：请你算出这另外的一个解。

注意：提交的格式需要与示例严格一致；
      括号及运算符号不要用中文输入法；
      整个算式中不能包含空格。

注意：机器评卷，不要填写任何多余的内容，比如说明文字。
*/
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        if (a[0] == 0 || a[4] == 0 || a[8] == 0)continue;
        int x1 = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
        int x2 = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];
        int x3 = a[8] * 10 + a[9];
        if ((x1 - x2) * x3 == 900) {
            printf("(%d%d%d%d-%d%d%d%d)*%d%d=900\n", 
                    a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
        }
    } while (next_permutation(a, a + 10));
    return 0;
}
//Point8总过不去的原因
//​​​​​这个题目如果总是有个测试点过不去就是因为A2类的交错求和的结果本身就是0，而你把0作为判断这一类数字不存在的条件是错误的。

#include <cstdio>

int main() {
    int n, j = 0, k = 0;                       //j用于交错求和，k用于平均值计算
    int a[1010] = {0};
    double count[10] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        switch (a[i] % 5) {
            case 0:
                if (a[i] % 2 == 0) {
                    count[1] += a[i];
                }
                break;
            case 1:
                j++;
                if (j % 2 == 1) {
                    count[2] += a[i];
                } else if (j % 2 == 0) {
                    count[2] -= a[i];
                }
                break;
            case 2:
                count[3]++;
                break;
            case 3:
                count[4] += a[i];
                k++;
                break;
            case 4:
                if (a[i] > count[5]) {
                    count[5] = a[i];
                }
                break;
            default:
                break;
        }
    }
    for (int i = 1; i <= 5; i++) {      //这里要注意A2交错求和的结果可能本身就是0，这样的话不能将0作为判断这类数字不存在的原因
        if (!count[i]) {                //不能光判a2，那样会误判，要加入对j的判别
            if (i == 2 && j != 0) {
                printf("%.0f", count[i]);
            } else {
                printf("N");
            }
            if (i != 5) {
                printf(" ");
            }
        } else {
            if (i != 4) {
                printf("%.0f", count[i]);
            } else {
                printf("%.1f", count[i] / k);
            }
            if (i != 5) {
                printf(" ");
            }
        }
    }
    return 0;
}




#include <cstdio>                 //example
int main() {
  int count[5] = {0};
  int ans[5] = {0};
  int n, temp;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);   //读入数字
    if(temp % 5 == 0) {   //A1类
      if(temp % 2 == 0) {
        ans[0] += temp;
        count[0]++;
      }
    }
    else if(temp % 5 == 1) {    //A2类
      if(count[1] % 2 == 0) {
        ans[1] += temp;
      }
      else {
        ans[1] -= temp;
      }
      count[1]++;
    }
    else if(temp % 5 == 2) {    //A3类
      count[2]++;
    }
    else if(temp % 5 == 3) {    //A4类
      ans[3] += temp;
      count[3]++;
    }
    else {      //A5类
      if(temp > ans[4]) {
        ans[4] = temp;
      }
      count[4]++;
    }
  }
  if(count[0] == 0)
    printf("N ");
  else
    printf("%d ", ans[0]);
  if(count[1] == 0)
    printf("N ");
  else
    printf("%d ", ans[1]);
  if(count[2] == 0)
    printf("N ");
  else
    printf("%d ", count[2]);
  if(count[3] == 0)
    printf("N ");
  else
    printf("%.1f ", (double)ans[3] / count[3]);
  if(count[4] == 0)
    printf("N");      //最后一个的输出不能有空格
  else
    printf("%d", ans[4]);
  return 0;
}





/*                              //失败作,只有一个用例正确，其他全错,有待修改
#include <cstdio>               //改为用两个数组，一个记答案ans[]，一个记个数count[]，每读入一个数字，就根据不同条件开始分类，不需要全读完再分类
                                //我可能错在最后的判断上了。应该记个数的。这个例子写的就很好了，照着它改就行。
int main() {
  int n, a[1100], a1 = 0, a2 = 0, a3 = 0, a5 = 0, max = 0, count = 0;
  double a4 = 0.0;
  n = getchar();
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; i++) {
    if(a[i] % 10 == 0) {
      a1 += a[i];
    }
    if(a[i] % 5 == 1) {
      if(i % 2 == 0) {
        a2 += a[i];
      }
      else if(i % 2 == 1) {
        a2 -= a[i];
      }
    }
    if(a[i] % 5 == 2) {
      a3++;
    }
    if(a[i] % 5 == 3) {
      a4 += a[i];
      count++;
    }
    if(a[i] % 5 == 4) {
      if(a[i] > max)
        max = a[i];
    }
  }
  if(a1 == 0) {
    printf("N ");
  }
  else {
    printf("%d ", a1);
  }
  if(a2 == 0) {
    printf("N ");
  }
  else {
    printf("%d ", a2);
  }
  if(a3 == 0) {
    printf("N ");
  }
  else {
    printf("%d ", a3);
  }
  if(a4 == 0.0) {
    printf("N ");
  }
  else {
    printf("%.1f ", a4 / count);
  }
  if(a5 == 0) {
    printf("N");
  }
  else {
    printf("%d", a5);
  }
  return 0;
}
*/

//建议对树用静态写法(用数组下标来代替所谓的地址)
//因为用指针的话，结点定义比较麻烦，要令指针域存放其所有子结点的地址
struct node {
  typename data;  //数据域
  vector child;   //指针域，存放所有子结点的下标
} Node[maxn];   //结点数组，maxn为结点上限个数

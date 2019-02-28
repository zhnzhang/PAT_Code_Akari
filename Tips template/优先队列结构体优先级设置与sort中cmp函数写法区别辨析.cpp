//首先提一下优先队列内元素优先级设置中的基本数据类型的优先级设置
//举例：priority_queue<int, vector<int>, less<int> > q;
//上面语句的第二个参数，填写的是来承载底层数据结构堆(heap)的容器，如果第一个参数是double型或char型，则此处只需要填写vector<double>或vector<char>;
//而第三个参数less<int>则是对第一个参数的比较类，less<int>表示数字大的优先级越大，而greater<int>表示数字小的优先级越大
//我没去仔细查具体为什么这么标识，在这里说下我的个人理解：
//less<int> 就是顺着优先级越来越小，表示数字大的优先级越大
//great<int> 就是顺着优先级越来越大，表示数字小的优先级越大
//对基本数据类型，也适用下面要讲的结构体的优先级设置方法，只不过第三个参数的写法不太一样了。

//结构体的优先级设置：
//若希望按数字大的为优先级高，就需要重载(overload)小于号"<"。重载是指对已有的运算符进行重新定义，也就是说，可以改变小于号的功能(例如把它重载为大于号的功能)
struct fruit {
  string name;
  int price;
  friend bool operator < (fruit f1, fruit f2) {
    return f1.price < f2.price;
  }
};
//fruit结构体中增加了一个函数，其中"friend"为友元，后面的"bool operator < (fruit f1, fruit f2)"对fruit类型的操作符"<"进行了重载
//重载大于号会编译错误，因为从数学上来说只需要重载小于号，即f1 > f2等价于判断f2 < f1,而f1 == f2则等价于判断!(f1 < f2) ** !(f2 < f1)
//函数内部的"return f1.price < f2.price"，因此重载后小于号还是小于号的作用。此时直接定义fruit类型的优先队列，其内部就是以价格高的水果为优先级高。
//同理，如果想要以价格低的水果为优先级高，那么只需要把return中的小于号改为大于号即可
struct fruit {
  string name;
  int price;
  friend bool operator < (fruit f1, fruit f2) {
    return f1.price > f2.price;
  }
};
//对上述部分，我希望能类比记忆。
//"<"类比less，就是顺着优先级越来越小，表示数字大的优先级越大
//">"类比greater，就是顺着优先级越来越大，表示数字小的优先级越大


//我们会发现，上面对小于号的重载与排序函数sort中的cmp函数有些相似，它们的参数都是两个变量，函数内部都是return了true或者false
//事实上，这两者的作用确实是类似的，只不过从效果看上去，似乎是“相反”的
//在排序中，如果是"return f1.price > f2.price"，那么则是按价格从高到低排序
//但是在优先队列中却是把价格低的放到队首。
//原因在于优先队列本身默认的规则就是优先级高的放在队首，因此把小于号重载为大于号的功能时，只是把这个规则反向了一下

//记住，优先队列设置结构体优先级里的这个函数与sort中的cmp函数的效果，是，相反，的。

//将优先队列设置结构体优先级的这个函数写在结构体外面的写法如下：
//先把friend去掉，把小于号改成一对小括号，然后把重载的函数写在结构体外面，同时将其用struct包装起来：
struct cmp {
  bool operator () (fruit f1, fruit f2) {
    return f1.price > f2.price;
  }
};
//在这种情况下，需要用之前讲解的给基础数据类型用的那套定义方式来定义优先队列
priority_queue<fruit, vector<fruit>, cmp> q;
//可以看到，此处只是把greater<>部分换成了cmp

//在前面也说过，这样的在外面的写法，同样适用于基本数据类型或者其他STL容器(例如set)，它们也可以通过同样的方式来定义优先级


//最后，如果结构体内的数据较为庞大(例如出现了字符串或者数组)，建议使用引用来提高效率，此时比较类的参数中需要加上"const"和"&"，如下所示：
friend bool operator < (const fruit &f1, const fruit &f2) {
  return f1.price > f2.price;
}

bool operator () (const fruit &f1, const fruit &f2) {
  return f1.price > f2.price;
}

//priority_queue可以解决一些贪心问题，也可以对Dijkstra算法进行优化(因为优先队列的本质是堆)
//需要注意，使用top()函数前，必须用empty()判断优先队列是否为空，否则可能因为队空而出现错误。
//对其他的STL队列容器也有类似的要求。

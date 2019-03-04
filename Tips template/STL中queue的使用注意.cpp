//当使用STL的queue时，元素入队的push操作只是制造了该元素的一个副本入队，因此在入队后对原元素的修改不会影响队列中的副本，而对队列中副本的修改也不会改变原元素，需要注意由此可能引入的bug(一般由结构体产生)，例如下面的这个例子：
#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int data;
} a[10];
int main() {
    queue<node> q;
    for(int i = 1; i <= 3; i++) {
        a[i].data = i;
        q.push(a[i]);
    }
    //尝试直接把队首元素(即a[1])的数据域改为100
    q.front().data = 100;
    //事实上对队列元素的修改无法改变原元素
    printf("%d %d %d\n", a[1].data, a[2].data, a[3].data);
    //然后尝试直接修改a[1]的数据域为200(即a[1],上面已经修改队首元素为100)
    a[1].data = 200;
    //事实上对原元素的修改也无法改变队列中的元素
    printf("%d\n", q.front().data);
    return 0;
}

//输出结果：
//1 2 3
//100

//这就是说，当需要对队列中的元素进行修改而不仅仅是访问时，队列中存放的元素最好不要是元素本身，而是它们的编号(如果是数据的话则是下标)。例如把上面的程序改成如下这样：
#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int data;
} a[10];

int main() {
    queue<int> q;       //q存放结构体数组中元素的下标
    for(int i = 1; i <= 3; i++) {
        a[i].data = i;
        q.push[i];  //这里是将数据下标i入队，而不是结点a[i]本身
    }
    a[q.front()].data = 100;    //q.front()为下标，通过a[q.front()]即可修改原元素
    printf("%d\n", a[1].data);
    return 0;
}
//输出结果：
//100

//这个小技巧可以避免很多由使用queue不当导致的错误，因此读者需要仔细体会这种写法和前面那种写法的区别，就可以在写BFS时避免一些错误的发生

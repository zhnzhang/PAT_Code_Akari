//在常用STL容器中，只有在vector和string中，才允许使用vi.begin() + 3这种迭代器加上整数的写法
//vector的迭代器不支持it < vi.end()写法，因此循环条件只能用it != vi.end()
//set的迭代器不支持it < st.end()写法，因此循环条件只能用it != st.end()


//在STL标准容器中，只有vector、string、deque是可以使用sort的。这是因为像set、map这种容器都是用红黑树实现的，元素本身有序，故不允许使用sort排序


for(set<int>::iterator it = st.begin(); it != st.end(); it++) {     //遍历set
    if(it != st.begin()) {  //要掌握这种针对STL容器输出的空格格式控制方法
        printf(" ");        //不在第一个数前输出空格
    }
    printf("%d", *it);  //从小到大输出朋友证号
}


//通过map直接建立int至int的映射，相比开int数组的优势在于：以免数据范围过大，可能导致的内存超限。


//字符串以及map的参数传递速度较慢，如果需要作为函数的参数的话需要尽可能加上引用


//在scanf或者cin输入书的编号id后，必须用getchar接收掉id后面的换行，否则getline将会换行读入
//(这里要注意，也就是scanf(接收完字符后面是换行的话)后面接getline的话，中间要加个getchar()收集换行，这是由scanf与getline的特性来决定的)


//STL中，对queue，使用front()和pop()函数前，必须用empty()判断队列是否为空，否则可能因为队空而出现错误


//STL中，以vector为例，需要注意，如果typename也是一个STL容器，定义的时候要记得在>>符号之间加上空格，因为一些使用C++11之前标准的编译器会把它视为移位操作，导致编译错误
//示例：vector<vector<int> > name;     // >>之间要加空格。这句本身其实是定义了一个二维vector数组


//由于map的内部实现中涉及pair，因此添加map头文件时会自动添加utility头文件，此时如果需要使用pair，就不需要额外再去添加utility头文件了
//pair可以用来代替二元结构体及其构造函数，可以节省编码时间
//pair还能作为map的键值对来进行插入，举例如下：
map<string, int> mp;
//如下也给出了如何临时构建pair的两种方法
mp.insert(make_pair("heihei", 5));
mp.insert(pair<string, int>("haha", 10));


//比较函数cmp是来告诉sort函数何时进行元素交换的

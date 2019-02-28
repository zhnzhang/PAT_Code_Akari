//在常用STL容器中，只有在vector和string中，才允许使用vi.begin() + 3这种迭代器加上整数的写法
//vector的迭代器不支持it < vi.end()写法，因此循环条件只能用it != vi.end()
//set的迭代器不支持it < st.end()写法，因此循环条件只能用it != st.end()


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

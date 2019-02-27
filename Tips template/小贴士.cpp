//在常用STL容器中，只有在vector和string中，才允许使用vi.begin() + 3这种迭代器加上整数的写法
//vector的迭代器不支持it < vi.end()写法，因此循环条件只能用it != vi.end()
//set的迭代器不支持it < st.end()写法，因此循环条件只能用it != st.end()
for(set<int>::iterator it = st.begin(); it != st.end(); it++) {     //遍历set
    if(it != st.begin()) {  //要掌握这种针对STL容器输出的空格格式控制方法
        printf(" ");        //不在第一个数前输出空格
    }
    printf("%d", *it);  //从小到大输出朋友证号
}

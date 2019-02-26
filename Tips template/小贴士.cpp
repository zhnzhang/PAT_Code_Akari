//在常用STL容器中，只有在vector和string中，才允许使用vi.begin() + 3这种迭代器加上整数的写法
//vector的迭代器不支持it < vi.end()写法，因此循环条件只能用it != vi.end()
//set的迭代器不支持it < st.end()写法，因此循环条件只能用it != st.end()

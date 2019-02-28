//由于map的内部实现中涉及pair，因此添加map头文件时会自动添加utility头文件，此时如果需要使用pair，就不需要额外再去添加utility头文件了
//pair可以用来代替二元结构体及其构造函数，可以节省编码时间
//pair还能作为map的键值对来进行插入，举例如下：
map<string, int> mp;
//如下也给出了如何临时构建pair的两种方法
mp.insert(make_pair("heihei", 5));
mp.insert(pair<string, int>("haha", 10));

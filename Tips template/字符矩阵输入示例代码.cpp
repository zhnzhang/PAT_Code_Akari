scanf("%d%d", &n, &m);
for(int i = 0; i < n; i++) {
    getchar();      //过滤掉每行后面的换行符(自行模拟逻辑)
    for(int j = 0; j < m; j++) {
        matrix[i][j] = getchar();
    }
    matrix[i][m + 1] = '\0';        //手动加上字符数组的结尾符
}

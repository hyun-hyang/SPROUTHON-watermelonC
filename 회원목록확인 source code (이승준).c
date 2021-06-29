void list(struct student* info)
{
    int i, j;
    printf("전체 회원정보를 조회하시겠습니까? 1.Yes 2. No\n");
    scanf("%d", &i);
    
    FILE* fp;
    fp = fopen("exampleFile.txt", "r");
    char tmp;
    int cnt = 0;
    if (fp == NULL) {
        exit(0);
    }
    if (i == 1)
    {
        while (fscanf(fp, "%c", &tmp) != EOF)
        {
            printf("%c", tmp);
            if (tmp == '\n')
                cnt++;
        }
        printf("회원 수는 %d명입니다.\n", cnt);
        printf("\n");
    }
    else
        exit(0);
}

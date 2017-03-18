#include<stdio.h>
#include<conio.h>

void main()
{
    FILE *fp;
    int sn=1, rn, s1, s2, s3, i, num;
    char fName[10], stu[12], empty;
    printf("Enter the name of the file: ");
    scanf("%s", fName);
    fp = fopen(fName, "a+");

    printf("Enter the number of students: ");
    scanf("%d", &num);
    if((empty = getc(fp)) == NULL)
    {
        fprintf(fp, "S.No.   Roll No      Student Name   Sub1   Sub2   Sub3\n");
        sn=1;
    }
    else
    {
        fseek(fp, -54L, 2);
        empty = getc(fp);
        sn = (int*)empty;
        sn = sn - 47;
        fseek(fp, 0L, 2);
    }
    fprintf(stdout, "S.No.  Roll No      Student Name   Sub1   Sub2   Sub3\n");

    for(i=1; i<=num; i++)
    {
        printf("%d ", sn);
        fscanf(stdin, "%d %s %d %d %d", &rn, stu, &s1, &s2, &s3);
        fprintf(fp, "\n%-5d   %-10d   %-12s   %-4d   %-4d   %-4d", sn, rn, stu, s1, s2, s3);
        sn++;
    }
    fclose(fp);
    
    //ok
}

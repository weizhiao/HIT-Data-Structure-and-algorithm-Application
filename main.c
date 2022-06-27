#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"list.h"
#include"file.h"
#include"institute.h"
#include"project.h"

int score1[3] = { 5,3,2 };
int score2[5] = { 7,5,3,2,1 };

void ShowMenu(const int maxboy, const int maxinstitute);
int Inputchoice(const int maxboy, const int maxinstitute);
void InputScore(INSTITUTE a, PROJECT p, const int maxboy, const int countinstitute, const int countboy, const int countgirl);
int IsMake(const int max);
void SeekProject(INSTITUTE a, PROJECT p, const int countboy, const int countgirl, const int maxboy);
void SeekInstitute(INSTITUTE a, PROJECT p, const int countinstitute, const int countboy);

int main()
{
    int array[6] = { -1,-1,-1,0,0,0 };
    INSTITUTE a;
    PROJECT Project;
    FILE* fp = Open();
    ReadArrayfromFile(array, fp);
    int maxboy = array[0];
    int maxgirl = array[1];
    int maxinstitute = array[2];
    int countboy = array[3];
    int countgirl = array[4];
    int countinstitute = array[5];
    if (maxboy != -1)
    {
        Project = malloc((maxboy + maxgirl) * sizeof(struct project));
        ReadProjectfromFile(maxboy + maxgirl, Project, fp);
    }
    if (maxinstitute != -1)
    {
        a = malloc(maxinstitute * sizeof(struct institute));
        ReadInstitutefromFile(maxinstitute, a, fp);
    }
    RecoverList(a, Project, countboy, countgirl, maxboy);
    while (1)
    {
        int ch;
        ShowMenu(maxboy, maxinstitute);
        ch = Inputchoice(maxboy, maxinstitute);
        switch (ch)
        {
        case 0:
            array[0] = maxboy;
            array[1] = maxgirl;
            array[2] = maxinstitute;
            array[3] = countboy;
            array[4] = countgirl;
            array[5] = countinstitute;
            WritetoFile(Project, a, array);
            return 0;
        case 1:
        {
            int flag = IsMake(maxinstitute);
            if (flag == 1)
            {
                free(a);
                a = MakeInstitute(&maxinstitute, &countinstitute);
            }
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            int flag = IsMake(maxboy);
            if (flag == 1)
            {
                free(Project);
                Project = MakeProject(&maxboy, &maxgirl, &countboy, &countgirl);
            }
            system("pause");
            system("cls");
            break;
        }
        case 3:
            AppendProject(Project, &countboy, &countgirl, maxboy, maxgirl);
            system("pause");
            system("cls");
            break;
        case 4:
            SeekProject(a, Project, countboy, countgirl, maxboy);
            system("pause");
            system("cls");
            break;
        case 5:
            ShowProject(Project, countboy, countgirl, maxboy);
            system("pause");
            system("cls");
            break;
        case 6:
            AppendInstitute(a, &countinstitute, maxinstitute);
            system("pause");
            system("cls");
            break;
        case 7:
            SeekInstitute(a, Project, countinstitute, countboy);
            system("pause");
            system("cls");
            break;
        case 8:
            ShowAllInstituteSum(a, countinstitute);
            system("pause");
            system("cls");
            break;
        case 9:
            ShowSortInstitute(a, countinstitute);
            system("pause");
            system("cls");
            break;
        case 10:
            InputScore(a, Project, maxboy, countinstitute, countboy, countgirl);
            system("pause");
            system("cls");
            break;
        }
    }
}

void ShowMenu(const int maxboy, const int maxinstitute)
{
    printf("###########################\n");
    printf("##    初始化学院请按1    ##\n");
    printf("##    初始化项目请按2    ##\n");
    if (maxboy != -1)
    {
        printf("##     添加项目请按3     ##\n");
        printf("##   查询项目成绩请按4   ##\n");
        printf("##  显示项目名称及编号5  ##\n");
    }
    if (maxinstitute != -1)
    {
        printf("##     添加学院请按6     ##\n");
        printf("##   查询学院信息请按7   ##\n");
        printf("##  显示所有学院的总分8  ##\n");
        printf("## 排序并显示学院的信息9 ##\n");
    }
    if (maxinstitute != -1 && maxboy != -1)
    {
        printf("##     输入项目成绩10    ##\n");
    }
    printf("##     退出系统请按0     ##\n");
    printf("###########################\n");
}

int Inputchoice(const int maxboy, const int maxinstitute)
{
    int ch;
    while (scanf("%d", &ch) != 1)
    {
    BACK:
        printf("输入错误，请重新输入！\n");
        fflush(stdin);
    }
    if (maxboy == -1)
    {
        if (ch == 3 || ch == 4 || ch == 10 || ch == 5)
        {
            goto BACK;
        }
    }
    if (maxinstitute == -1)
    {
        if (ch == 9 || ch == 6 || ch == 7 || ch == 8 || ch == 10)
        {
            goto BACK;
        }
    }
    return ch;
}

int IsMake(const int max)
{
    if (max == -1)
    {
        return 1;
    }
    else
    {
        printf("该项已初始化，是否仍要初始化？(y or n)\n");
        char ch;
        fflush(stdin);
        while (scanf("%c", &ch) != 1 || (ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n'))
        {
            printf("请按照提示输入！\n");
            fflush(stdin);
        }
        if (ch == 'N' || ch == 'n')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

void InputScore(INSTITUTE a, PROJECT p, const int maxboy, const int countinstitute, const int countboy, const int countgirl)
{
    int n;
    int count;
    int sex;
    printf("请输入想添加成绩的项目编号:\n");
    while (scanf("%d", &n) != 1 || n <= 0 || n > (countboy + countgirl))
    {
        if (n <= 0 || n > (countboy + countgirl))
        {
            printf("超出当前项目的最大编号，请重新输入！\n");
        }
        else
        {
            printf("输入错误，请重新输入！\n");
        }
        fflush(stdin);
    }
    if (n > countboy)
    {
        count = n + maxboy - countboy - 1;
        sex = 2;
    }
    else
    {
        count = n - 1;
        sex = 1;
    }
    if (p[count].isinput == 1)
    {
        printf("该项目已有成绩，是否仍要输入？(y or n)\n");
        char ch;
        fflush(stdin);
        while (scanf("%c", &ch) != 1 || (ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n'))
        {
            printf("请按照提示输入！\n");
            fflush(stdin);
        }
        if (ch == 'N' || ch == 'n')
        {
            goto END;
        }
    }
    if (sex == 1)
    {
        printf("(男生)");
    }
    else
    {
        printf("(女生)");
    }
    printf("项目名称为：%s\n", p[count].name);
    printf("取前三名成绩请输入1，取前五名成绩请输入2：\n");
    int b;
    int* score;
    while (scanf("%d", &b) != 1 || (b != 1 && b != 2))
    {
        printf("输入错误，请重新输入！\n");
        fflush(stdin);
    }
    if (b == 1)
    {
        p[count].count = 3;
        score = score1;
    }
    else
    {
        p[count].count = 5;
        score = score2;
    }
    printf("请输入前%d名的学院编号(可输入-1中止输入)：\n", p[count].count);
    for (int i = 0; i < p[count].count; i++)
    {
        int x;
    BACK:
        printf("请输入第%d名的学院编号：\n", i + 1);
        while (scanf("%d", &x) != 1 || x > countinstitute || x < 0)
        {
            if (x > countinstitute)
            {
                printf("超过当前学院的最大编号，请重新输入或添加学院！\n");
            }
            else if (x == -1)
            {
                goto END;
            }
            else
            {
                printf("输入错误，请重新输入！\n");
            }
        }
        for (int j = 0; j < i; j++)
        {
            if (p[count].Institute[j] == x - 1)
            {
                printf("请勿重复输入！\n");
                goto BACK;
            }
        }
        p[count].Institute[i] = x - 1;
        printf("第%d名为:%s\n", i + 1, a[x - 1].name);
        AppendLast(a[x - 1].L, count);
        if (sex == 1)
        {
            a[x - 1].BoySum += score[i];
        }
        else
        {
            a[x - 1].GirlSum += score[i];
        }
        if (i == p[count].count - 1)
        {
            p[count].isinput = 1;
        }
    }
    if (p[count].isinput == 1)
    {
        printf("添加成功！\n");
    }
    else
    {
    END:
        printf("输入已中止！\n");
    }
}

void SeekProject(INSTITUTE a, PROJECT p, const int countboy, const int countgirl, const int maxboy)
{
    if (countboy == 0 && countgirl == 0)
    {
        printf("暂无已创建的项目\n");
    }
    else
    {
        printf("请输入您想查看信息的项目编号：\n");
        int n;
        int count;
        while (scanf("%d", &n) != 1 || n <= 0 || n > (countboy + countgirl))
        {
            if (n > (countboy + countgirl))
            {
                printf("超过当前最大的项目编号，请重新输入：\n");
            }
            else
            {
                printf("输入数据形式有误，请重新输入：\n");
            }
            fflush(stdin);
        }
        if (p[n - 1].isinput == 0)
        {
            printf("该项目的成绩还未输入\n");
        }
        else
        {
            if (n <= countboy)
            {
                count = n - 1;
            }
            else
            {
                count = n - countboy - 1 + maxboy;
            }
            printf("项目名称为：%s\n", p[count].name);
            printf("取得前%d名的学院分别为：\n", p[count].count);
            for (int i = 0; i < p[count].count; i++)
            {
                printf("第%d名：%s\n", i + 1, a[p[count].Institute[i]].name);
            }
        }
    }
}

void SeekInstitute(INSTITUTE a, PROJECT p, const int countinstitute, const int countboy)
{
    if (countinstitute == 0)
    {
        printf("暂无已创建的学院\n");
    }
    else
    {
        printf("请输入您想要查看学院的编号：\n");
        int n;
        while (scanf("%d", &n) != 1 || n <= 0 || n > countinstitute)
        {
            if (n > countinstitute)
            {
                printf("超过当前最大的项目编号，请重新输入：\n");
            }
            else
            {
                printf("输入数据形式有误，请重新输入：\n");
            }
            fflush(stdin);
        }
        ShowInstitute(a[n - 1]);
        if (a[n - 1].L->next == NULL)
        {
            printf("该学院无获奖项目\n");
        }
        else
        {
            printf("学院获奖项目有：\n");
            LIST position = a[n - 1].L;
            while (position->next != NULL)
            {
                int i = 1;
                printf("%d  ", i);
                if (position->next->data >= countboy)
                {
                    printf("(女生)");
                }
                else
                {
                    printf("(男生)");
                }
                printf("%s获得第%d名\n", p[position->next->data].name, Rank(p[position->next->data], n - 1));
                position = Next(position);
                i++;
            }
        }
    }
}


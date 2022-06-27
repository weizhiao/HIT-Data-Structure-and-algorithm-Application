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
    printf("##    ��ʼ��ѧԺ�밴1    ##\n");
    printf("##    ��ʼ����Ŀ�밴2    ##\n");
    if (maxboy != -1)
    {
        printf("##     �����Ŀ�밴3     ##\n");
        printf("##   ��ѯ��Ŀ�ɼ��밴4   ##\n");
        printf("##  ��ʾ��Ŀ���Ƽ����5  ##\n");
    }
    if (maxinstitute != -1)
    {
        printf("##     ���ѧԺ�밴6     ##\n");
        printf("##   ��ѯѧԺ��Ϣ�밴7   ##\n");
        printf("##  ��ʾ����ѧԺ���ܷ�8  ##\n");
        printf("## ������ʾѧԺ����Ϣ9 ##\n");
    }
    if (maxinstitute != -1 && maxboy != -1)
    {
        printf("##     ������Ŀ�ɼ�10    ##\n");
    }
    printf("##     �˳�ϵͳ�밴0     ##\n");
    printf("###########################\n");
}

int Inputchoice(const int maxboy, const int maxinstitute)
{
    int ch;
    while (scanf("%d", &ch) != 1)
    {
    BACK:
        printf("����������������룡\n");
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
        printf("�����ѳ�ʼ�����Ƿ���Ҫ��ʼ����(y or n)\n");
        char ch;
        fflush(stdin);
        while (scanf("%c", &ch) != 1 || (ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n'))
        {
            printf("�밴����ʾ���룡\n");
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
    printf("����������ӳɼ�����Ŀ���:\n");
    while (scanf("%d", &n) != 1 || n <= 0 || n > (countboy + countgirl))
    {
        if (n <= 0 || n > (countboy + countgirl))
        {
            printf("������ǰ��Ŀ������ţ����������룡\n");
        }
        else
        {
            printf("����������������룡\n");
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
        printf("����Ŀ���гɼ����Ƿ���Ҫ���룿(y or n)\n");
        char ch;
        fflush(stdin);
        while (scanf("%c", &ch) != 1 || (ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n'))
        {
            printf("�밴����ʾ���룡\n");
            fflush(stdin);
        }
        if (ch == 'N' || ch == 'n')
        {
            goto END;
        }
    }
    if (sex == 1)
    {
        printf("(����)");
    }
    else
    {
        printf("(Ů��)");
    }
    printf("��Ŀ����Ϊ��%s\n", p[count].name);
    printf("ȡǰ�����ɼ�������1��ȡǰ�����ɼ�������2��\n");
    int b;
    int* score;
    while (scanf("%d", &b) != 1 || (b != 1 && b != 2))
    {
        printf("����������������룡\n");
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
    printf("������ǰ%d����ѧԺ���(������-1��ֹ����)��\n", p[count].count);
    for (int i = 0; i < p[count].count; i++)
    {
        int x;
    BACK:
        printf("�������%d����ѧԺ��ţ�\n", i + 1);
        while (scanf("%d", &x) != 1 || x > countinstitute || x < 0)
        {
            if (x > countinstitute)
            {
                printf("������ǰѧԺ������ţ���������������ѧԺ��\n");
            }
            else if (x == -1)
            {
                goto END;
            }
            else
            {
                printf("����������������룡\n");
            }
        }
        for (int j = 0; j < i; j++)
        {
            if (p[count].Institute[j] == x - 1)
            {
                printf("�����ظ����룡\n");
                goto BACK;
            }
        }
        p[count].Institute[i] = x - 1;
        printf("��%d��Ϊ:%s\n", i + 1, a[x - 1].name);
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
        printf("��ӳɹ���\n");
    }
    else
    {
    END:
        printf("��������ֹ��\n");
    }
}

void SeekProject(INSTITUTE a, PROJECT p, const int countboy, const int countgirl, const int maxboy)
{
    if (countboy == 0 && countgirl == 0)
    {
        printf("�����Ѵ�������Ŀ\n");
    }
    else
    {
        printf("����������鿴��Ϣ����Ŀ��ţ�\n");
        int n;
        int count;
        while (scanf("%d", &n) != 1 || n <= 0 || n > (countboy + countgirl))
        {
            if (n > (countboy + countgirl))
            {
                printf("������ǰ������Ŀ��ţ����������룺\n");
            }
            else
            {
                printf("����������ʽ�������������룺\n");
            }
            fflush(stdin);
        }
        if (p[n - 1].isinput == 0)
        {
            printf("����Ŀ�ĳɼ���δ����\n");
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
            printf("��Ŀ����Ϊ��%s\n", p[count].name);
            printf("ȡ��ǰ%d����ѧԺ�ֱ�Ϊ��\n", p[count].count);
            for (int i = 0; i < p[count].count; i++)
            {
                printf("��%d����%s\n", i + 1, a[p[count].Institute[i]].name);
            }
        }
    }
}

void SeekInstitute(INSTITUTE a, PROJECT p, const int countinstitute, const int countboy)
{
    if (countinstitute == 0)
    {
        printf("�����Ѵ�����ѧԺ\n");
    }
    else
    {
        printf("����������Ҫ�鿴ѧԺ�ı�ţ�\n");
        int n;
        while (scanf("%d", &n) != 1 || n <= 0 || n > countinstitute)
        {
            if (n > countinstitute)
            {
                printf("������ǰ������Ŀ��ţ����������룺\n");
            }
            else
            {
                printf("����������ʽ�������������룺\n");
            }
            fflush(stdin);
        }
        ShowInstitute(a[n - 1]);
        if (a[n - 1].L->next == NULL)
        {
            printf("��ѧԺ�޻���Ŀ\n");
        }
        else
        {
            printf("ѧԺ����Ŀ�У�\n");
            LIST position = a[n - 1].L;
            while (position->next != NULL)
            {
                int i = 1;
                printf("%d  ", i);
                if (position->next->data >= countboy)
                {
                    printf("(Ů��)");
                }
                else
                {
                    printf("(����)");
                }
                printf("%s��õ�%d��\n", p[position->next->data].name, Rank(p[position->next->data], n - 1));
                position = Next(position);
                i++;
            }
        }
    }
}


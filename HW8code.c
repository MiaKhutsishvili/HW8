// Kimia Khudsiani 40223030

#include <stdio.h>

typedef struct 
{
    int min, sec;
} 
Time;

typedef struct
{
    char firstName[100];
    char lastName[100];
    char ID[10];
    Time selfRecord;
    Time * record;
    Time runningTime;
    int sT, cT;
}
runner;

int main()
{
    int n, winner, rec = 1000000000, Trec = 1000000000;
    scanf ("%d", &n);
    runner comp[n];
    for (int i = 0; i < n; i++)
    {
        printf ("\nRunner #%d\nFirst name: ", i + 1);
        scanf ("%s", comp[i].firstName);
        printf ("Last name: ");
        scanf ("%s", comp[i].lastName);
        printf ("ID: ");
        scanf ("%s", comp[i].ID);
        comp[i].record = &comp[i].selfRecord;
        printf ("Self record: (min)(sec) ");
        scanf ("%d%d", &comp[i].record->min, &comp[i].record->sec);
        printf ("Competition record: (min)(sec) ");
        scanf ("%d%d", &comp[i].runningTime.min, &comp[i].runningTime.sec);
        comp[i].sT = comp[i].selfRecord.min * 60 + comp[i].selfRecord.sec;
        comp[i].cT = comp[i].runningTime.min * 60 + comp[i].runningTime.sec;
        if (comp[i].cT < rec)
            rec = comp[i].cT;
        if (comp[i].cT < Trec)
            Trec = comp[i].cT;
        if (comp[i].sT < Trec)
            Trec = comp[i].sT;
    }
    int sort[10000][100];
    for (int i = 0; i < 10000; i++)
        for (int j = 0; j < 100; j++)   
            sort[i][j] = -1;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (sort[comp[i].cT][j] >= 0)
            j++;
        sort[comp[i].cT][j] = i;
    }
    printf ("The winner is (are) : %s %s", comp[sort[rec][0]].firstName, comp[sort[rec][0]].lastName);
    for (int i = 1; sort[rec][i] > -1; i++)
        printf (" & %s %s", comp[sort[rec][i]].firstName, comp[sort[rec][i]].lastName);
    printf ("\n");
    if (rec < Trec)
        printf ("New Record!!!\n");
    for (int i = 0; sort[rec][i] > -1; i++)
        if (comp[sort[rec][i]].sT > comp[sort[rec][i]].cT)
            printf ("%s %s broke his/her self record.\n", comp[sort[rec][i]].firstName, comp[sort[rec][i]].lastName);
        
    printf ("First Name:\tLast Name:\tID:\t\tSelf record:\t\tRunning time:\n");
    for (int i = 0; i < 10000; i++)
    {
        int j = 0;
        while (sort[i][j]> -1)
        {
            printf ("%s\t\t%s\t\t%s\t\t%d min & %d sec\t\t%d min & %d sec\n",
                comp[sort[i][j]].firstName, comp[sort[i][j]].lastName, comp[sort[i][j]].ID,
                comp[sort[i][j]].selfRecord.min, comp[sort[i][j]].selfRecord.sec,
                comp[sort[i][j]].runningTime.min, comp[sort[i][j]].runningTime.sec);
            j++;
        }
    }
    return 0;
}

extern int DSL[], CableModem[], FibreBased[], ratio[];
void showMenu(void)
{
    printf("\t\t\tBroadband Subscription 2\n\n");
    printf("Please Enter A, B, C or Q:\n");
    printf("A) TotalSubscriptions\n");
    printf("B) Average Subscription\n");
    printf("C) Highest Ratio\n");
    printf("Q) Exit the Menu\n");
}
void  TotalSubs(void)
{
    char Subscriptions;
    do
    {
    printf("\nPlease Enter A, B, C or Q\nA) Total Subs for DSL\nB) Total Subs for CableModem \nC) Total Subs for FibreBased\nQ) Return to Menu\n");
    scanf(" %c", &Subscriptions);
    switch(Subscriptions)
    {
    case 'A': case 'a':
        printf("\nTotal number of subscriptions for DSL is %d\n", total(DSL));
        break;

    case 'B': case 'b':
        printf("\nTotal number of subscriptions for CableModem is %d\n", total(CableModem));
        break;

    case 'C': case 'c':
        printf("\nTotal number of subscriptions for FibreBased is %d\n", total(FibreBased));
        break;

    case 'Q': case 'q':
        Subscriptions = 'Q';
        break;

    default:
        printf("Invalid entry");
        break;
    }
}while(Subscriptions!='Q');
return 0;
}

int total(int broadband[])
{
    int i, count = 0;

    for(i= 0; i<6; i++)

        {
        count =count + broadband[i];
    }
    return count;
}

void AvgSubs(void)
{
    char Subscriptions;
    do
    {
    printf("Please Enter A, B, C or Q\nA) Bimonthly average subs for DSL\nB) Bimonthly average subs for CableModem \nC) Bimonthly average subs for FibreBased\nQ) Return to Menu\n");
    scanf(" %c", &Subscriptions);
    switch(Subscriptions)
    {
    case 'A': case 'a':
        AvgTotal(DSL);
        break;

    case 'B': case 'b':
        AvgTotal(CableModem);
        break;

    case 'C': case 'c':
        AvgTotal(FibreBased);
        break;

    case 'Q': case 'q':
        Subscriptions='Q';
        break;
    default:
        printf("Invalid Entry\n");
        break;
}
    }while(Subscriptions!='Q');
return 0;
}

void AvgTotal(int broadband[])
{
    float average=0;
    for(int i = 0; i < 6; i++)
        {
        if(i%2 == 0)
            {
            average = (broadband[i] + broadband[i+1])/2;
             printf("The average bimonthly subscriptions for selected broadband is: %.2f\n\n", average);
        }
    }
}

void HighestRatio(void)
{
    char Subscriptions;
    do
    {
        printf("Please Enter A or Q\nA) Highest Ratio for FibreBased and CableModem\nQ) Return to Menu\n");
        scanf(" %c", &Subscriptions);
        switch(Subscriptions)
        {
        case 'A': case 'a':
        findRatio(FibreBased, CableModem);
        break;

        case 'Q': case 'q':
        Subscriptions='Q';
        break;

        default:
        printf("Invalid Entry\n");
        break;

        }
    }while(Subscriptions!='Q');
    return 0;
}

void findRatio(int broadband[],int broadband2[])
{
    float RatioMax = 0.0;
    int i, j=0;
    char Months[][5]={"Jan", "Feb", "Mar" , "Apr", "May", "Jun"};

    for(i = 0; i< 6; i++)
    {
            ratio[i] = broadband[i]/broadband2[i];
            RatioMax = ratio[0];
    if(ratio[i] > RatioMax)
    {
        RatioMax = ratio[i];
        j = j + 1;
    }
    }
    int RatioMax2= RatioMax;
printf("\nThe highest ratio for FibreBased and CableModem is %d and the month is %s\n\n", RatioMax2, Months[j]);
return 0;
}

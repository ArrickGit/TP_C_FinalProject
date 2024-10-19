#include <stdio.h>
#include <stdlib.h>
void showMenu(void), TotalSubs(void), AvgSubs(void), HighestRatio(void);
int main()
{
    char userInput;
    do
    {
        showMenu();

        scanf(" %c", &userInput);

        switch(userInput)
        {
        case 'A': case 'a':
            TotalSubs();
            break;

        case 'B': case 'b':
            AvgSubs();
            break;

        case 'C': case 'c':
            HighestRatio();
            break;

        case 'Q': case 'q':
            userInput= 'Q';
            break;
        default:
            printf("Invalid Entry\n");
        }
    }while(userInput!='Q');
}

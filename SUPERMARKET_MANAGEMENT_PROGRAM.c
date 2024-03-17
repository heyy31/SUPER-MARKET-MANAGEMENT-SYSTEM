SUPER MARKET MANAGEMENT

CODE:

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct product
{
    int pno;
    char name[100];
    float price,qty,tax,dis;
}p[100];
int n,k=0;
int x[100];
float tax;
char userch;
void admin ();
void create();
void display();
void modify();
void user();

void admin()
{
  system("cls");
  int ch2;
  printf ("-------------------------------------------------------------\n");
  printf ("1.ADD PRODUCT:-\n");
  printf ("2.DISPLAY ALL PRODUCT:-\n");
  printf ("3.DELETE A PRODUCT:-\n");
  printf ("4.BACK TO MAIN:- \n");
  printf ("-------------------------------------------------------------\n");
  scanf ("ENTER YOUR CHOICE:- \n");
  scanf ("%d", &ch2);
  switch (ch2)
    {
    case 1:
      create();
      break;
    case 2:
        display();
      break;
    case 3:
        del();
      break;
    case 4:
        main();
        break;
    default:
      printf ("PLEASE TRY AGAIN WITH CORRECT INPUT---THANKYOU \n");
      admin();
    }
}
void create()
{
    printf("\nENTER THE NUMBER OF PRODUCTS U WANT TO CREATE\n");
    scanf("%d",&n);
    int i;float tax;
    for(i=0;i<n;i++)
    {
        printf("ENTER THE PRODUCT ID:-\n");
        scanf("%d",&p[i].pno);
        printf("ENTER PRODUCT NAME:- \n");
        scanf("%s",p[i].name);
        printf("ENTER THE PRICE:-\n");
        scanf("%f",&p[i].price);
        printf("ENTER DISCOUNT PERCENTAGE:-\n");
        scanf("%f",&p[i].dis);
    }
    printf("ENTER TAX TO BE APPLIED ON BILL \n");
    scanf("%f",&tax);
    printf("THE PRODUCTS ARE CREATED \n");
    printf("THANKYOU\n");
    getch();
    admin();
}
void display()
{
    char userch;
    int i;
    for(i=0;i<n;i++)
    {
        if(p[i].pno!=0)
        {
            printf("THE PRODUCT ID:- %d \n",p[i].pno);
            printf("THE PRODUCT NAME:- %s \n",p[i].name);
            printf("PRICE OF PRODUCT:- %f \n",p[i].price);
            printf("DISCOUNT:- %f \n",p[i].dis);
        }

    }
    printf("\nTHE PRODUCT ARE DISPLAYED\n");
    printf("THANKYOU\n");
    getch();
    if(userch == 'A')
    admin();
    else if(userch == 'U')
    user();

}
void del()
{
    int i,x;
    printf("ENTER THE PRODUCT ID TO BE DELETED\n");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(p[i].pno==x)
        {
            printf("\nRECORD FOUND AND DELETED SUCCESSFUL\n");
            p[i].pno=0;
            break;
        }
    }
    getch();
    admin();

}
float total=0.0;
void user()
{
    int y,i,qty,ch,a,yc;
    float amt=0.0,tot=0.0;
    char nam[20],address[100],phone[10],name1[10];
    display();
    printf("\n ---------WELCOME TO OUR SUPERMARKET--------- \n");
    while (y!=0)
    {
        printf("SELECT THE PRODUCT ID U WANT TO PURCHASE");
        printf("\nENTER UR CHOICE\n");
        scanf("%d",&y);
        getch();
    for(i=0;i<n;i++)
    {
        tot=0.0;
        if(p[i].pno==y)
        {
            printf("ENTER QUANTITY OF PRODUCT U WANT TO PURCHASE \n");
            scanf("%d",&qty);
            amt=(p[i].price-(p[i].price*(p[i].dis*0.001))+tax);
            tot=amt*qty;
             total+=tot;
             x[k]=i;
             k++;
            break;
        }
    }
        printf("IF U WISH TO PROCEED FOR MORE PRODUCTS PRESS 1");
        scanf("%d",&yc);
        if(yc==1)
        continue;
    else
    break;
    }
    printf("--THE FINAL TOTAL IS:- %f \n",total);
    getch();
    printf("DO YOU WANT TO PROCEED FOR BILLING\n");
    printf("--ENTER\n1.TO PROCEED \n");
    printf("2. TO CONTINUE SHOPPING \n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("ENTER UR NAME:- \n");
        scanf("%s",nam);
        printf("ENTER UR ADDRESS:- \n");
        scanf("%s",address);
        printf("ENTER UR CONTACT NO.:- \n");
        scanf("%s",phone);
        break;
        case 2:
        user();
        break;
        default:
        printf("INVALID INPUT");
    }
        printf("--TO PROCEED FOR BILL:- \n");
        printf("---1.YES--- \n");
        printf("---2.NO--- \n");
        scanf("%d",&a);

          if(a==1)
       {
           system("cls");
            printf("--------------------------------------------\n");
            printf("-------BILL-------\n");
            printf("NAME:- %s \n",nam);
            printf("ADDRESS:- %s \n",address);
            printf("CONTACT NO.:- %s \n",phone);
            printf("PRODUCT DETAILS:- \n");
            for(i=0;i<k;i++)
            {
                printf("PRODUCT NAME:- %s \n",p[x[i]].name);
            }
            printf("TOTAL AMOUNT:- %f \n",total);
            printf("-------THANKS FOR SHOPPING-----\n");
            exit(0);
       }
        else
        {
            printf("THANKS");
            exit(0);
        }

}
int main()
{
    system("cls");
    system("color E2");
    printf("--------------------------------SUPERMARKET-------------------------------\n");
    printf("----ENTER PASSWORD TO START THE SYSTEM:\n");
    char pass[20]="FileHandling";char password[20];
    FILE *fp;
    fp=fopen("login.txt","wb");
    fwrite(pass,1,20,fp);
    fclose(fp);
    printf("----ENTER YOUR PASSWORD:-\n");
    for(int i=0;i<12;i++)
    {
        password[i]=getch();
        printf("*");
    }
    printf("\n \n");
    fp=fopen("login.txt","rb");
    fread(pass,1,20,fp);
    if(strcmp(pass,password)==0)
    {
        printf("-----WELCOME TO OUR SUPERMARKET---- \n");
        char userChoice; //Variable to use to select menu choice
        while (userChoice != 'Q') {
        printf ("*\n");
        printf ("PLEASE ENTER THE FUNCTION U WANT TO OPERATE:\n");
        printf("'A': ADMIN:-\n");
        printf("'U': USER:-\n");
        printf("'Q': QUIT:-\n");
        printf ("*\n");

        scanf("%s", &userChoice);  //Stores menu choice into variable userChoice
        // Add Contact
        userch=userChoice;
        if (userChoice == 'A')
           admin();

        //Remove Contact
        if (userChoice == 'U')
            user();

        //Quit
        if (userChoice == 'Q') {
            printf("---SUPERMARKET IS CLOSED---\n");
            exit(0);
            return 0;
        }
    }
}
else
{
    printf("WRONG PASSWORD \n");
    exit(0);
}
    return 0;
}



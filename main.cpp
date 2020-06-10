#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

void gotoxy(int,int);
void starting_fun();
int display();
void heading();
int security();

void valid(int);
void search_goods(int);
void search_goods_sub(int,string,int);
int add_goods();
void edit_goods(int);
void edit_goods_sub();
int delete_goods();
void bill(int);
void display_goods(int);
int i=0,num=0;
string cc1,cc2,phn;


/*structure for details*/
struct details
    {
       int quantity;
       float price,total;
       string id;
       char name[20];
    }item[50];

/*main function*/
int main()
{
    system("MODE CON COLS=130 LINES=30");
    starting_fun();
    getch();
    return 0;
}
/*gotoxy function*/
inline void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*security function*/
inline int security()
{
    string pwrd;
    gotoxy(55,2);
    cout<<"***** *SUPER MARKET* *****"<<endl;
    gotoxy(59,3);
    cout<<"  Billing System   "<<endl;
    gotoxy(48,8);
    cout<<"Enter the Password :";
    cin>>pwrd;
   int res = strcmp(pwrd.c_str(),"123");          //c_str() *********FOR STRING TO ARRAY ****//
   if(res==0)
   {
      system("cls");
      heading();
      gotoxy(48,8);
      cout<<"Enter customer details : "<<endl;
      gotoxy(48,12);
      cout<<"Enter customer first name : ";
      cin>>cc1;
      fflush(stdin);
      gotoxy(48,13);
      cout<<"Enter customer last name : ";
      cin>>cc2;
      fflush(stdin);
      gotoxy(48,14);
      cout<<"Enter customer phone number : ";
      cin>>phn;
      fflush(stdin);
      int opt= display();
      return(opt);

   }
   else
   {
       gotoxy(48,10);
       cout<<"Invalid Password"<<endl;
       exit(1);
   }
}
/*starting of program*/
inline void starting_fun()
{
    int num1=0;
    int opt=security();
    while(opt>=1  && opt<=7 )
    {
        switch(opt)
        {
            case 1:if(num1==0)
            {
                valid(opt);             break;
            }
            else
            {
                search_goods(num);      break;
            }
            case 2:
                num1=add_goods();       break;
            case 3:if(num1==0)
            {
                valid(opt);             break;
            }
            else
            {
                edit_goods(num);        break;
            }
            case 4:if(num1==0)
            {
                valid(opt);             break;
            }
            else
            {
                num=delete_goods();     break;
            }
            case 5:if(num1==0)
            {
                valid(opt);             break;
            }
            else
            {
                bill(num);              break;
            }
            case 6:if(num1==0)
            {
                valid(opt);             break;
            }
            else
            {
                display_goods(num);     break;
            }
            case 7:
                   exit(1);
        }
            opt=display();
    }
}
/*display function*/
inline int display()
{
    int opt;
    system("cls");                                     //FOR NEW LAYOUT//
        gotoxy(50,2);
    cout<<"***** *SUPER MARKET* *****"<<endl;
    gotoxy(54,3);
    cout<<"  Billing System   "<<endl;
        gotoxy(56,7);
        cout<<"Main Menu"<<endl;
        gotoxy(54,8);
        cout<<"=============="<<endl;
        gotoxy(46,10);
        cout<<"1. Search"<<endl;
        gotoxy(46,12);
        cout<<"2. Add Goods"<<endl;
        gotoxy(46,14);
        cout<<"3. Edit Goods"<<endl;
        gotoxy(46,16);
        cout<<"4. Delete Goods"<<endl;
        gotoxy(46,18);
        cout<<"5. Calculate Bill"<<endl;
        gotoxy(46,20);
        cout<<"6. Display All"<<endl;
        gotoxy(46,22);
        cout<<"7. Exit"<<endl;
        gotoxy(46,24);
        cout<<"Please enter the required option :";
        cin>>opt;
        if(opt>=1 && opt<=7 )
        {
            return(opt);
        }
        else
        {
            gotoxy(46,26);
            cout<<"Invalid Choice"<<endl;
        }
}
/*search goods function*/
inline void search_goods(int num)
{
    int sopt,a=1,b=2;
    string temp,example;
    system("cls");
    heading();
    gotoxy(56,8);
    cout<<"SEARCH MENU"<<endl;
    gotoxy(56,12);
    cout<<"1. By Code "<<endl;
    gotoxy(56,13);
    cout<<"2. By Name "<<endl;
    gotoxy(56,14);
    cout<<"Enter required option : ";
    cin>>sopt;

    switch(sopt)
    {
    case 1:
    system("cls");
    heading();
    gotoxy(56,8);
    cout<<"SEARCH MENU"<<endl;
    gotoxy(38,12);
    cout<<"Enter the code of item :";
    cin>>temp;
    search_goods_sub(num,temp,a);
    break;
    case 2:
    system("cls");
    heading();
    gotoxy(56,8);
    cout<<"SEARCH MENU"<<endl;
    gotoxy(38,12);
    cout<<"Enter the name of item :";
    cin>>temp;
    search_goods_sub(num,temp,b);
    break;
    default:gotoxy(42,20);
            cout<<"Invalid Choice"<<endl;
    }
getch();
}
/*search_goods_sub function*/
inline void search_goods_sub(int num,string temp,int c)
{
    string example;
    int s,i,k=12;
    system("cls");
    heading();
    gotoxy(56,8);
    cout<<"SEARCH MENU"<<endl;
    for(i=0;i<num;i++)
    {
        if(c==1)
        {
            example=item[i].id;
        }
        if(c==2)
        {
            example=item[i].name;
        }
        s=strcmp(example.c_str(),temp.c_str());
        if(s==0)
        {
    gotoxy(32,10);
    cout<<"Code"<<endl;
    gotoxy(50,10);
    cout<<"Name"<<endl;
    gotoxy(68,10);
    cout<<"Quantity"<<endl;
    gotoxy(86,10);
    cout<<"Price"<<endl;
        gotoxy(32,k);
        cout<<item[i].id;
        gotoxy(50,k);
        cout<<item[i].name;
        gotoxy(68,k);
        cout<<item[i].quantity;
        gotoxy(86,k);
        cout<<item[i].price;
        cout<<"\n";
        ++k;
        break;
        }
    }
    if(s!=0)
    {
        gotoxy(52,16);
        cout<<"Item does not exists"<<endl;
        getch();
    }
}
/*adding goods function*/
inline int add_goods()
{
    heading();
    char ch='y';
    while(toupper(ch)=='Y')
    {
        system("cls");
        heading();
        gotoxy(56,8);
        cout<<"ADD ARTICLES"<<endl;
        gotoxy(48,12);
        cout<<"Enter code of article : ";
        cin>>item[i].id;
        fflush(stdin);
        int b = 0;
         for(int j=0;j<num;j++)
        {
            if(item[i].id == item[j].id)
            {
                b = 1;
                gotoxy(48,14);
                cout<<"Code already exists"<<endl;
                gotoxy(48,15);
                cout<<"Press enter to add new code "<<endl;
                getch();
            }
        }
        if(b == 0)
        {
        gotoxy(48,14);
        cout<<"Enter name of item : ";
        gets(item[i].name);
        fflush(stdin);
        gotoxy(48,16);
        cout<<"Enter quantity of item : ";
        cin>>item[i].quantity;
        fflush(stdin);
        gotoxy(48,18);
        cout<<"Enter the price of item : ";
        cin>>item[i].price;
        fflush(stdin);
        ++i;
        ++num;
        gotoxy(48,20);
        cout<<"You want to enter new record (Y/N) ?";
        ch=getche();
        }
    }
    return(num);
}
/*function to edit items*/
inline void edit_goods(int num)
{
    string eid1,eid2;
    char ch;
    int t,s,choice,k=12;
    system("cls");
    heading();
    gotoxy(56,6);
    cout<<"EDIT RECORDS"<<endl;
    gotoxy(38,12);
    cout<<"Enter code of item : ";
    cin>>eid1;
    for(t=0;t<num;t++)
        {
            eid2=item[t].id;
            s=strcmp(eid1.c_str(),eid2.c_str());
            if(s==0)
            {
                system("cls");
                heading();
                gotoxy(56,6);
                cout<<"EDIT RECORDS"<<endl;
    gotoxy(33,10);
    cout<<"Code"<<endl;
    gotoxy(51,10);
    cout<<"Name"<<endl;
    gotoxy(70,10);
    cout<<"Quantity"<<endl;
    gotoxy(88,10);
    cout<<"Price"<<endl;
                for(int i=t;i<num;i++)
                {
                     gotoxy(33,k);
                     cout<<item[i].id;
                     gotoxy(51,k);
                     cout<<item[i].name;
                     gotoxy(70,k);
                     cout<<item[i].quantity;
                     gotoxy(88,k);
                     cout<<item[i].price;
                     cout<<"\n";
                     ++k;
                    break;
                }
        gotoxy(38,16);
        cout<<"Do you want to edit this record ? (Y/N) : ";
        cin>>ch;
         if(toupper(ch)=='Y')
        {
            gotoxy(38,19);
            cout<<"1. Edit Quantity"<<endl;
            gotoxy(38,20);
            cout<<"2. Edit Price"<<endl;
            gotoxy(38,23);
            cout<<"Enter your choice (1,2) : ";
            cin>>choice;

            switch(choice)
            {
            case 1:
                edit_goods_sub();
                gotoxy(52,14);
                cout<<"Enter new quantity : ";
                cin>>item[t].quantity;
                gotoxy(51,18);
                cout<<"***** Item Edited *****"<<endl;
                getch();
                break;
            case 2:
                edit_goods_sub();
                gotoxy(52,14);
                cout<<"Enter new price : ";
                cin>>item[t].price;
                gotoxy(51,18);
                cout<<"***** Item Edited *****"<<endl;
                getch();
                break;
            }
        }
        break;
        }
    }
    if(s!=0)
    {
        gotoxy(46,16);
        cout<<"Item code does not exists"<<endl;
        getch();
    }
}
/*edit_goods_sub function*/
inline void edit_goods_sub()
{
    system("cls");
    heading();
    gotoxy(56,6);
    cout<<"EDIT RECORDS"<<endl;
}
/*function to delete items*/
inline int delete_goods()
{
    string did1,did2,s1,s2;
    int s,t,j;
    system("cls");
    heading();
    gotoxy(55,6);
    cout<<"DELETE ARTICLES"<<endl;
    gotoxy(52,12);
    cout<<"Enter code of item : ";
    cin>>did1;
    for(t=0;t<num;t++)
        {
            did2=item[t].id;
            s=strcmp(did1.c_str(),did2.c_str());
            if(s==0)
            {
                for(j=t;j<num;j++)
                {
                    item[j].id=item[j+1].id;
                    s1=item[j].name;s2=item[j+1].name;s1=s2; //*******conversion of char array to string********//
                    item[j].quantity=item[j+1].quantity;
                    item[j].price=item[j+1].price;
                }
                gotoxy(52,15);
                cout<<"---- Item Deleted ----"<<endl;
                --num;
                --i;
                getch();
                break;
            }
        }
        if(s!=0)
        {
            gotoxy(49,15);
            cout<<"---- Item does not exists ----"<<endl;
            getch();
        }
        return(num);
}
/*function to calculate bills*/
void bill(int num)
{
   int i=0,sum=0,k=12;
    system("cls");                                     ofstream fout;
    heading();
    gotoxy(28,8);
    cout<<"Customer name : "<<cc1<<" "<<cc2;
    gotoxy(58,6);                                      fout.open("Master Records.txt",ios::app);
    cout<<"CUSTOMER'S BILL"<<endl;
    gotoxy(84,8);
    cout<<"Phn No. : "<<phn<<endl;                     fout<<"***** *SUPER MARKET* *****";
    gotoxy(24,10);                                     fout<<"\n      Billing System \n"<<endl;
    cout<<"Sr no."<<endl;                              fout<<"     CUSTOMER'S BILL\n"<<endl;
    gotoxy(42,10);                                     fout<<"Customer name :- "<<cc1<<" "<<cc2;
    cout<<"Name"<<endl;                                fout<<"        Phn No. : "<<phn<<endl;
    gotoxy(60,10);                                     fout.close();
    cout<<"Quantity"<<endl;
    gotoxy(78,10);
    cout<<"Price"<<endl;
    gotoxy(96,10);
    cout<<"Total"<<endl;
    for(int j=1;j<=num;j++)
    {
        gotoxy(24,k);                                  fout.open("Master Records.txt",ios::app);
        cout<<j<<".";                                  fout<<" \n"<<i+1<<". ";
        gotoxy(42,k);                                  fout<<"Code: "<<item[i].id;
        cout<<item[i].name;                            fout<<" Name: "<<item[i].name;
        gotoxy(60,k);
        cout<<item[i].quantity;                        fout<<" Quantity: "<<item[i].quantity;
        gotoxy(78,k);
        cout<<item[i].price;                           fout<<" Price: "<<item[i].price;
        item[i].total = item[i] .quantity * item[i].price;
        gotoxy(96,k);
        cout<<item[i].total;
        sum =  sum + item[i].total;                    fout<<" Total: "<<item[i].total;
        cout<<"\n";                                    fout<<endl;
        ++k;
        ++i;                                           fout.close();
    }                                                  fout.open("Master Records.txt",ios::app);
   gotoxy(50,20);                                      fout<<"\n"<<"GRAND TOTAL AMOUNT :- "<<sum<<"\n"<<endl;
   cout<<"GROSS TOTAL AMOUNT :- "<<sum<<endl;          fout.close();
   getch();
}
/*function to display items*/
inline void display_goods(int num)
{
    int i=0,k=12;
    system("cls");
    heading();
    gotoxy(58,6);
    cout<<"RECORDS"<<endl;
    gotoxy(24,10);
    cout<<"Sr no."<<endl;
    gotoxy(42,10);
    cout<<"Code"<<endl;
    gotoxy(60,10);
    cout<<"Name"<<endl;
    gotoxy(78,10);
    cout<<"Quantity"<<endl;
    gotoxy(96,10);
    cout<<"Price"<<endl;
    for(int j=1;j<=num;j++)
    {
        gotoxy(24,k);
        cout<<j<<".";
        gotoxy(42,k);
        cout<<item[i].id;
        gotoxy(60,k);
        cout<<item[i].name;
        gotoxy(78,k);
        cout<<item[i].quantity;
        gotoxy(96,k);
        cout<<item[i].price;
        cout<<"\n";
        ++k;
        ++i;
    }
    getch();
}
/*function for validation*/
inline void valid(int opt)
{
    system("cls");
    heading();
    switch(opt)
    {
    case 1:
        gotoxy(56,8);
        cout<<"SEARCH MENU"<<endl;
        gotoxy(50,14);
        cout<<"---- No Results Found ----";
        getch();
        break;
    case 3:
        gotoxy(56,8);
        cout<<"EDIT RECORDS"<<endl;
        gotoxy(50,14);
        cout<<"---- No Data Avaliable ----";
        getch();
        break;
    case 4:
        gotoxy(56,8);
        cout<<"DELETE ARTICLES"<<endl;
        gotoxy(50,14);
        cout<<"---- No Data Avaliable ----";
        getch();
        break;
    case 5:
        gotoxy(56,8);
        cout<<"CUSTOMER'S BILL"<<endl;
        gotoxy(50,14);
        cout<<"---- No Data Avaliable ----";
        getch();
        break;
    case 6:
        gotoxy(56,8);
        cout<<"RECORDS"<<endl;
        gotoxy(50,14);
        cout<<"---- No Results Found ----";
        getch();
        break;
    }
}
/*function for heading*/
void heading()
{
    system("cls");
    gotoxy(50,2);
    cout<<"***** *SUPER MARKET* *****"<<endl;
    gotoxy(54,3);
     cout<<"  Billing System   "<<endl;
}

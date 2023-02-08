#include<windows.h>

#include<stdio.h>

#include<conio.h>

#include <stdlib.h>

#include<string.h>

#include<ctype.h>

#include<dos.h>

#include<time.h>



#define RETURNTIME 15



char catagories[][15]={"HUAWEI","VIVO","XAOMI","OPPO","READMI","ALCATEL"};

void retFunction(void);

void mobileMainWindowMenu(void);

void mobileAdding(void);

void mobileDelete(void);

void MobileEditing(void);

void mobileSearching(void);

void mobileViewWindow(void);

void exitSystem(void);

int  getdata();

int  checkid(int);

int t(void);



void mobilePassword();

void mobileRecIssue();

void animationLoading();





FILE *fp,*ft,*fs;





COORD coord = {0, 0};



int s;

char mobileFindingEmp;

char mobilePass[10]={"admin"};



void gotoxy (int x, int y)

{

coord.X = x; coord.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}



struct meroDate

{

int mm,dd,yy;

};

struct staff

{

int id;

char firstname[20];

char mobileName[20];

char mobileAvail[20];

int mobileQuantity;

int mobilePrice;

int counting;

char *mobileCategory;

struct meroDate issued;

struct meroDate duedate;

};

struct staff a;

int main()

{

mobilePassword();

getch();

return 0;



}

void mobileMainWindowMenu()

{

system("cls");

int i;


printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
printf("\n\t\t\t\t\t        +     			 MAIN MENU    		+      ");
printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");



gotoxy(20,5);

printf("[1] Add Mobile Record   ");

gotoxy(20,7);

printf("[2] Delete Mobile Record");

gotoxy(20,9);

printf("[3]Search Mobile Record");

gotoxy(20,11);

printf("[4] View Mobile list");

gotoxy(20,13);

printf("[5] Edit Mobile Record");

gotoxy(20,15);

printf("[6] Exit System");

gotoxy(20,22);

t();

gotoxy(20,18);

printf("Enter your choice:");



switch(getch())

{

case '1':

mobileAdding();

break;

case '2':

mobileDelete();

break;

case '3':

mobileSearching();

break;

case '4':

mobileViewWindow();

break;

case '5':

MobileEditing();

break;

case '6':

{

system("cls");

gotoxy(16,3);

printf("\tMOBILE SHOP MANAGEMENT SYSTEM");

gotoxy(16,4);

printf("\tTHANK YOU");





exit(0);

}

default:

{

gotoxy(10,25);

printf("\aWrong Entry!!Please re-entered correct option");

if(getch())

mobileMainWindowMenu();

}



}

}

void mobileAdding(void)

{

system("cls");

int i;

gotoxy(20,5);

printf("SELECT BRANDS");

gotoxy(20,7);

printf("[1]HUAWEI");

gotoxy(20,9);

printf("[2] VIVO");

gotoxy(20,11);

printf("[3] XAOMI");

gotoxy(20,13);

printf("[4] OPPO");

gotoxy(20,15);

printf("[5] READMI");

gotoxy(20,17);

printf("[6] ALCATEL");

gotoxy(20,19);

printf("[7] Back to main menu");

gotoxy(20,21);



printf("Enter your choice:");

scanf("%d",&s);

if(s==7)



mobileMainWindowMenu() ;

system("cls");

fp=fopen("stf.dat","ab+");

if(getdata()==1)

{

a.mobileCategory=catagories[s-1];

fseek(fp,0,SEEK_END);

fwrite(&a,sizeof(a),1,fp);

fclose(fp);

gotoxy(21,14);

printf("The record is sucessfully saved");

gotoxy(21,15);

printf("Save any more?(Y / N):");

if(getch()=='n')

mobileMainWindowMenu();

else

system("cls");

mobileAdding();

}

}

void mobileDelete()

{

system("cls");

int d;

char another='y';

while(another=='y')

{

system("cls");

gotoxy(10,5);

printf("Enter the Mobile ID to  delete:");

scanf("%d",&d);

fp=fopen("stf.dat","rb+");

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id==d)

{



gotoxy(10,7);

printf("The Mobile record is available");

gotoxy(10,8);

printf("Staff name is %s",a.mobileName);

gotoxy(10,9);

mobileFindingEmp='t';

}

}

if(mobileFindingEmp!='t')

{

gotoxy(10,10);

printf("No record is found modify the search");

if(getch())

mobileMainWindowMenu();

}

if(mobileFindingEmp=='t' )

{

gotoxy(10,9);

printf("Do you want to delete it?(Y/N):");

if(getch()=='y')

{

ft=fopen("test.dat","wb+");

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id!=d)

{

fseek(ft,0,SEEK_CUR);

fwrite(&a,sizeof(a),1,ft);

}

}

fclose(ft);

fclose(fp);

remove("stf.dat");

rename("test.dat","stf.dat");

fp=fopen("stf.dat","rb+");

if(mobileFindingEmp=='t')

{

gotoxy(10,10);

printf("The record is sucessfully deleted");

gotoxy(10,11);

printf("\n\tDelete another record?(Y/N)");

}

}

else

mobileMainWindowMenu();

fflush(stdin);

another=getch();

}

}

gotoxy(10,15);

mobileMainWindowMenu();

}

void mobileSearching()

{

system("cls");

int d;

printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
printf("\n\t\t\t\t\t        +     			 SEARCH MOBILE    		+      ");
printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");

gotoxy(20,10);

printf("1. Search By ID");

gotoxy(20,14);

printf("2. Search By Name");

gotoxy( 15,20);

printf("Enter Your Choice");

fp=fopen("stf.dat","rb+");

rewind(fp);

switch(getch())

{

case '1':

{

system("cls");

printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
printf("\n\t\t\t\t\t        +     			 SEARCH BY MOBILE ID    		+      ");
printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
gotoxy(20,5);

printf("Enter the Mobile id:");

scanf("%d",&d);

gotoxy(20,7);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id==d)

{

Sleep(2);

gotoxy(20,6);

printf("The Mobile is available\n");

gotoxy(20,8);

printf("ID:%d",a.id);

gotoxy(20,9);

printf("Brand:%s",a.mobileCategory);

gotoxy(20,10);

printf("Name:%s",a.mobileName);

gotoxy(20,11);

printf("Availability:%s ",a.mobileAvail);

gotoxy(20,12);

printf("Quantity:%i ",a.mobileQuantity);

gotoxy(20,13);

printf("Price:%i ",a.mobilePrice);

gotoxy(20,14);

mobileFindingEmp='t';

}



}

if(mobileFindingEmp!='t')

{

printf("\aNo Record Found");

}

gotoxy(20,17);

printf("Try another search?(Y/N)");

if(getch()=='y')

mobileSearching();

else

mobileMainWindowMenu();

break;

}

case '2':

{

char s[15];

system("cls");



printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
printf("\n\t\t\t\t\t        +     			 SEARCH BY MOBILE PHONE    	+      ");
printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
gotoxy(20,5);

printf("Enter Mobile Name:");

scanf("%s",s);

int d=0;

while(fread(&a,sizeof(a),1,fp)==1)

{

if(strcmp(a.mobileName,(s))==0)

{

	gotoxy(20,d+7);

	//printf("The Staff is available");

	gotoxy(20,d+8);

	printf("ID:%d",a.id);

	gotoxy(20,d+10);

	printf("Name:%s",a.mobileName);

	gotoxy(20,d+11);

	printf("Availability:%s",a.mobileAvail);

	gotoxy(20,d+12);

	printf("Quantity:%i",a.mobileQuantity);

	gotoxy(20,d+13);

	printf("Price:%i",a.mobilePrice);

	gotoxy(20,d+14);

	getch();

	d+=6;

}



}

if(d==0)



printf("\aNo Record Found");



gotoxy(20,d+11);

printf("Try another search?(Y/N)");

if(getch()=='y')

	mobileSearching();

else

	mobileMainWindowMenu();

break;

}

default :

getch();

mobileSearching();

}

fclose(fp);

}



void mobileViewWindow(void)

{

int i=0,j;

system("cls");

gotoxy(1,1);

printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
printf("\n\t\t\t\t\t        +     			 MOBILE LIST    		+      ");
printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
gotoxy(2,2);

printf(" BRAND        ID    BRAND NAME    AVAILABILITY  QUANTITY   PRICE ");


j=4;

fp=fopen("stf.dat","rb");

while(fread(&a,sizeof(a),1,fp)==1)

{

gotoxy(3,j);

printf("%s",a.mobileCategory);

gotoxy(16,j);

printf("%d",a.id);

gotoxy(22,j);

printf("%s",a.mobileName);

gotoxy(36,j);

printf("%s",a.mobileAvail);

gotoxy(50,j);

printf("%i",a.mobileQuantity);

gotoxy(61,j);

printf("%i",a.mobilePrice);

gotoxy(60,j);

printf("\n\n");

j++;

}

fclose(fp);

gotoxy(35,25);

retFunction();

}

void MobileEditing(void)

{

system("cls");

int c=0;

int d,e;



printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
printf("\n\t\t\t\t\t        +     			 EDIT MOBILE SECTION   		+      ");
printf("\n\t\t\t\t\t        ++++++++++++++++++++++++++++++++++++++++++++++++      ");
char another='y';

while(another=='y')

{

system("cls");

gotoxy(15,6);

printf("Enter Mobile Id to be edited:");

scanf("%d",&d);

fp=fopen("stf.dat","rb+");

while(fread(&a,sizeof(a),1,fp)==1)

{

if(checkid(d)==0)

{

gotoxy(15,7);

printf("The Mobile is availble");

gotoxy(15,8);

printf("The Mobile ID:%d",a.id);

gotoxy(15,9);

printf("Enter new name:");

scanf("%s",a.mobileName);

gotoxy(15,10);

printf("Enter new Availability Status:");

scanf("%s",a.mobileAvail);

gotoxy(15,11);

printf("Enter new Quantity:");

scanf("%i",&a.mobileQuantity);

gotoxy(15,12);

printf("Enter new Price:");

scanf("%i",&a.mobilePrice);

gotoxy(15,13);

printf("The record is modified");

fseek(fp,ftell(fp)-sizeof(a),0);

fwrite(&a,sizeof(a),1,fp);

fclose(fp);

c=1;

}

if(c==0)

{

gotoxy(15,9);

printf("No record found");

}

}

gotoxy(15,16);

printf("Modify another Record?(Y/N)");

fflush(stdin);

another=getch() ;

}

retFunction();

}

void retFunction(void)

{

{

gotoxy(15,20);

printf("Press ENTER to return to main menu");

}

a:

if(getch()==13)

mobileMainWindowMenu();

else

goto a;

}

int getdata()

{

int t;

gotoxy(20,3);

printf("Enter the Information Below");

gotoxy(20,4);

printf("Brand:");

gotoxy(31,5);

printf("%s",catagories[s-1]);

gotoxy(21,6);

printf("MBL ID:\t");

gotoxy(30,6);

scanf("%d",&t);

if(checkid(t) == 0)

{

gotoxy(21,13);

printf("\aThe id already exists\a");

getch();

mobileMainWindowMenu();

return 0;

}

a.id=t;

gotoxy(21,7);

printf("Model Name:");

gotoxy(33,7);

scanf("%s",a.mobileName);

gotoxy(21,8);

printf("Availability:");

gotoxy(35,8);

scanf("%s",a.mobileAvail);

gotoxy(21,9);

printf("Quantity:");

gotoxy(31,9);

scanf("%i",&a.mobileQuantity);

gotoxy(21,10);

printf("Price:");

scanf("%i",&a.mobilePrice);

return 1;

}

int checkid(int t)

{

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

if(a.id==t)

return 0;

return 1;

}

int t(void)

{

time_t t;

time(&t);

printf("Date and time:%s\n",ctime(&t));



return 0 ;

}



void mobilePassword(void)

{



system("cls");

char d[25]="Password Protected";

char ch,pass[10];

int i=0,j;





	
	printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    printf("\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      + 			LOGIN			+      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      +                                              +      +");
    printf("\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
    printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t \n\n\n Enter Password:");



while(ch!=13)

{

ch=getch();



if(ch!=13 && ch!=8){

putch('*');

pass[i] = ch;

i++;

}

}

pass[i] = '\0';

if(strcmp(pass,mobilePass)==0)

{

printf("\n\n\n\t\tPassword matched!!");

printf("\n\n\tPress any key to countinue.....");

getch();

mobileMainWindowMenu();

}

else

{

printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");

getch();

mobilePassword();

}

}






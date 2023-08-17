
#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
void input(char [][2]);
void generation(char [][2]);
void check_r(char [][2],char [][2],int x,int *);
void match(int,char [][2],char [][2],int,int*);
void check_w(char [][2],char [][2],int *);

struct store
{
	char arr[4][2];
	char pins[4][5];
}store[8];



int main()
{

	
    int choice;
	system("cls");
    printf("\n\n\n\t\t\t\t\t\t\t\tMASTERMIND\n\t\t\t\t\t\t\t\t----------");
    printf("\n\t\t\t\t\t\t\t\tThe classical code cracking game\n");
    printf("\nEnter 1 to go to the instructions page, 2 to start playing the game, 3 to exit\n");
    scanf("%d",&choice);
	system("cls");
    if(choice==1)
	{

		FILE *f1=fopen("instructions.txt","r");
		char s[2000];
		while(fgets(s,2000,f1))
			printf("%s",s);
		printf("\nEnter 2 to start playing the game, 3 to exit\n");
    		scanf("%d",&choice);
		system("cls");

	}
        if(choice==3)
		exit(0);
        
    
       int chance,g=-1 ;
    char user[4][2] ,gen_code[4][2];
if(choice==2)
{
   
   generation(gen_code);
  for(chance=1;chance<=8;chance++)
  {
     
 	printf("\n\nThe available colours are:RED,YELLOW,GREEN,BLUE,ORANGE,PINK,VIOLET\n");
       printf("\nThis is your %d guess\n",chance);
   input(user);
   g++;
   
       
     
     
    char chc='c';
    while(chc=='c'||chc=='C')
    {
        printf("Enter S to submit and C to change the input\n");
    scanf (" %c", &chc);
    if(chc=='c'||chc=='C')
    input(user);
    if(chc=='s'||chc=='S')
    {
	system("cls");
    	break;
    }
   
    }
   
     int count_r=0;    //count no. of red pins
    int *red;           //pointer to refer to no.of red pins
    red=&count_r;
    check_r(gen_code,user,1,red);
   
   
   
   int count_w=0;           //count no. of white pins
    int *c_w=&count_w;      //pointer to refer to no.of white pins
   
   check_w(gen_code,user,c_w);
   printf("\n");
 
 	

	for(int i=0;i<4;i++)			//storing user array in structures
	{
		for(int j=0;j<2;j++)
		store[g].arr[i][j]=user[i][j];
	}
     
	
     if(count_r==4)             //winner
     {
        printf("\nCongratulations!! You guessed it right!!\n");
	printf("\nThe secret code was\n");
  	for(int m=0;m<4;m++)        //print gen array
      	{
         
       	for(int n=0;n<2;n++)
           
               printf("%c",gen_code[m][n]);
           
           printf("  ");
      }
        break;
     }
	char colr[5]="red  ";
	char colw[5]="white";
	int s_row=0;
   for(int i=0;i<count_r;i++)       //no.of times red has to be printed
   {
	for(int k=0;k<5;k++)
	store[g].pins[s_row][k]=colr[k];
	s_row++;
   
   }
   for(int i=0;i<(count_w-count_r);i++)         //no.of times white has to be printed
   {
	for(int k=0;k<5;k++)
	store[g].pins[s_row][k]=colw[k];
	s_row++;
   
   }

	for(int k=0;k<chance;k++)			//printing struct members
     
	{
		if(k==0)
			printf("Your guesses are\n");
	 	for(int i=0;i<4;i++)
		{	
			for(int j=0;j<2;j++)
			{
			
				printf("%c",store[k].arr[i][j]);
			}
			printf(" ");
		}
		printf("	");
		for(int i=0;i<4;i++)
		{	
			for(int j=0;j<5;j++)
			{
			
				printf("%c",store[k].pins[i][j]);
			}
			printf(" ");
		}
		printf("\n");
		
	}
  }


  if(chance==9)
  {
  printf("\nThe secret code was\n");
  for(int m=0;m<4;m++)        //print gen array
      {
         
       for(int n=0;n<2;n++)
           
               printf("%c",gen_code[m][n]);
           
           printf("  ");
      }
 
   printf("\nBetter luck next time\n");
  }
}
    return 0;
}


void input(char user[4][2])
{
    char col_pos[2];
    int pos[20]={1,2,3,4} , c=4,row=0 ;
     
   
   
    printf("Enter the colour and position\n");
    for(int i=1;i<=4;i++)       //to accept the colour and position
    {
   
    scanf("%s",col_pos);
    pos[c]=col_pos[1];
    int count=1;
    for(int j=0;j<=c;j++)       //to check the number of times the same position is entered
    {
    if(pos[j]==col_pos[1])
    count++;
   
    }
    c++;
    if(count>2)         //to check if user entered same position twice
    {
    printf("OOPS! Same position cannot be entered twice\n");
    i--;
    //printf("%d",i);
    }
   
    else
    {
         
       for(int column=0;column<2;column++)      //to add user's entry into 2d array
           {
               user[row][column]=col_pos[column];
               
               
           }
           row++;
    }      
     
   
   
    }
   
}


void generation(char gen_code[4][2])
{
    int ran_no,row_code=0;
     
       
        char color[7]={'b','v','r','y','g','o','p'};
        for (int i=1;i<=4;i++)
        {
            ran_no=1+rand()%7;
           
            switch(ran_no)
            {
               
            case 1:
     
               gen_code[row_code][0]=color[0];
               gen_code[row_code][1]=i+'0';
           
           row_code++;
           
           break;
    case 2:
       
               
               gen_code[row_code][0]=color[1];
               gen_code[row_code][1]=i+'0';
           
           row_code++;
           
           break;
     case 3:
       
               
               gen_code[row_code][0]=color[2];
               gen_code[row_code][1]=i+'0';
           
           row_code++;
           
           break;
     case 4:
     
               gen_code[row_code][0]=color[3];
               gen_code[row_code][1]=i+'0';
           
           row_code++;
           
           break;
           
      case 5:
       
               gen_code[row_code][0]=color[4];
               gen_code[row_code][1]=i+'0';
           
           row_code++;
           
           break;
      case 6:
       
               gen_code[row_code][0]=color[5];
               gen_code[row_code][1]=i+'0';
           
           row_code++;
           
           break;
      case 7:
     
               gen_code[row_code][0]=color[6];
               gen_code[row_code][1]=i+'0';
           
           row_code++;
           
           break;
           
            }
        }
}


void check_r(char g[][2],char u[][2],int x,int *count)     //checking which row matches position of gen array
{
   for(int i=0;i<4;i++)
   {
       if(u[i][1]==x+'0')
       {
       
       match(i,g,u,x,count);  //position is checked here and match func is called to check if colour is also right
       }
   }
}


void match(int i2,char g[][2],char u[][2],int x2,int *count)         //generating red pin
{
    x2-=1;
    if(g[x2][0]==u[i2][0])
    {
        x2+=2;
        *count+=1;
        //printf("red\n");
       
        check_r(g,u,x2,count);  //to check next row of gen array
    }
   
    else
    {
    x2+=2;
    check_r(g,u,x2,count);  //to check next row of gen array
    }
}

void check_w(char g[][2],char u[][2],int *count)        //generating white pin
{
   
    char color[4];
    for(int i=0;i<4;i++)
    color[i]=g[i][0];
   //printf("\ncolor array %s\n",color);
    for(int x=0;x<4;x++)		//incrementing rows
    {
    for(int i=0;i<4;i++)	//traversing through colour array
    {
            if(u[x][0]==color[i])
           
            {
                *count+=1;
                color[i]='x';
            //printf("white\n");
	     break;
            }
           //printf("\ncolor array after %s\n",color);  
    }
}
}
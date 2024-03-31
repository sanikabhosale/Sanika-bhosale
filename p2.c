#include<stdio.h>
#include<string.h>
typedef struct Book{
	int bid;
	char name[30];
	char Author[40];
	char categery[40];
	double price;
	int rating;
}Book;
int ctr=0;

void hardCode(Book*);
void storeData(Book*,int);
void displayBook(Book*);
void searchBook(Book*);
int searchBookByName(Book*);
int searchBookById(Book*);
void searchBookByAuthor(Book*);
void searchBookByCategery(Book*);
void deleteBook(Book*);
void updateBook(Book*);
void updatePrice(Book*);
void updateRating(Book*);
void sortBook(Book*);
void sortPrice(Book*);
void sortRating(Book*);
void main()
{
	int ch;
	Book b[20];
	hardCode(b);
	do
	{
		
		printf("***MAIN MENU****");
		printf("\n1.add Book\n2.display Book \n3.search Book");
		printf("\n4.delete Book");
		printf("\n5.update Book");
		printf("\n6.sort Book");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				storeData(b,20);
				break;
			case 2:
				displayBook(b);
				break;
			case 3:
				searchBook(b);
				break;
			case 4:
				deleteBook(b);
				break;
			case 5:
				updateBook(b);
				break;
			case 6:
				sortBook(b);
				break;
			default:
				printf("Thank you");
		}	
		
	}while(ch!=0);
		
}
void hardCode(Book* b)
{
	
	b[ctr].bid=1;
	char bn[30]="c";
	strcpy(b[ctr].name,bn);
	char ba[30]="Dennis Ritchie";
	strcpy(b[ctr].Author,ba);
	char bc[30]="computer language";
	strcpy(b[ctr].categery,bc);
	b[ctr].price=300;
	b[ctr].rating=3;
	ctr++;
	
	b[ctr].bid=2;
	char bn1[30]="abc";
	strcpy(b[ctr].name,bn1);
	char ba1[30]="era";
	strcpy(b[ctr].Author,ba1);
	char bc1[30]="Horrer";
	strcpy(b[ctr].categery,bc1);
	b[ctr].price=200;
	b[ctr].rating=4;
	ctr++;
	
	
	b[ctr].bid=3;
	char bn2[30]="mplkj";
	strcpy(b[ctr].name,bn2);
	char ba2[30]="bregu";
	strcpy(b[ctr].Author,ba2);
	char bc2[30]="story";
	strcpy(b[ctr].categery,bc2);
	b[ctr].price=250;
	b[ctr].rating=5;
	ctr++;

	
	b[ctr].bid=4;
	char bn3[30]="kfhv";
	strcpy(b[ctr].name,bn3);
	char ba3[30]="bregu";
	strcpy(b[ctr].Author,ba3);
	char bc3[30]="story";
	strcpy(b[ctr].categery,bc3);
	b[ctr].price=250;
	b[ctr].rating=2;
	ctr++;

	
}
void storeData(Book* b,int n)
{
	if(ctr<=n)
	{
		printf("enter Book id:");
		scanf("%d",&b[ctr].bid);
		printf("Enter Book Name:");
		scanf("%s",b[ctr].name);
		printf("Enter Book Author:");
		scanf("%s",b[ctr].Author);
		printf("Enter Book categery:");
		scanf("%s",b[ctr].categery);
		printf("Enter Book price:");
		scanf("%lf",&b[ctr].price);
		printf("Enter Book rating:");
		scanf("%d",&b[ctr].rating);
		ctr++;
	}
}
void displayBook(Book* b)
{
	int i;
    printf("-----------------------------------------------------------------------------------------------------------\n");
	printf("Book ID|    Book Name     |Book Author          | Book categery         |Book price     |Book rating     |\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<ctr;i++)
	{
		printf("%-7d|%-18s|%-21s|%-15s\t|%-7lf\t|%-7d|\n",b[i].bid,b[i].name,b[i].Author,b[i].categery,b[i].price,b[i].rating);
	}
	
}
void searchBook(Book* b)
{
	int search;
	int si,sn,sa,i;
	
	do{
		printf("\n-1.search by Book id\n-2.search by Name\n-3search by Author Name\n-4.search book Categery\n-5Main Menu\n");
		scanf("%d",&search);
		switch(search)
		{
		    case -1:
				si=searchBookById(b);
				if(si==-1)
				{
				 	printf("Book not faund\n");
				}
				else
				{
				   printf("-----------------------------------------------------------------------------------------------------------\n");
	               printf("Book ID|    Book Name     |Book Author          | Book categery         |Book price     |Book rating     |\n");
                   printf("-----------------------------------------------------------------------------------------------------------\n");
		           printf("%-7d|%-18s|%-21s|%-15s\t|%-7lf\t|%-7d|\n",b[si].bid,b[si].name,b[si].Author,b[si].categery,b[si].price,b[si].rating);
			    }
				break;
			case -2:
				sn=searchBookByName(b);	
				if(sn==-1)
				{
				 	printf("Book not faund\n");
				}
				else
				{
				   printf("-----------------------------------------------------------------------------------------------------------\n");
	               printf("Book ID|    Book Name     |Book Author          | Book categery         |Book price     |Book rating   |\n");
                   printf("-----------------------------------------------------------------------------------------------------------\n");
		           printf("%-7d|%-18s|%-21s|%-15s\t|%-7lf\t|%-7d|\n",b[sn].bid,b[sn].name,b[sn].Author,b[sn].categery,b[sn].price,b[sn].rating);
			    }
				break;
			case -3:
				searchBookByAuthor(b);
	
				break;
				
			case -4:
				searchBookByCategery(b);
	
				break;
				
			default:
				printf("Envalid choice");
		
		}
		
	}while(search!=-5);
}
int searchBookByName(Book* b)
{
	int i=0,f=0;
	char n[30];
	printf("enter search Book name=");
	scanf("%s",n);
	for(i=0;i<ctr;i++)
	{
		if(strcmp(b[i].name,n)==0)
		{
		 return i;		
		}
	}
	return -1;
	
}
void searchBookByAuthor(Book* b)
{
	int i=0,f=0;
	char n[40];
	printf("enter search Book Author name=");
	scanf("%s",n);
	for(i=0;i<ctr;i++)
	{
		if(strcmp(b[i].Author,n)==0)
		{	
		// return i;
		if(f==1)
		{
		 	printf("%-7d|%-18s|%-21s|%-15s\t|%-7lf\t|%-7d|\n",b[i].bid,b[i].name,b[i].Author,b[i].categery,b[i].price,b[i].rating);
		}
		else
		{
		f=1;
		printf("-----------------------------------------------------------------------------------------------------------\n");
	    printf("Book ID|    Book Name     |Book Author          | Book categery         |Book price     |Book rating    |\n");
        printf("-----------------------------------------------------------------------------------------------------------\n");
        printf("%-7d|%-18s|%-21s|%-15s\t|%-7lf\t|%-7d|\n",b[i].bid,b[i].name,b[i].Author,b[i].categery,b[i].price,b[i].rating);	
        }
		}
	}
	//return -1;
	if(f==0)
	{
		printf("Author not faund\n");
	}
	
}
void searchBookByCategery(Book* b)
{
	int i=0,f=0;
	char n[40];
	printf("enter search Book categery =");
	scanf("%s",n);
	for(i=0;i<ctr;i++)
	{
		if(strcmp(b[i].categery,n)==0)
		{	
		// return i;
			if(f==1)
			{
		 	printf("%-7d|%-18s|%-21s|%-15s\t|%-7lf\t|%-7d|\n",b[i].bid,b[i].name,b[i].Author,b[i].categery,b[i].price,b[i].rating);
			}
			else
			{
			f=1;
			printf("-----------------------------------------------------------------------------------------------------------\n");
	    	printf("Book ID|    Book Name     |Book Author          | Book categery         |Book price     |Book rating|\n");
        	printf("-----------------------------------------------------------------------------------------------------------\n");
        	printf("%-7d|%-18s|%-21s|%-15s\t|%-7lf\t|%-7d|\n",b[i].bid,b[i].name,b[i].Author,b[i].categery,b[i].price,b[i].rating);	
        	}
		}
	}
	//return -1;
	if(f==0)
		printf("Author not faund\n");
	
}
int searchBookById(Book* b)
{
	int i,f=0;
	int n;
	printf("enter search Book Id=");
	scanf("%d",&n);
	for(i=0;i<ctr;i++)
	{
		if(b[i].bid==n)
		{
		 return i;	
		}
	}
	return -1;
	
}
void deleteBook(Book* b)
{
	int i,f=0;
	char n[30];   //book name
	printf("enter search Book name=");
	scanf("%s",n);
	for(i=0;i<ctr;i++)
	{
		if(strcmp(b[i].name,n)==0)
		{
			f=1;
			b[i]=b[i+1];
			ctr=ctr-1;
				
		}
		else if(f==1)
		{
			b[i]=b[i+1];
		}
		
	}
	if(f==0)
	{
		printf("player not faund\n");
	} 
	displayBook(b);  
}
void updateBook(Book* b)
{
	int update;
	
	do{
		printf("\n-1.upadate price\n-2.update rating\n-3.Main Menu\n");
		scanf("%d",&update);
		switch(update)
		{
			case -1:
				updatePrice(b);
				break;
			case -2:
				updateRating(b);
				break;
			default:
				printf("Envalid choice");

		}
		
	}while(update!=-3);
	
}
void updatePrice(Book* b)
{
	int i,c;
	double p;
	char n[30];
	printf("enter Book name you want you update:");
	scanf("%s",n);
	printf("enter new Book price:");
	scanf("%lf",&p);
	
	for(i=0;i<ctr;i++)
    {
     if(strcmp(b[i].name,n)==0)	
     {
     	b[i].price=p;
	 }
	}
	displayBook(b);  
}
void updateRating(Book* b)
{
	int i,c;
	char n[30];
	printf("enter Book name you want you update:");
	scanf("%s",n);
	printf("enter new Book rating:");
	scanf("%d",&c);
	
	for(i=0;i<ctr;i++)
    {
     if(strcmp(b[i].name,n)==0)	
     {
     	b[i].rating=c;
	 }
	}
	displayBook(b);  
}	
void sortBook(Book* b)
{
	int sort;
	
	do{
		printf("\n-1.sort price\n-2.sort rating\n-3.Main Menu\n");
		scanf("%d",&sort);
		switch(sort)
		{
			case -1:
				sortPrice(b);
				break;
			case -2:
				sortRating(b);
				break;
			default:
				printf("Envalid choice");

		}
		
	}while(sort!=-3);
}
void sortPrice(Book* b)
{
	Book b2[ctr];
	int k;
	for(k=0;k<ctr;k++)
	{
		b2[k]=b[k];
	}
	int i,j,f=0;
	Book b1;
	for(i=0;i<ctr;i++)
	{
		for(j=i+1;j<ctr;j++)
		{
			if((b2[i].price)>(b2[j].price))
		    {
			  b1=b2[i];
		      b2[i]=b2[j];
			  b2[j]=b1;
		    }
		}
		
	}
	displayBook(b2);  
}
void sortRating(Book* b)
{
	Book b2[ctr];
	int k;
	for(k=0;k<ctr;k++)
	{
		b2[k]=b[k];
	}
	int i,j,f=0;
	Book b1;
	for(i=0;i<ctr;i++)
	{
		for(j=i+1;j<ctr;j++)
		{
			if((b2[i].rating)>(b2[j].rating))
		    {
			  b1=b2[i];
		      b2[i]=b2[j];
			  b2[j]=b1;
		    }
		}
		
	}
	displayBook(b2);  
}
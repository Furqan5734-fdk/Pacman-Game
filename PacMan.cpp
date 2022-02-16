#include<iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
	string Grid[25][22];
	int x,y;
	int n=3,m=2;
	char move;
	int score=0;
	
	// Storage of the map
	
	for(x=0; x<25; x++)
	{
		for(y=0; y<22; y++)
		{
		cout<<Grid[x][y];	
		}
	}
	
	// Designing the map
	
		for(x=0; x<25; x++)
		{
			for(y=0; y<22; y++)
			{
				if(x==0 || x==24)
				{
					Grid[x][y]="#";
				}
				else if(y==0 || y==21)
				{
					Grid[x][y]="#";
				}
				////////////x axis
				else if(x>2 && y==3 && x<8)
				{
					Grid[x][y]="#";
				}
				///////yaxis
				else if(y>3 && x==7 && y<8)
				{
					Grid[x][y]="#";
				}
				
				//////xaxis
				else if(x>15 && y==3 && x<21)
				{
					Grid[x][y]="#";
				}
				
				//yaxis
				else if(y>3 && x==20 && y<19)
				{
					Grid[x][y]="#";
				}
				else if(x>15 && y==18 && x<20)
				{
					Grid[x][y]="#";
				}
				
				else if(x>2 && y==18 && x<8)
				{
					Grid[x][y]="#";
				}
				
				
				else if(y>13 && x==7 && y<19)
				{
					Grid[x][y]="#";
				}
				
				
				else if(y>6 && x==12 && y<15)
				{
					Grid[x][y]="#";
				}
				
				else
				{
					Grid[15][20]="O";
					Grid[x][y]=".";	
				}		
			}
		}
	
	// Printing the map
	
	
	//GHOST PRINTING RANDOMLY
	
	
	int movecount=0;
	Grid[n][m]="@";
	cout<<" Score: "<<score<<endl;
	cout<<" Moves: "<<movecount<<endl;
	
		int x_axis=2 ,y_axis=15;
		Grid[x_axis][y_axis]="&";
		
	cout<<endl;
		for(x=0; x<25; x++)
		{
			for(y=0; y<22; y++)
			{
				cout<<Grid[x][y]<<" ";	
			}
		cout<<endl;
		}
		
//		srand(time(0));
//		int num1=(rand() % 25) + 1 , num2=(rand() % 25) + 1; 
//		
	
		
		while(true)
		{
			
	
		cout<<"---------------------------------------"<<endl;	
		cout<<"Enter Move: ";
		cin>>move;
		
			
			
		  movecount++;
	  	
	  	
		if(move=='s')
		{
			n++;
			
			if(n>0)
		{
		Grid[n-1][m]=" ";	
		}	
		}
		
		
		if(move=='w')
		{
		n--;
		if(n>0)
		{
		Grid[n+1][m]=" ";	
		}	
		}
		
		
		if(move=='a')
		{
		m--;
		if(m>0)
		{
		Grid[n][m+1]=" ";	
		}	
		}
		
		if(move=='d')
		{
		m++;
		if(m>0)
		{
		Grid[n][m-1]=" ";	
		}	
		}
		
		
		if(Grid[n][m]=="O")
		{
		cout<<"\nFinish"<<endl;
		cout<<"Score: "<<score<<endl;
		cout<<"Total Moves: "<<movecount<<endl;
		cout<<endl;
		break;	
		}
		if(Grid[n][m]=="#")
		{
		cout<<"\nGame is Over"<<endl;
		cout<<"Score: "<<score<<endl;
		cout<<"Total Moves: "<<movecount<<endl;
		cout<<endl;
		break;	
		}
		if(Grid[n][m]==".")
		{
		score+=1;	
		}
		Grid[n][m]="@";
		cout<<"Score: "<<score<<endl;
		cout<<"Total Moves: "<<movecount<<endl;
		cout<<endl;
		for(x=0; x<25; x++)
		{
			for(y=0; y<22; y++)
			{
			cout<<Grid[x][y]<<" ";	
			}
		cout<<endl;
		}
			
		Grid[x_axis][y_axis]=".";
		
		here:
			srand(time(0));
			int num=(rand() % 4) + 1; 
		
		if(num==1)
		{
			if(Grid[x_axis][y_axis-1]=="#")
			goto here;
			
			Grid[x_axis][y_axis-=1]="&";
				
		}
		if(num==2)
		{	
		
			if(Grid[x_axis][y_axis+1]=="#")
			goto here;
			
			Grid[x_axis][y_axis+=1]="&";	
		}
		if(num==3)
		{
			if(Grid[x_axis-1][y_axis]=="#")
			goto here;
			
			Grid[x_axis-=1][y_axis]="&";	
		}
		if(num==4)
		{
			if(Grid[x_axis+1][y_axis]=="#")
			goto here;
			
			Grid[x_axis+=1][y_axis]="&";	
		}
		
		
		if(Grid[x_axis][y_axis]==Grid[n][m])
		{
			Grid[x_axis][y_axis]=".";
			Grid[n][m]="&";
		cout<<"\nGame is Over"<<endl;
		cout<<"Score: "<<score<<endl;
		cout<<"Total Moves: "<<movecount<<endl;
		cout<<endl;
		break;	
		}
			
		}
		
	return 0;
}

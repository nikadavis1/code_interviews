/*This program takes in directions N=North, S=South, E=East, W=West from 
a file. The program takes in users input and compares the user's directions
to the file's direction. If the user's dirction correspones with the file's direction
than the program will output an x following the path of the direction in the file. */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAPSIZE 10
char MapFilename[500]= {};




struct PlayerInfo				//This data structure will contain the players name
{								//the curretn row and column of the path
	char PlayerName[20];
	int CurrentRow;
	int CurrentCol;
};


int MoveNorth(char [][MAPSIZE],struct PlayerInfo *Playptr);		//These varibles will hold the direction from the file
int MoveSouth(char [][MAPSIZE],struct PlayerInfo *Playptr);		//and the player's information
int MoveEast(char [][MAPSIZE],struct PlayerInfo *Playptr);
int MoveWest(char [][MAPSIZE],struct PlayerInfo *Playptr);
void get_command_line_params(int argc, char *argv[]);

int MoveNorth(char Map[][MAPSIZE], struct PlayerInfo *Playptr)	 //This function will move the x up north, 
{																 //if the user's input is N
	if(Map[Playptr->CurrentRow-1][Playptr->CurrentCol]=='S' || Map[Playptr->CurrentRow-1][Playptr->CurrentCol]=='E' || Map[Playptr->CurrentRow-1][Playptr->CurrentCol]=='X' )
	{
		Playptr->CurrentRow--;
		return 1;
	}
	else{									//print warning statement 
	printf("North is the wrong move\n");
	return 0;
	}

}

int MoveSouth(char Map[][MAPSIZE], struct PlayerInfo *Playptr)    //This function will move the x down south, 
{																  //if the user's input is S
	if(Map[Playptr->CurrentRow+1][Playptr->CurrentCol]=='S' || Map[Playptr->CurrentRow+1][Playptr->CurrentCol]=='E' || Map[Playptr->CurrentRow+1][Playptr->CurrentCol]=='X' )
	{
		Playptr->CurrentRow++;
		return 1;
	}
	else{									
		printf("South is the wrong move\n");
		return 0;
	}
}

int MoveWest(char Map[][MAPSIZE], struct PlayerInfo *Playptr)        //This fucntion will move the x left west,
{																	 //if the user's input is W
		if(Map[Playptr->CurrentRow][Playptr->CurrentCol-1]=='S' || Map[Playptr->CurrentRow][Playptr->CurrentCol-1]=='E' || Map[Playptr->CurrentRow][Playptr->CurrentCol-1]=='X' )
	{
		Playptr->CurrentCol--;
		return 1;
	}
	else{
		printf("West is the wrong move\n");
		return 0;
	}
}

int MoveEast(char Map[][MAPSIZE], struct PlayerInfo *Playptr)     //This function will move the x right,
{																  //if the user's input is E
		if(Map[Playptr->CurrentRow][Playptr->CurrentCol+1]=='S' || Map[Playptr->CurrentRow][Playptr->CurrentCol+1]=='E' || Map[Playptr->CurrentRow][Playptr->CurrentCol+1]=='X' )
	{
		Playptr->CurrentCol++;
		return 1;
	}
	else{
		printf("East is the wrong move\n");
		return 0;
		}
}




void get_command_line_params(int argc, char *argv[])  //This function reads in from the Map file
{
	int i;

	for (i=0; i < argc; i++)
	{
	if(!memcmp(*(argv+i),"MAP=",4))
		{
			memcpy(MapFilename,(strchr(*(argv+i),'=')+1),500);
		}
	
	}
	if(MapFilename==NULL)
		{
		printf("MAP= must be given on the command line\n");
		exit(0);
		}

	
}





int main(int argc, char *argv[])
{
FILE *TreasureMap;
char MapList[500];
char Map[MAPSIZE][MAPSIZE];
char PlayerPath[MAPSIZE][MAPSIZE];
char PlayerMove;
int i,j,k;
int MakeMove;
struct PlayerInfo Player;
struct PlayerInfo *PlayerPtr;
PlayerPtr=&Player;

get_command_line_params(argc, argv);
TreasureMap=fopen(MapFilename,"r+");

if(TreasureMap==NULL)
{
	perror("TreasureMap did not open");
	exit(0);
}

printf("Enter Player name\n");
scanf("%s",Player.PlayerName);
getchar();

Player.CurrentRow=0;
Player.CurrentCol=0;

fgets(MapList,500,TreasureMap);
i=0;


for(j=0; j < MAPSIZE; j++)
{
		for(k=0; k < MAPSIZE; k++)
		{
			Map[j][k]=MapList[i];
			printf("%c ",Map[j][k]);
			i++;
			PlayerPath[j][k]='-';
		}
		printf("\n");
}

printf("Press <Enter> when you are ready to start\n");
getchar();
system("clear");
PlayerPath[0][0]=Map[0][0];

do
{
	
	printf("Enter a direction (NSEW) or 'Q' to quit\n");
	scanf("%c",&PlayerMove);
	getchar();
	PlayerMove=toupper(PlayerMove);
	system("clear");

	if(PlayerMove=='N')
	{
		MakeMove=MoveNorth(Map,PlayerPtr);
	}
	else if(PlayerMove=='S')
	{
		MakeMove=MoveSouth(Map,PlayerPtr);
	}
	else if(PlayerMove=='W')
	{
		MakeMove=MoveWest(Map,PlayerPtr);
	}
	else if(PlayerMove=='E')
	{
		MakeMove=MoveEast(Map,PlayerPtr);
	}

	
	else{
		printf("Invalid move- must be NSEW\n");
		MakeMove==0;
	
	}

	if(MakeMove==1)
	{
		if(Map[Player.CurrentRow][Player.CurrentCol]=='S')
		{
			printf("You are at the start\n");
		}
		else if(Map[Player.CurrentRow][Player.CurrentCol]=='E')
		{
			PlayerPath[Player.CurrentRow][Player.CurrentCol]='E';
			printf("Congratulation %s you have made it to the end\n",Player.PlayerName);
			
		}
		else if(Map[Player.CurrentRow][Player.CurrentCol]=='X')
		{
			PlayerPath[Player.CurrentRow][Player.CurrentCol]='X';
		}
	
	}
	
	for(j=0; j < MAPSIZE; j++)
	{
		for(k=0; k < MAPSIZE; k++)
		{
			printf("%c  ",PlayerPath[j][k]);
				
		}
		printf("\n");
	}

}
	while(PlayerMove!='Q');
	{
	fclose(TreasureMap);
	exit(0);
	}
	
}

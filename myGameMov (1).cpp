// create game 

#include<iostream>
#include<windows.h>

using namespace std;



void checkWin();
void gameOver();
void gameContinue();
void resetPos(); //knows what level through while switches
void menuReturn();
void howToPlay();
void about();
void gameUp(); //To next level, sets current level loop to false



char menu[6][20] = 
		{
			"-------------------",
			"PLAY              <",
			"HOW TO PLAY        ",
			"ABOUT              ",
			"EXIT               ",
			"-------------------",	
		};

char map[10][30	] = {
	"###################",
	"#@                #",
	"#                 #",
	"#          r      #",
	"#       r       r #",
	"#       r         #",
	"#     r           #",
	"#         r       #",
	"#                   EXIT",
	"###################",
	
	
};

char map2[30][50] = {
	"###################################",
	"#        *                         #",
	"#        *                         #",
	"#    *  *  * *                     #",
	"#     *          *****             #",
	"#       ****                       #",
	"#       *     ***                   #",
	"#     l                            #",
	"#    l     *           *****        #",
	"#   l              *****            #",
	"#  l                               #",
	"#  l                           ",
	"#  l                               ",
	"#  l         * * * * %)             ",
	"#  * * * * * *  EXIT     *           ",
	"###################################",
	
};

int X = 1;
int Y = 1;

int enemyY = 5;
int enemyX = 5;



bool gameRunning = true;
bool menuRunning = true;
bool isOne = true;
bool isTwo = true;

int menuY = 1;
int menuX = 18;

int main()
{
	while(menuRunning)
	{
		system("cls");
		
		cout << "\n\n\t\tEzra's Game\n\n";
		
		
		
		for(int g = 0; g < 6; g++)
		{
			cout << "\t\t" <<  menu[g] << endl;
		}
		
		system("pause > nul");
	
		 if(GetAsyncKeyState(VK_UP))
		{
			int menuY2 = menuY-1;
			
			if(menu[menuY2][menuX] != '-')
			{
				menu[menuY][menuX] = ' ';
				menuY--;
				menu[menuY][menuX] = '<'; 
			}
		
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			int menuY2 = menuY+1;
			
			if(menu[menuY2][menuX] != '-')
			{
				menu[menuY][menuX] = ' ';
				menuY++;
				menu[menuY][menuX] = '<'; 
			}
		
		}
		
		else if(GetAsyncKeyState(VK_RETURN))
		{

			
			if(menuY == 1)
			{
				menuRunning = false;
			}
			else if(menuY == 2)
			{
				howToPlay();
			}
			else if(menuY == 3)
			{
				about();
			}
			else if(menuY == 4)
			{
				menuRunning = false;
				gameRunning = false;
				system("cls");
				cout << "\n\n\n\n\t\t\tGoodbye!\n";

			}
		}
		
	}
		
	while(gameRunning)
	{
		//display Menu
		while(isOne)
		{
		
			system("cls"); //refreshes screen after every loop so doesn't scroll;
			cout << "\t\t\t\tLEVEL 1\n\n";
	
			for(int display = 0; display < 10; display++)
			{
				
				cout << "\t\t\t" <<  map[display] << endl;
	
			}


		
			system("pause > nul"); //lets user only one input per loop (so one down press doesn't equal 3)
		
			if(GetAsyncKeyState(VK_ESCAPE))
			{
				gameOver();
				gameContinue();
			}
		
			if(GetAsyncKeyState(VK_UP))
			{
				int y2 = Y-1; //+1 means down 1 because way array is initialized

				if(map[y2][X] == ' ') //if space in in char down 1
				{
					map[Y][X] = ' '; //previous space now empty
					Y--; 
					map[Y][X] = '@';
				}
			
				else
				{
					gameOver();
					gameContinue();
				
				} 


			}
		
			if(GetAsyncKeyState(VK_DOWN))
			{
				int y2 = Y+1; //+1 means down 1 because way array is initialized

				if(map[y2][X] == ' ') //if space in in char down 1
				{
					map[Y][X] = ' '; //previous space now empty
					Y++; 
					map[Y][X] = '@';

				}
				else
				{
					gameOver();
					gameContinue();	
				} 


			}

			if(GetAsyncKeyState(VK_RIGHT))
			{
				int x2 = X+1;
				if(map[Y][x2] == ' ')
				{
					map[Y][X] = ' ';
					X++;
					map[Y][X] = '@';
				}
				else
				{
					gameOver();
					gameContinue();
				}


			}
		
			if(GetAsyncKeyState(VK_LEFT))
			{	
				int x2 = X-1;
				if(map[Y][x2] == ' ')
				{
					map[Y][X] = ' ';
					X--;
					map[Y][X] = '@';
				}
				else
				{
					gameOver();
					gameContinue();
				}
			

			}

		
			checkWin();
		}//end level 1
		
	
		bool goRight = true; //for enemy
		bool goLeft = false; //keeps going left even if space on right

		while(isTwo)
		{
	
	
			system("cls"); //refreshes screen after every loop so doesn't scroll; local scope
	
			cout << "\t\t\t\tLEVEL 2\n\n";
	
			for(int display = 0; display < 15; display++)
			{
				cout << "\t\t\t" <<  map2[display] << endl;
	
			}



 //lets user only one input per 		
		
			if(GetAsyncKeyState(VK_ESCAPE))
			{
				 //after input game pauses waiting for more.
				gameOver();
				gameContinue();
			}
		
			if(GetAsyncKeyState(VK_UP))
			{
				
				int y2 = Y-1; //+1 means down 1 because way array is initialized

				if(map2[y2][X] == ' ') //if space in in char down 1
				{
					map2[Y][X] = ' '; //previous space now empty
					Y--; 
					map2[Y][X] = '@';
				}
			
				else
				{
					gameOver();
					gameContinue();
				
				} 


			}
		
			if(GetAsyncKeyState(VK_DOWN))
			{
	
				int y2 = Y+1; //+1 means down 1 because way array is initialized

				if(map2[y2][X] == ' ') //if space in in char down 1
				{
					map2[Y][X] = ' '; //previous space now empty
					Y++; 
					map2[Y][X] = '@';

				}
				else
				{
					gameOver();
					gameContinue();	
				} 


			}

			if(GetAsyncKeyState(VK_RIGHT))
			{
		
				int x2 = X+1;
				if(map2[Y][x2] == ' ')
				{
					map2[Y][X] = ' ';
					X++;
					map2[Y][X] = '@';
				}
				else
				{
					gameOver();
					gameContinue();
				}


			}
		
			if(GetAsyncKeyState(VK_LEFT))
			{	
		
				int x2 = X-1;
				if(map2[Y][x2] == ' ')
				{
					map2[Y][X] = ' ';
					X--;
					map2[Y][X] = '@';
				}
				else
				{
					gameOver();
					gameContinue();
				}
			

			}
			

			if(goLeft)
			{
				int enemyX2 = enemyX-1;
				if(map2[enemyY][enemyX2] == ' ')
				{
					map2[enemyY][enemyX] = ' ';
					enemyX--;
					map2[enemyY][enemyX] = 'S';
				}
				else if(map2[enemyY][enemyX2] == '@')
				{
				
					gameOver();
					gameContinue();
				}
				else
				{
					goLeft = false;
					goRight = true;
				}
			}
			else if(goRight) //confirms keep going right even if space left
			{

				int enemyX2 = enemyX+1;
				if(map2[enemyY][enemyX2] == ' ')
				{
					map2[enemyY][enemyX] = ' ';
					enemyX++;
					map2[enemyY][enemyX] = 'S';	
				}
				else if(map2[enemyY][enemyX2] == '@')
				{
					gameOver();
					gameContinue();
				}
				else
				{
			 		goLeft = true;
			 		goRight = false;
				}
			
			}
			
		
				
			
			
			
			
			
			checkWin();
		}//end isTwo
		cin.get();
	} //end gameRunning
	
	return 0;

} //end main

void gameOver()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << "\t\t\tGAME OVER\n";

}

void resetPos()
{
	if(isOne)
	{
		map[Y][X] = ' ';
		X = 1;
		Y = 1;
		map[1][1] = '@';
	}
	else if(isTwo)
	{
		map2[Y][X] = ' ';
		X = 1;
		Y = 1;
		map2[Y][X] = '@';
		map2[enemyY][enemyX] = ' ';
		enemyX = 5;
		enemyY = 5;
		map2[enemyY][enemyX] = 'S';

	}
	
}

void gameContinue()
{
	char ch = ' ';
	cout << "\t\tDo you want to keep playing?(y/n): ";
	
	cin >> ch;

	while(ch != 'N' && ch != 'n' && ch != 'Y' && ch != 'y')
	{
		cout << endl;
		cout << "\t\tEnter either a 'y' or 'n': ";
		cin >> ch;
		
	}
	if(ch == 'n' || ch == 'N')
	{
		system("cls");
		gameRunning = false;
		isOne = false;
		isTwo = false;
		cout << "\n\n\n\n\t\t\tGoodbye!";
	}
	else
	{
		resetPos();
		
		
	}
	
	
	
}

void gameUp()
{
	if(isOne == true)
	{
		isOne = false;
	}
	else if(isTwo == true)
	{
		isTwo = false;
	}
	resetPos();
}

void checkWin()
{
	if( isOne==true && Y == 8 && X == 19)
	{
		system("cls");
		cout << "\n\n\n\t\t\tlevel cleared!\n\n";
		cin.get();
		gameUp();

	}
	else if( isTwo == true && Y ==14 && X == 20)
	{
		system("cls");
		cout << "\n\n\n\t\t\tlevel cleared!\n\n";
		cin.get();
		gameUp();
	}
		
	
}

void menuReturn()
{
	char ch = ' ';
	
	cout << "\n\t\t";
	cout << "Press [Enter] to return...";
	cin.get(ch);
	menu[menuY][menuX] = ' ';
	menuY = 1;
	menu[menuY][menuX] = '<';
		
	
}

void howToPlay()
{
	system("cls");
	cout << "\n\n\tThanks for choosing my game!\n\n";
	cout << "\tThe @ represents your character.\n";
	cout << "\tUse the arrow keys to move your character.\n";
	cout << "\tPress [ESC] to exit the game.\n";
	cout << "\tCareful! avoid any letters or symbols you see.\n";
	cout << "\tGet to the EXIT to clear the level.\n\n";
	cout << "\t";
	menuReturn();
}

void about()
{
	system("cls");
	cout <<"\n\n\tThis is my first movement based game!";
	cout << "\n\tI hope you enjoy it as much as I enjoyed making it!\n\n";
	cout << "\t";
	menuReturn(); 
}






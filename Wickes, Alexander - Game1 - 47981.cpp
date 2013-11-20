//Wickes, Alexander, 1st game project, 10/25/13
//Hl HO! CHERRY-O® gameboard with spinner
//4 Different-colored buckets, 40 Cherries
//Object:To be the first player to pick 10 cherries from your tree and fill your bucket.
//Assembly and Setup
//1. Assemble the spinner as shown below.
//A. Break out the arrow and spinner base.
//B. Insert base through hole as shown.
//C. Snap together arrow and spinner base.
//2. Each player chooses a tree and places 10 cherries on it.
//3. The youngest player goes first. Play passes to the left.
//Game Play
//In turn, each player spins and plays according to his/her spin:
//One Cherry:Pick one cherry from your tree and put it into your bucket.
//Two Cherries: Pick two cherries from your tree and put them into your bucket.
//Three Cherries: Pick three cherries from your tree and put them into your bucket.
//Four Cherries:Pick four cherries from your tree and put them into your bucket.
//Bird or Dog:Take two cherries from your bucket and place them back on
//your tree. (If you have only one cherry, put that one back. If you have
//none do nothing.)
//Spilled Bucket:Dump the cherries out of your bucket, place them back on your 
//tree and start over.
//Winning:You win if you're the first player to call, "Hi Ho! CherryO!" indicating
//that you have 10 cherries in your bucket.
#include<iostream>
#include<string>
#include <windows.h>  //needed for sleep functions						
#include<ctime> //time for random number generator
using namespace std;
void Spin(int&); // function spin 
void Spin(int& spinner)//before spin
{						
  srand(time(NULL));// after spin		
  spinner=rand()%7+1;//random number between 1 and 7 like game spinner
}
int main()
{
char again;// play again
    do{ //do / while to play another game
string anykey; //press any key to spin
int cherry[4];// player buckets
int i=0;
int winner, num, spinner;//keep running until a winner, define number of players
//and random number of 1 to 7 for spinner	
    cout<<"Welcome to Hi Ho! CherryO!"<<endl;
    Sleep(3000);   // 3 sec in milliseconds 1Sec = 1000 MiliSeconds, from window lib 
    cout<<"Up to 4 players!"<<endl;
    Sleep(3000);   // 3 sec in milliseconds 1Sec = 1000 MiliSeconds, from window lib
    cout<<"Lets Play "<<endl;
    Sleep(3000);   // 3 sec in milliseconds 1Sec = 1000 MiliSeconds, from window lib
    system("CLS");//cout << string(50, '\n'); //clear the screen
						// "win" decides whether the program should continue or not
   //  **string answer;						// "answer" has the user input something to continue
   
   cout<<"Enter the number of players (2 to 4)."<<endl;
   cin>>num;	
   	//start with 0 cherrys to begin with
   for (i=0;i<num+1;i++){
    cherry[i]=0;
   }
  cout<<"All cherry buckets are currently empty."<<endl;
   winner=1;
//keep the loop going until there is a winner
   while(winner==1)						
   {// give each player a turn
   for (i=1;i<=num;i++)            			
      { //end the game if there is a winner
   if (cherry[1]<10||cherry[2]<10||cherry[3]<10||cherry[4]<10)//run until
   //there is a winner
        {
        cout<<"Player "<<i<<" type press anykey and enter to spin."<<endl;
        cin>>anykey; //anykey to spin
           Spin(spinner);//call spin function

          cherry[i]=cherry[i]+spinner;//add cherrries to bucket
          cout<<"Player "<<i<<" spun a "<<spinner<<". "<<endl;// spin results
          cout<<" "<<endl; //row
          if(cherry[i]>10)
          {
          cherry[i]=10;
          }
          cout<<" "<<endl; //row
// 7 if's for 7 positions on the spinner per game instructions above
         if (cherry[i]==1){
              cout<<"Pick one cherry from your tree and put it into your bucket."<<endl;
              cherry[i]=1;
          }
          else if (cherry[i]==2){  
              cout<<"Pick two cherries from your tree and put them into your bucket."<<endl;
              cherry[i]=2;
          } 
          else if (cherry[i]==3){  
              cout<<"Pick three cherries from your tree and put them into your bucket."<<endl;
              cherry[i]=3;
          }
          else if (cherry[i]==4){  
              cout<<"Pick four cherries from your tree and put them into your bucket."<<endl;
              cherry[i]=4;
          } 
          else if (cherry[i]==5){  
              cout<<"A bird took two cherries from your bucket and placed them back on the tree."<<endl;
              cherry[i]=-2;}
          else if (cherry[i]==6){  
              cout<<"A dog took two cherries from your bucket and placed them back on the tree."<<endl;
              cherry[i]=-2;
          } 
          else if (cherry[i]==7){  
              cout<<"Your bucket was knocked over. All your cherrys go back to the tree."<<endl;
              cherry[i]=0;
              }
           cout<<" "<<endl; //row
           //tell players what contents are in the bucket
              cout<<"You now have "<<cherry[i]<<" cherries in your bucket."<<endl;
          if (cherry[i]>=10){ // tell a play when they win, yell Hi ho CherryO!
              cout<<"Player "<<i<<" Hi Ho! CherryO!"<<endl;
              Sleep(500);   // 1/2 sec in milliseconds 1Sec = 1000 MiliSeconds, from window lib
              cout<<"Your a winner!"<<endl;
              winner=2; 
          }
         if (cherry[i]>=10){
             cherry[i]=10;
         }}}} //end if, for, while
        cout<<"  \n";   //row
         cout << "Would you like to try again?(y/n)\n";// play again?
    cin >> again;
    } while (again =='y' || again =='Y');
    
    cout << "good-bye\n";           

    return 0;
}	

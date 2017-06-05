#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define in insert
#define pb push_back
#define all(a) a.begin(),a.end()
#define pf push_front
#define pob pop_back
#define pof pop_front
#define bitcnt(x) __builtin_popcountll(x)
typedef long long int ll;typedef long int l;typedef pair<int,int> pii;
const ll INF=(1<<28);
const ll MOD=(1e9+7);
char arr[3][3];
bool win,deadlock;

int generate_board()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<arr[i][j]<<"\t";		//to print the matrix
		}
		cout<<'\n';
	}
return 0;
}
int initialize()		//initialize for each test case
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){	arr[i][j]='E';
		}
	}
return 0;
}
//a function to check winning after the 4th move
bool check_for_win()
{
	if((arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2]) && arr[2][2]!='E')	return true;
	if((arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2]) && arr[0][2]!='E')	return true;
	if((arr[0][0]==arr[0][1] && arr[0][1]==arr[0][2]) && arr[0][2]!='E')	return true;
	if((arr[1][0]==arr[1][1] && arr[1][1]==arr[1][2]) && arr[1][2]!='E')	return true;
	if((arr[2][0]==arr[2][1] && arr[2][1]==arr[2][2]) && arr[2][2]!='E')	return true;
	if((arr[0][0]==arr[1][0] && arr[1][0]==arr[2][0]) && arr[2][0]!='E')	return true;
	if((arr[0][1]==arr[1][1] && arr[1][1]==arr[2][1]) && arr[2][1]!='E')	return true;
	if((arr[0][2]==arr[1][2] && arr[1][2]==arr[2][2]) && arr[2][2]!='E')	return true;
	return false;
}


int main()
{
   // ios_base::sync_with_stdio(false);cin.tie(NULL);
    while(true)
    {
    	int ready;
    	cout<<"Are you two ready to play?"<<'\n';cout<<"1) Yes	2)No"<<'\n';
    	cout<<"Press 1 for yes and 2 for No"<<'\n';
    	cin>>ready;
    	win=false;deadlock=false;
    	if(ready==2){	cout<<"Thank You"<<'\n';	return 0;	}
    	else if(ready==1)
    	{
    		string player1,player2;
    		cout<<"Enter the name of first player:"<<" ";
    		cin>>player1;
			cout<<"Enter the name of second player:"<<" ";
			cin>>player2;
    		initialize();
    		cout<<player1<<"'s move will be marked by X while"<<" "<<player2<<"'s move will be marked by 0"<<"\n"<<"Lets Go"<<'\n';
			for(int i=1;i<=9;i++)
			{
				cout<<'\n';
				generate_board();
				string winner;
				int row_num,col_num;
				if(i%2!=0)
				{
					cout<<'\n';
					cout<<player1<<", Which row?"<<'\t';cin>>row_num;
					cout<<'\n';
					cout<<player1<<", Which column?"<<'\t';cin>>col_num;
					cout<<'\n';
					if(row_num>3 || col_num>3){cout<<"Invalid Move"<<'\n';	break;}
					if(arr[row_num-1][col_num-1]=='X' || arr[row_num-1][col_num-1]=='0'){cout<<"Cannot overwrite."<<'\n';break;	}
					arr[row_num-1][col_num-1]='X';
				}
				else
				{
					cout<<'\n';
					cout<<player2<<", Which row?"<<'\t';cin>>row_num;
					cout<<'\n';
					cout<<player2<<", Which column?"<<'\t';cin>>col_num;
					cout<<'\n';
					if(row_num>3 || col_num>3){cout<<"Invalid Move"<<'\n';	break;}
					if(arr[row_num-1][col_num-1]=='X' || arr[row_num-1][col_num-1]=='0'){cout<<"Cannot overwrite."<<'\n';break;	}
					arr[row_num-1][col_num-1]='0';
				}
				if(i>=5) {
					if(check_for_win()==true)
					{
						if(i%2==0){	winner=player2;}
						else winner=player1;
						cout<<winner<<" wins the game."<<'\n';
						win=true;
					}
				}
				if(win==true)	break;
				if(i==9)
				{
					cout<<"Its a Tie"<<'\n';
					break;
				}
			}
		}
	}
return 0;
}

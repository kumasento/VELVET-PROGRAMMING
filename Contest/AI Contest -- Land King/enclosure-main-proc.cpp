/*
 * The game contest -- 2014
 * Author: VELVETDETH
 * Date: 2014/05/06
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>
#include <math>

#define PLAYER_NUMBER 4

using namespace std;

typedef struct{
	int x, y;
} Coord;

struct PlayerStatus{
	Coord Pxy;
	int stat;
	int trappedleft;
	int scoredecline;
} inputPlayerStatus[4];

struct TrapsStatus{
	Coord Pxy;
	int trapstat;
};

int main(){
	// Initialization:
	int MY_PLAYER_ID;
	int TRAP_ON_MAP;
	Coord MY_START_POINT;

	memset(inputPlayerStatus, 0, sizeof(inputPlayerStatus));

	// Part1 -- Get Start Position
	// At this point, there is no need to get other's output
	string cmd; cin >> cmd;
	if(cmd == "[START]"){
		cin>>MY_PLAYER_ID;
		// Choose where to born -- Random 
		srand((unsigned) time(0));
		MY_START_POINT.x = rand()%11;
		MY_START_POINT.y = rand()%11;
		printf("[POS] %d %d\n", MY_START_POINT.x, MY_START_POINT.y);
	}

	// Part2 -- Get the Status of All the Players and Make a Decision.
	while(cin>>cmd){
		if(cmd == "[STATUS]"){
			// SubPart1 -- Get Instruction Input
			// First get the status of the players:
			for(int i = 0; i < PLAYER_NUMBER; i++)
				scanf("%d%d%d%d%d", inputPlayerStatus[i].Pxy.x, 
									inputPlayerStatus[i].Pxy.y,
									inputPlayerStatus[i].stat,
									inputPlayerStatus[i].trappedleft,
									inputPlayerStatus[i].scoredecline);

			// Then Get the Status of the Traps
			cin>>TRAP_ON_MAP;
			TrapsStatus *TrapsStatusArray = (TrapsStatus *)
											malloc(	sizeof(TrapsStatus) *
													TRAP_ON_MAP);
			for(int i = 0; i < TRAP_ON_MAP; i++)
				scanf("%d%d%d", TrapsStatusArray[i].Pxy.x,
								TrapsStatusArray[i].Pxy.y,
								TrapsStatusArray[i].trapstat);

			// SubPart2 -- Refresh the Map

			// SubPart3 -- Make a Decision

		}
		else{
			cerr << "Error: Input Format Wrong." << endl;
			break;
		}
	}
}
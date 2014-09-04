#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
 
#define DEBUG
#define Rep(i,a) for(int i=0; i<a; i++)
#define For(i,a,b) for(int i=a; i<b; i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
 
#define CARDS 13
#define ACE 'A'
#define KING 'K'
#define QUEEN 'Q'
#define JACK 'J'

#define SUITS 4
#define SPADES 'S'
#define HEARTS 'H'
#define DIAMONDS 'D'
#define CLUBS 'C'

int main() {
#ifndef ONLINE_JUDGE
    freopen("../data/462.txt", "r", stdin);
#endif

    string first_card;
    while (cin >> first_card) {
        vector<string> cards(CARDS);
        cards[0] = first_card;
        for (int i = 1; i < CARDS; i++)
            cin >> cards[i];
        
        vector< vector<string> > suits(SUITS);

        //1. point counts
        int point_count = 0;
        int ig_point_count = 0;
        for (int i = 0; i < CARDS; i++) {
            char card_name = cards[i][0];
            char card_suit = cards[i][1];

            // rule 1
            if (card_name == ACE) point_count += 4;
            else if (card_name == KING) point_count += 3;
            else if (card_name == QUEEN) point_count += 2;
            else if (card_name == JACK) point_count += 1;

            // add to suits vector
            if (card_suit == SPADES) suits[0].push_back(cards[i]);
            else if (card_suit == HEARTS) suits[1].push_back(cards[i]);
            else if (card_suit == DIAMONDS) suits[2].push_back(cards[i]);
            else if (card_suit == CLUBS) suits[3].push_back(cards[i]);
        }

        int stopped = 0;
        for (int i = 0; i < SUITS; i++) {
            // rule 2, 3, 4
            int s_p = 0;
            for (int j = 0; j < suits[i].size(); j++) {
                char card_name = suits[i][j][0];
                char card_suit = suits[i][j][1];

                if (card_name == KING && suits[i].size() == 1) point_count --;
                if (card_name == QUEEN && suits[i].size() <= 2) point_count --;
                if (card_name == JACK && suits[i].size() <= 3) point_count --;

                if (card_name == ACE) s_p ++;
                if (card_name == KING && suits[i].size() > 1) s_p ++;
                if (card_name == QUEEN && suits[i].size() > 2) s_p ++;
            }

            if (s_p != 0) stopped ++;
        }

        ig_point_count = point_count;
        for (int i = 0; i < SUITS; i++) {
            // rule 5, 6, 7
            if (suits[i].size() == 2) point_count ++;
            else if (suits[i].size() == 1) point_count += 2;
            else if (suits[i].size() == 0) point_count += 2;
        }

        if (point_count < 14) cout << "PASS" << endl;
        else if (ig_point_count >= 16 && stopped == 4) cout << "BID NO-TRUMP" << endl;
        else if (point_count >= 14) {
            int max_val = suits[0].size(), max_idx = 0;
            
            for (int i = 1; i < SUITS; i++)
                if (max_val < suits[i].size())
                    max_val = suits[i].size(), max_idx = i;

            if (max_idx == 0) cout << "BID S" << endl;
            else if (max_idx == 1) cout << "BID H" << endl;
            else if (max_idx == 2) cout << "BID D" << endl;
            else if (max_idx == 3) cout << "BID C" << endl;
        }
    }

#ifdef DEBUG
    
#endif
   return 0;
}

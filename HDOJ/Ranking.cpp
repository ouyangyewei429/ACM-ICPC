#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int solves, costTime;
};

vector<Player> vect;
int proNum, timePenalty;

int compare(Player &c, Player &d) {
    if (c.solves == d.solves
        && c.costTime == d.costTime) {
        return c.name < d.name;
    } else {
        if (c.solves == d.solves) {
            return c.costTime < d.costTime;
        } else {
            return c.solves > d.solves;
        }
    }
}

void readData() {
    Player pr;
    char buff[20];
    int ti, subTimes;
    
    vect.clear();
    while (cin >> pr.name) {
        pr.solves = pr.costTime = 0;
        for (int i = 0; i < proNum; ++i) {
            sscanf(buff, "%d(%d)", &ti, &subTimes);
            if (ti > 0) {
                ++pr.solves;
                pr.costTime += (ti + subTimes * timePenalty);
            }
        }
        vect.push_back(pr);
    }// End of while
    return ;
}

void process() {
    sort(vect.begin(), vect.end(), compare);
    
    vector<Player>::const_iterator vectPtr;
    for (vectPtr = vect.begin(); vectPtr != vect.end(); ++vectPtr) {
        printf("%10s%2d%2d\n", vectPtr->name.c_str(), 
			                     vectPtr->solves, 
			                     vectPtr->costTime);
    }
    return ;
}

int main() {
    while (~scanf("%d %d", &proNum, &timePenalty)) {
        readData();
        process();
    }// End of while
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int numberOfCells, myOwn_size3 = 0, myOwn_size2 = 0; // 37
    cin >> numberOfCells; cin.ignore();
    vector<int> low_q, mid_q, high_q;
    for (int i = 0; i < numberOfCells; i++) {
        int index; // 0 is the center cell, the next cells spiral outwards
        int richness; // 0 if the cell is unusable, 1-3 for usable cells
        int neigh0; // the index of the neighbouring cell for each direction
        int neigh1;
        int neigh2;
        int neigh3;
        int neigh4;
        int neigh5;
        cin >> index >> richness >> neigh0 >> neigh1 >> neigh2 >> neigh3 >> neigh4 >> neigh5; cin.ignore();
        if (richness == 1)
            low_q.push_back(index);
        else if (richness == 2)
            mid_q.push_back(index);
        else
            high_q.push_back(index);
    }
    // game loop
    while (1) {
        int day; // the game lasts 24 days: 0-23
        cin >> day; cin.ignore();
        int nutrients; // the base score you gain from the next COMPLETE action
        cin >> nutrients; cin.ignore();
        int sun; // your sun points
        int score; // your current score
        cin >> sun >> score; cin.ignore();
        int oppSun; // opponent's sun points
        int oppScore; // opponent's score
        bool oppIsWaiting; // whether your opponent is asleep until the next day
        cin >> oppSun >> oppScore >> oppIsWaiting; cin.ignore();
        int numberOfTrees; // the current amount of trees
        cin >> numberOfTrees; cin.ignore();
        vector<tuple<int, bool, bool>> max_size, mid_size, min_size;
        // int max_n = 0, mid_n = 0, min_n = 0;
        for (int i = 0; i < numberOfTrees; i++) {
            int cellIndex; // location of this tree
            int size; // size of this tree: 0-3
            bool isMine; // 1 if this is your tree
            bool isDormant; // 1 if this tree is dormant
            cin >> cellIndex >> size >> isMine >> isDormant; cin.ignore();
            if (isMine)
            {
                if (size == 3)
                {
                    max_size.push_back({cellIndex, isMine, isDormant});
                    // max_n++;
                }
                else if (size == 2)
                {
                    mid_size.push_back({cellIndex, isMine, isDormant});
                    // mid_n++;
                }
                else if (size == 1)
                {
                    min_size.push_back({cellIndex, isMine, isDormant});
                    // min_n++;
                }
            }
        }
        int numberOfPossibleMoves;
        cin >> numberOfPossibleMoves; cin.ignore();
        for (int i = 0; i < numberOfPossibleMoves; i++) {
            string possibleMove;
            getline(cin, possibleMove);
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        if (!max_size.empty())
        {
            if (sun >= 4)
                cout << "COMPLETE " << get<0>(max_size[0]) << endl;
            else
                cout << "WAIT" << endl;
        }
        else if (!mid_size.empty())
        {
            if (sun >= 7)
                cout << "GROW " << get<0>(mid_size[0]) << endl;
            else
                cout << "WAIT" << endl;

        }
        else if (!min_size.empty())
        {
            if (sun >= 3)
                cout << "GROW " << get<0>(min_size[0]) << endl;
            else
                cout << "WAIT" << endl;
        }
        // GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>
        // cout << "WAIT" << endl;
    }
    #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int numberOfCells, myOwn_size3 = 0, myOwn_size2 = 0; // 37
    cin >> numberOfCells; cin.ignore();
    array<vector<int>, 37> forest;
    for (int i = 0; i < numberOfCells; i++) {
        int index; // 0 is the center cell, the next cells spiral outwards
        int richness; // 0 if the cell is unusable, 1-3 for usable cells
        int neigh0; // the index of the neighbouring cell for each direction
        int neigh1;
        int neigh2;
        int neigh3;
        int neigh4;
        int neigh5;
        cin >> index >> richness >> neigh0 >> neigh1 >> neigh2 >> neigh3 >> neigh4 >> neigh5; cin.ignore();
        forest[index] = {richness, neigh0, neigh1, neigh2, neigh3, neigh4, neigh5};
    }
    // game loop
    while (1) {
        int day; // the game lasts 24 days: 0-23
        cin >> day; cin.ignore();
        int nutrients; // the base score you gain from the next COMPLETE action
        cin >> nutrients; cin.ignore();
        int sun; // your sun points
        int score; // your current score
        cin >> sun >> score; cin.ignore();
        int oppSun; // opponent's sun points
        int oppScore; // opponent's score
        bool oppIsWaiting; // whether your opponent is asleep until the next day
        cin >> oppSun >> oppScore >> oppIsWaiting; cin.ignore();
        int numberOfTrees; // the current amount of trees
        cin >> numberOfTrees; cin.ignore();
        pair<int, bool> max_size, mid_size, min_size, seed;
        bool had_size_0 = false, had_size_1 = false, had_size_2 = false, had_size_3 = false;
        int seed_number = 0;
        // int max_n = 0, mid_n = 0, min_n = 0;
        for (int i = 0; i < numberOfTrees; i++) {
            int cellIndex; // location of this tree
            int size; // size of this tree: 0-3
            bool isMine; // 1 if this is your tree
            bool isDormant; // 1 if this tree is dormant
            cin >> cellIndex >> size >> isMine >> isDormant; cin.ignore();
            for(int i = 0; i < forest.size(); ++i)
            {
                if (forest[i][1] == cellIndex)
                    forest[i][1] = -1;
                if (forest[i][2] == cellIndex)
                    forest[i][2] = -1;
                if (forest[i][3] == cellIndex)
                    forest[i][3] = -1;
                if (forest[i][4] == cellIndex)
                    forest[i][4] = -1;
                if (forest[i][5] == cellIndex)
                    forest[i][5] = -1;
                if (forest[i][6] == cellIndex)
                    forest[i][6] = -1;
            }
            if (isMine)
            {
                if (!had_size_3 && size == 3)
                {
                    max_size = {cellIndex, isDormant};
                    had_size_3 = true;
                }
                if (!had_size_2 && size == 2)
                {
                    mid_size = {cellIndex, isDormant};
                    had_size_2 = true;
                }
                if (!had_size_1 && size == 1)
                {
                    min_size = {cellIndex, isDormant};
                    had_size_1 = true;
                }
                if (!had_size_0 && size == 0)
                {
                    seed = {cellIndex, isDormant};
                    had_size_0 = true;
                }
            }
            if (isMine && size == 0)
                seed_number++;
        }
        int numberOfPossibleMoves;
        cin >> numberOfPossibleMoves; cin.ignore();
        for (int i = 0; i < numberOfPossibleMoves; i++) {
            string possibleMove;
            getline(cin, possibleMove);
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        if (had_size_3)
        {
            if (sun >= seed_number)
            {
                for(int i = 1; i < forest[max_size.first].size(); ++i)
                {
                    if (forest[max_size.first][i] != -1 && forest[forest[max_size.first][i]][0] != 0)
                    {
                        cout << "SEED "<<  max_size.first << " "  << forest[max_size.first][i] << endl;
                        break;
                    }
                }
            }
            if (sun >= 4 && !max_size.second)
                cout << "COMPLETE " << max_size.first << endl;
        }
        if (had_size_2)
        {
            if (sun >= seed_number)
            {
                for(int i = 1; i < forest[mid_size.first].size(); ++i)
                {
                    if (forest[mid_size.first][i] != -1 && forest[forest[mid_size.first][i]][0] != 0)
                    {
                        cout << "SEED "<<  mid_size.first << " "  << forest[mid_size.first][i] << endl;
                        break;
                    }
                }
            }
            if (sun >= 7 && !mid_size.second)
                cout << "GROW " << mid_size.first << endl;
        }
        if (had_size_1)
        {
            if (sun >= seed_number)
            {
                for(int i = 1; i < forest[min_size.first].size(); ++i)
                {
                    if (forest[min_size.first][i] != -1 && forest[forest[min_size.first][i]][0] != 0)
                    {
                        cout << "SEED "<<  min_size.first << " "  << forest[min_size.first][i] << endl;
                        break;
                    }
                }
            }
            if (sun >= 3 && !min_size.second)
                cout << "GROW " << min_size.first << endl;
        }
        if (had_size_0)
        {
           if (sun >= 1 && !seed.second) 
               cout << "GROW " << seed.first << endl;
        }
        if (sun <= 0)
            cout << "WAIT" << endl;
        // GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>
        // cout << "WAIT" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
const int noEnemies = 11; 

int maxPower;    
bool canCrossChakrvyuha(vector<int>& enemyPower, int enemy, int cur_power, int behind, int skips, int recharge)
{
    if (enemy == noEnemies)
        return true;
    bool flag = false;
    if (recharge > 0 && cur_power < maxPower)
        flag |= canCrossChakrvyuha(enemyPower, enemy, maxPower, behind, skips, recharge - 1);
    if (cur_power >= behind)
    {
        cur_power -= behind;
        behind = 0;
    }
    else
        return false;
    if (skips > 0)
        flag |= canCrossChakrvyuha(enemyPower, enemy + 1, cur_power, behind, skips - 1, recharge);

    if (cur_power >= enemyPower[enemy])
    {
        if (enemy == 2 || enemy == 6)
            behind = enemyPower[enemy] / 2;

        flag |= canCrossChakrvyuha(enemyPower, enemy + 1, cur_power - enemyPower[enemy], behind, skips, recharge);
    }

    return flag;
}

int main()
{
    vector<int> enemyPower(noEnemies); 

    for (int i = 0; i < noEnemies; i++)
        cin >> enemyPower[i];

    int a, b; 
    cin >> maxPower >> a >> b;
    a = min(a, noEnemies);             
    b = min(b, noEnemies);            

    int behind = 0;             
    if (canCrossChakrvyuha(enemyPower, 0, maxPower, behind, a, b))
        cout << "Abhimanyu can cross the Chakrvyuha" << endl;
    else
        cout << "Abhimanyu cannot cross the Chakrvyuha" << endl;

    return 0;
}

//Test case: 1 

// noEnemies = 11
// enemyPower = {10,20,30,40,50,60,70,80,90,100,110}
// maxPower = 10
// a = 5
// b = 5
// Answer: Abhimanyu can cross the Chakrvyuha

// Test case: 2

// noEnemies = 11
// enemyPower = {0,10,2,3,9,5,6,}
// maxPower = 5
// a = 5
// b = 3
// Answer: Abhimanyu cannot cross the Chakrvyuha
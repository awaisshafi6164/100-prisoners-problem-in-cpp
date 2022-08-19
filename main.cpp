#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

class problem {
public:
    int drawers[100];

    problem() {

        for (int i = 0; i < 100; i++)
            drawers[i] = i;

        random_shuffle(begin(drawers), end(drawers));
    }

    bool playRandom();
    bool playlinked();
};

bool problem::playRandom() {
    bool openedDrawers[100] = { 0 };

    for (int prisonerNum = 0; prisonerNum < 100; prisonerNum++) {

        bool prisonerSuccess = false;

        for (int i = 0; i < 50; i++) {

            int drawerNum = (rand() % 100) + 1;

            if (!openedDrawers[drawerNum]) {
                openedDrawers[drawerNum] = true;
                break;
            }
            if (drawers[drawerNum] == prisonerNum) {
                prisonerSuccess = true;
                break;
            }
        }
        if (!prisonerSuccess)
            return false;
    }
    return true;
}

bool problem::playlinked() {
    for (int prisonerNum = 0; prisonerNum < 100; prisonerNum++) {
        bool prisonerSuccess = false;
        int checkDrawerNum = prisonerNum;
        for (int i = 0; i < 50; i++) {
            if (drawers[checkDrawerNum] == prisonerNum) {
                prisonerSuccess = true;
                break;
            } else
                checkDrawerNum = drawers[checkDrawerNum];
        }
        if (!prisonerSuccess)
            return false;
    }
    return true;
}

double strategy(char choice){

    int numberOfSuccesses = 0;

    for (int i = 0; i < (100 *100); i++) {

        problem d;

        if ((choice == '1' && d.playRandom()) || (choice == '2' && d.playlinked()))
            numberOfSuccesses++;
    }

    return numberOfSuccesses * 100.0 / (100 * 100);
}

int main() {

    cout<<"100 Prisoners Problem\n\n";

    char choice;
    cout<<"Press 1: For Random Strategy\n";
    cout<<"Press 2: For Linked Strategy\n";
    cout<<"Enter Choice Here --> ";
    cin>>choice;

    switch(choice){
        case '1':{
            cout << "\nRandom strategy:  " << strategy('1') << " %" << endl;
            break;
        }
        case '2':{
            cout << "\nLinked strategy: " << strategy('2') << " %" << endl;
            break;
        }
        default:{
            cout<<"Wrong Entry!\n";
            break;
        }
    }

    return 0;
}

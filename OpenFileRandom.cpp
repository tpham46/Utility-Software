 #include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    srand(time(0));
    // Open random a file after every 15 minutes
    ifstream Input1;
    ifstream Input2;
    vector<string> v;
    cout << "Opening schedule file!";
    Input1.open("Schedule.txt");

    string scan;
    while(getline(Input1,scan)){
        v.push_back(scan);
    }
    cout << endl;
    random_shuffle(v.begin(),v.end());

    int counter = 0 ;

    int x = 1500;
    bool work = true;
    while(work != false){
        if(!v.empty()){
            cout << "Your next task is " << v.at(v.size()-1) << endl;
            v.pop_back();
            counter++;
        }
        else{
            cout << "Run out of things to do, Relax! \n";
        }
        while(x > 0){
            sleep(1);
            x--;
            if(x == 0){
                x = 1500;
                system("shutdown -h");
                do{
                cout << "Press g to continue!";
                } while(cin.get() != 'g');

            }
        }

        if(v.empty()){
            cout << "U r Done \n \n \n";
            break;
        }
    }

    Input1.close();
    return 0;
}

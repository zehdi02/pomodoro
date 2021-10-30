#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void studyBreak(int h, int m, int s) {
    char decide;
    while (h!=0 && m!=0 && s!=0) {
        system("cls");
        cout << "   BREAK   " << endl;
        cout << "===========" << endl;
        cout << h << " : " << m << " : " << s << endl;
        cout << "===========" << endl;

        // when programs first runs and timer goes from 1min 0s to 59s
        if (s==0 && m==0) {
            s=60;
            if (m>0) {
                m--;
            }
        }
        s--;

        // when timer goes from 2min 0s, to 1min 59s
        if (s==0 && m>0) {
            s = 59;
            m--;
            if (m == 0) {
                m = 0;
            }
        }

        // when timer goes from 1hr to 59min n 59s
        if (m==0 && h>0) {
            m = 59;
            s = 59;
            h--;
        }

        if (h==0 && m==0 && s==0) {
            cout << "================================\n";
            cout << "         BREAK IS OVER!\n         TIME TO STUDY!\n";
            cout << "================================\n";
        }

        sleep(1); //usleep() must be <1,000,000 to work like sleep(1)
    }
}

int main(){
    
    int hr, min, sec;
    int breakCounter = 24;
    //unsigned int usecs = 999999;
    char decide;
    int first = 1;
    cout << "======================================================" << endl;
    cout << "Enter how lonog you want to study for [HR, MIN, SEC]: \n";
    cout << "======================================================" << endl;
    cin >> hr >> min >> sec;
    // hr = 0;
    // min = 0;
    // sec = 2;

    while (true) {
        system("cls");
        cout << "===========" << endl;
        cout << hr << " : " << min << " : " << sec << endl;
        cout << "===========" << endl;
        
        // when programs first runs and timer goes from 1min 0s to 59s
        if (sec==0 && first==1) {
            sec=60;
            first--;
            if (min>0) {
                min--;
            }
        }
        sec--;

        // when timer goes from 2min 0s, to 1min 59s
        if (sec==0 && first==0) {
            sec = 59;
            min--;
            if (min == 0) {
                min = 0;
            }
        }

        // when timer goes from 1hr to 59min n 59s
        if (min==0 && hr>0) {
            min = 59;
            sec = 59;
            hr--;
        }

        // When timer is finished after study timer
        if (hr==0 && min==0 && sec==0 && breakCounter>0) {
            breakCounter--;
            system("cls");
            cout << "================================================================" << endl;
            cout << hr << " : " << min << " : " << sec << endl;
            cout << "Timer ended.\nWould you like to '(r)elax' or '(s)top' or '(c)ontinue studying?\n";
            cout << "================================================================" << endl;
            cin >> decide;

            // ends the pomodoro program
            if (decide=='s') {
                cout << "=======================================" << endl;
                cout << "You have stopped the Pomodoro program.\n";
                cout << "=======================================" << endl;
                return 0;
            }

            // puts user to break mode
            if (decide=='r') {
                // hr = 0;
                // min = 0;
                // sec = 3;
                cout << "==========================" << endl;
                cout << "How long is your break?\n";
                cout << "==========================" << endl;
                cin >> hr >> min >> sec;
                
                cout << "=======================================" << endl;
                cout << "You have a break for " << hr << " : " << min << " : " << sec << endl;
                cout << "=======================================" << endl;
                studyBreak(hr, min, sec);
            }

            // get back to studying
            if (decide=='c') {
                main();
            }
        }
        
        sleep(1); //usleep() must be <1,000,000 to work like sleep(1)
    }

    return 0;
}
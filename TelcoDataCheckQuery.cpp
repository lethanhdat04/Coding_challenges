#include<iostream>
#include<map>

using namespace std;

bool checkPhone(string s) {
    if (s.length() != 10) return false;
    else {
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] < '0') || (s[i] > '9')) return false;
        }
    }
    return true;
}

int countTime(string ftime, string etime) {
    int startTime = 3600*((ftime[0] - '0')*10 + ftime[1] - '0') + 60*((ftime[3] - '0')*10 + ftime[4] - '0') + (ftime[6] - '0')*10 + ftime[7] - '0';
    int endTime = 3600*((etime[0] - '0')*10 + etime[1] - '0') + 60*((etime[3] - '0')*10 + etime[4] - '0') + (etime[6] - '0')*10 + etime[7] - '0';
    return endTime - startTime;
}

map<string, int> numberCalls, timeCall;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int totalCall = 0;
    int incorrectNum = 0;
    string type;
    while (cin >> type && type != "#") {
        totalCall++;
        string fnum, tnum, date, ftime, ttime;
        cin >> fnum >> tnum >> date >> ftime >> ttime;
        if (!checkPhone(fnum) || !checkPhone(tnum)) incorrectNum++;
        numberCalls[fnum]++;
        timeCall[fnum] += countTime(ftime, ttime);
    }

    do {
        cin >> type;
        if (type == "#") continue;
        if (type == "?check_phone_number") {
            if (incorrectNum == 0) {
                cout << 1 << endl;
            } else cout << 0 << endl;
        } else if (type == "?number_calls_from") {
            string fnum;
            cin >> fnum;
            cout << numberCalls[fnum] << endl;
        } else if (type == "?count_time_calls_from") {
            string fnum;
            cin >> fnum;
            cout << timeCall[fnum] << endl;
        } else {
            cout << totalCall << "\n";
        }
    } while (type != "#");

    return 0;
}
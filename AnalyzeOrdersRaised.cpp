#include<iostream>
#include<sstream>
#include<vector>
#include<map>

using namespace std;

int parseTime(const string& time){
    int h = stoi(time.substr(0,2));
    int m = stoi(time.substr(3,2));
    int s = stoi(time.substr(6,2));
    return h*3600 + m*60 + s;
}

int main(){
    string line;
    vector<string> orderTimes;
    map<string, int> timeCount;
    int order[100000];
    int orderCount[100000];

    while (getline(cin, line) && line != "#"){
        stringstream ss(line);
        string orderId, timePoint;
        ss >> orderId >> timePoint;
        orderTimes.push_back(timePoint);
        int x = parseTime(timePoint);
        order[x] += 1;
        timeCount[timePoint]++;
    }

    for (int i = 1; i <= 100000; i++){
        orderCount[i] = orderCount[i-1] + order[i];
    }

    //Process the query
    while (getline(cin, line) && line != "###"){
        if (line == "?number_orders"){
            cout << orderTimes.size() << endl;
        } else if (line.find("?number_orders_in_period") == 0){
            stringstream ss(line);
            string query, fromTime, endTime;
            ss >> query >> fromTime >> endTime;
            int from = parseTime(fromTime);
            int end = parseTime(endTime);
            // int count = 0;

            // for (const string& time: orderTimes){
            //     int x = parseTime(time);
            //     if (x >= from && x <= end){
            //         count++;
            //     }
            // }
            // cout << count << endl;
            cout << orderCount[end] - orderCount[from - 1] << "\n";
        } else if (line.find("?number_orders_at_time") == 0){
            stringstream ss(line);
            string query, atTime;
            ss >> query >> atTime;
            cout << timeCount[atTime] << endl;
        }
    }
    return 0;
}
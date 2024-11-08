#include <iostream>
#include <string>
#include<stack>

using namespace std;

int main(){
    string command;
    stack<int> st;
    int value;
    while (cin >> command && command != "#"){
        if (command == "PUSH"){
            cin >> value;
            st.push(value);
        } else if (command == "POP"){
            if (!st.empty()){
                cout << st.top() << endl;
                st.pop();
            } else {
                cout << "NULL" << endl;
            }
        }
    }
    // while (!st.empty()){
    //     cout << st.top() << "\n";
    //     st.pop();
    // }
    return 0; 
}
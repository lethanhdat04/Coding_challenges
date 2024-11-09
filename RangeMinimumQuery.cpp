#include<iostream>

using namespace std;

const int MAX_N = 1000005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG];  // m[i][j] is minium among a[i..i+2^j-1]

int query(int L, int R){
    int length = R - L + 1;
    int k = 0;
    while ((1 << (k+1)) <= length){
        k++;
    }
    return min(m[L][k], m[R - (1 << k) + 1][k]);
}

int main(){
    //input()
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        m[i][0] = a[i];
    }
    //Preprocessing
    for (int j = 1; j < LOG; j++){
        for (int i = 0; i + (1 << j) - 1 < n; i++){
            m[i][j] = min(m[i][j-1], m[i+(1<<(j-1))][j-1]);
        }
    }
    //Query
    int q;
    cin >> q;
    int sum = 0;
    for (int i = 0; i < q; i++){
        int L, R;
        cin >> L >> R;
        sum += query(L, R);
    }
    cout << sum;
    return 0;
}
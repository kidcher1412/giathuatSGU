#include <bits/stdc++.h>

using namespace std;

int check(double mid, int f, vector<int> r){
    int sum = 0, i = r.size();
    while(i--) {
        sum += (int)(M_PI * r[i] *r[i] / mid);
        if(sum > f) return 1;
    }
    return sum > f;
}

double bitnarySearch(vector<int> r, int f){
    double low = 0, hight = 100, mid;
    int temp = 50;
    while(temp--){
        mid = (low + hight) / 2;
        check(mid, f, r) ? low = mid : hight = mid;
    }
    return low;
}

int main() {
    int t, n, f;
    cin >> t;
    while (t--) {
        cin >> n >> f;
        vector<int> r;
        int i = n;
        while(i--) {
            cin >> n;
            r.push_back(n);
        };
        sort(r.begin(), r.end());
        cout << endl;
        cout <<  bitnarySearch(r, f);
    }
}
#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_func(string s) {
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i]) 
            j = p[j - 1];
        if (s[j] == s[i])
            j++;
        p[i] = j;
    }
    return p;
}

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    int dl = s.size();

    vector<int> p = prefix_func(s);
    int res;
    for(int i = 1; i + 1 < dl; i += 2){
        res = i + 1;
        int q = res - p[i];
        if(res % q == 0 and (res / 2) % q == 0){
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Lice {
    long index;
    long pristigane;
    long trygvane;
    long stol=-1;
  //chatichna naredba
    bool operator<(const Lice& other) const {
        if (pristigane == other.trygvane) {
            return trygvane < other.trygvane;
        }
        return start < other.start;
    }
 //chatichna naredba
    bool operator>(const Lice& other) const {
           return end > other.end;
    }
};

int main() {
    long n, t;
    cin >> n;
    vector<Person> hora(n);
    for (int i = 0; i < n; i++) {
        hora[i].index = i;
        cin >> hora[i].start >> hora[i].end;
    }
    cin >> t;
    priority_queue<int,vector<int>, greater<int>> stolove;
    for (int i = 0; i < n; i++) {
        stolove.push(i);
    }
    sort(hora.begin(), hora.end());
    int result=0;
    priority_queue<Person,vector<Person>,greater<Person>> sednali;
    for (int i = 0; i < n; i++) {
        if (sednali.empty() || hora[i].start < sednali.top().end) {
            hora[i].stol=stolove.top();  
            stolove.pop();
            if (hora[i].index == t) {
                result=hora[i].stol;
                break;
            }
            sednali.push(hora[i]);
        }
        else {
            while (!sednali.empty() && sednali.top().end <= hora[i].start) {
                stolove.push(sednali.top().stol);
                sednali.pop();
            }
            hora[i].stol=stolove.top();  
            stolove.pop();
            if (hora[i].index == t) {
                result=hora[i].stol;
                break;
            }
            sednali.push(hora[i]);
        }
      
    }
    cout<<result;
    return 0;
}

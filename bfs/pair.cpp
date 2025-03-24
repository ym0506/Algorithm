#include <iostream>
#include <utility>

using namespace std;

int main() {
    pair<int, int> t1 = make_pair(10, 12);
    pair<int, int> t2 = {20, 30};

    cout << t2.first << ' ' << t2.second << '\n';

    if (t2 < t1) cout << "t2 < t1\n";
}
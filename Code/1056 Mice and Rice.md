## 1056 Mice and Rice （25 分)

**Mice and Rice** is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.

First the playing order is randomly decided for *N**P* programmers. Then every *N**G* programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every *N**G* winners are then grouped in the next match until a final winner is determined.

For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: *N**P* and *N**G* (≤1000), the number of programmers and the maximum number of mice in a group, respectively. If there are less than *N**G* mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains *N**P* distinct non-negative numbers *W**i* (*i*=0,⋯,*N**P*−1) where each *W**i* is the weight of the *i*-th mouse respectively. The third line gives the initial playing order which is a permutation of 0,⋯,*N**P*−1 (assume that the programmers are numbered from 0 to *N**P*−1). All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the final ranks in a line. The *i*-th number is the rank of the *i*-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.

### Sample Input:

```in
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
```

### Sample Output:

```out
5 5 5 2 5 5 5 3 1 3 5
```

### Code

```c++
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int weight, index, rank, index0;
};
bool cmp(node a, node b) {
    return a.index0 < b.index0;
}
int main() {
    int n, g, num;
    scanf("%d%d", &n, &g);
    vector<int> v(n);
    vector<node> w(n);
    queue<node> q;
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        w[i].weight = v[num];
        w[i].index = i;
        w[i].index0 = num;
        q.push(w[i]);
    }
    while(!q.empty()) {
        int size = q.size();
        if(size == 1) {
            node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }
        int group = size / g;
        if(size % g != 0)
            group += 1;
        node maxnode;
        int maxn = -1, cnt = 0;
        for(int i = 0; i < size; i++) {
            node temp = q.front();
            w[temp.index].rank = group + 1;
            q.pop();
            cnt++;
            if(temp.weight > maxn) {
                maxn = temp.weight;
                maxnode = temp;
            }
            if(cnt == g || i == size - 1) {
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }
    sort(w.begin(), w.end(), cmp);
    for(int i = 0; i < n; i++) {
        if(i != 0) printf(" ");
        printf("%d", w[i].rank);
    }
    return 0;
}
```


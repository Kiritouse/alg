#include <bits/stdc++.h>
using namespace std;
bool check(priority_queue<int> pq)
{
    while (pq.size() != 1)
    {
        int max1 = pq.top();
        pq.pop();
        int max2 = pq.top();
        pq.pop();
        int deltamax = abs(max1 - max2);
        pq.push(deltamax);
    }
    if (pq.top() == 0)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int num = 0;
            scanf("%d", &num);
            pq.push(num);
        }
        if (check(pq))
            printf("Yes\n");
        else
            printf("No\n");
    }
}

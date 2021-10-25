#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ifstream cin("speeding.in");
    ofstream cout("speeding.out");
    vector<pair<int, int>> segments, bessei_seg;
    int N,M;
    cin >> N >> M;
    while (N--)
    {
        int l,s;
        cin >> l >> s;
        segments.push_back({l,s});
    }
    while (M--)
    {
        int l,s;
        cin >> l >> s;
        bessei_seg.push_back({l,s});
    }
    int seg_sum = 0, be_seg_sum = 0, ans = 0;
    for (size_t i = 0; i < bessei_seg.size(); i++)
    {
        be_seg_sum += bessei_seg[i].first;
        seg_sum = 0;
        for (size_t j = 0; j < segments.size(); j++)
        {
            seg_sum += segments[j].first;
            if (seg_sum >= be_seg_sum)
            {
                ans = max(ans, (int)(bessei_seg[i].second - segments[j].second));
                break;
            }
        }
    }
    cout << ans; 
    return 0;
}
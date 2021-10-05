#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m,s_len,t_len,min_ans = 1e3+1,tmp_ans = 0;
    string s,t,sub_t;
    vector<int> indexs,tmp;
    cin>>n>>m>>s>>t;
    s_len = s.size();
    t_len = t.size();
    for (size_t i = 0; i < t.size(); ++i)
    {
        if (t_len - i >= s_len)
        {
            sub_t = t.substr(i,s_len);
            tmp_ans = 0;
            tmp.clear();
            for (size_t j = 0; j < sub_t.size(); ++j)
            {
                if (sub_t[j] != s[j])
                {
                    tmp_ans++;
                    tmp.push_back(j+1);
                }
            }
        }
        min_ans = min(min_ans, tmp_ans);
        if (min_ans == tmp_ans)
        {
            indexs.clear();
            for (size_t k = 0; k < tmp.size(); k++)
               indexs.push_back(tmp[k]);
        }
    }
    cout << min_ans << '\n';
    for(auto x:indexs)
        cout << x << ' ';
    cout << '\n';
    return 0; 
}
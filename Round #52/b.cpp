/*

We walked with our shoulders in line,
Laughing about things that didn't matter as we looked onward toward the same dream.
If I listen carefully, I can still hear it,
Your voice, staining this city orange.

When you're not around, I'm so bored,
But when I say I'm lonely, you just laugh at me.
I just keep counting up the things I have left,
That shine brightly and never fade away.

Like the sky after the rain lets up, like clearing up one's heart.
I remember your smile, it floats up in my mind and I can't help but smile.
Surely, just as we were that day, like innocent children,
We'll run through the passing seasons, seeing each of our many tomorrows.

Whenever I was alone and started to feel uneasy,
On nights I didn't want to sleep, we'd just go on talking.

I wonder what you'll go on to see from here,
And what I'll see right here.
I'll try to entrust my tears,
To this city where the setting sun stains everything orange.

This single love was born among a million rays of light.
Even if you never change, even if you happen to change, you're you, so I'm not worried.
Someday we'll both become adults and meet wonderful people.
At that time, I hope we can bring along our irreplaceable families and meet here again.

Like the sky after the rain lets up, like clearing up one's heart.
I remember your smile, it floats up in my mind and I can't help but smile.
This single love was born among a million rays of light.
We run through the passing seasons, seeing each of our many tomorrows,
Choosing from each of our many dreams.

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> edge[N];
int cnt[N];

vector<int> rem;

void pre(int now, int bef) {
  for (auto it : edge[now]) if (it.first != bef) {
    pre(it.first, now);
    cnt[now] += cnt[it.first];
  }
  cnt[now]++;
}

void dfs(int now, int bef) {
  for (auto it : edge[now]) {
    if (it.first == bef) continue;
    if (it.second) {
      rem.push_back(cnt[it.first]);
      continue;
    }
    dfs(it.first, now);
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edge[a].emplace_back(b, c);
    edge[b].emplace_back(a, c);
  }  
  pre(1, 0);
  dfs(1, 0);
  sort(rem.begin(), rem.end());
  reverse(rem.begin(), rem.end());
  int now = n, ans = 0;
  for (auto it : rem) {
    if (now <= k) break;
    //printf("rem %d\n", it);
    ans++;
    now -= it;
  }
  if (now <= k) {
    cout << ans << endl;
  } else {
    puts("-1");
  }
  return 0;
}

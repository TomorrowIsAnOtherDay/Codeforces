/*************************************************************************
    > File Name: c.cpp
    > Author:zhoubo_NLP 
    > Mail: zhouboacmer@qq.com
    > Created Time: 五  7/ 7 10:07:11 2017
    > Usage: 
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 200050;

struct Trip{
  int l, r;
  int cost;
}trip[N], trip2[N];
int min_cost[N];

bool lpoint_cmp(const Trip& s1, const Trip& s2) {
  return s1.l < s2.l;
}

bool rpoint_cmp(const Trip& s1, const Trip& s2) {
  return s1.r < s2.r;
}

int main() {
  int n, x;
  std::cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    std::cin >> trip[i].l >> trip[i].r >> trip[i].cost;
    trip2[i] = trip[i];
  }
  for(int i = 0; i < N; ++i) {
    min_cost[i] = -1;
  }
  std::sort(trip, trip + n, lpoint_cmp);
  std::sort(trip2, trip2 + n, rpoint_cmp);
  int ans = -1;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && trip2[j].r < trip[i].l) {
      int cur_duration = trip2[j].r - trip2[j].l + 1;
      if (min_cost[cur_duration] == -1) {
        min_cost[cur_duration] = trip2[j].cost;
      } else {
        min_cost[cur_duration] = std::min(min_cost[cur_duration], trip2[j].cost);
      }
      ++j;
    }
    int cur_days = trip[i].r - trip[i].l + 1;
    int rest_days = x - cur_days;
    if (rest_days <= 0) {
      continue;
    }
    if (min_cost[rest_days] == -1) {
      continue;
    }
    int all_cost = trip[i].cost + min_cost[rest_days];
    if (ans == -1) {
      ans = all_cost;
    } else {
      ans = std::min(ans, all_cost);
    }
  }
  if (ans == -1) {
    ans = -1;
  }
  std::cout << ans << std::endl;
  return 0;
}


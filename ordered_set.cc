#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    oms;

// set
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    os;

// oms s;
// s.insert(v);

// Find the order of a value, 0 indexed
// s.order_of_key(v);

// Find the k-th value
// auto itr = s.find_by_order(k - 1);

// Remove a value
// s.erase(s.find_by_order(s.order_of_key(v));

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
// s.order_of_key(v);
// s.find_by_order(v);

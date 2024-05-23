#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <sstream>
#include <set>
#include <vector>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// https://codeforces.com/blog/entry/76087
template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1,T2> &p){
  os << '{' << p.first << ", " << p.second << '}';
  return os;
}

template<typename C, 
         typename T = std::decay<decltype(*begin(std::declval<C>()))>,
         typename std::enable_if<!std::is_same<C, std::string>::value>::type* = nullptr
         >
std::ostream &operator<<(std::ostream &os, const C &container){
  bool first = true;
  std::stringstream ss; 
  ss << '[';
  for(const auto &x : container){
    if (!first){
      ss << ", ";
    }
    first = false;
    ss << x;
  }
  ss << ']';
  return os << ss.str();
}

vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}

void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef DEBUG
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

// binsary search (lower_bound) do not being used here
int bs(int* a, int value, int size) {
  int left = 0, right = size-1;

  while (left < right) {
    int mid = left + (right-left)/2;

    if (a[mid] < value) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

void run_case() {
  int k, q;
  cin >> k >> q;
  int a[k];
  for (int i = 0; i < k; i++) {
    int ai;
    cin >> ai; a[i] = ai; // already sorted
  }
  int n;
  while (q--) {
    cin >> n;
    cout << min(a[0]-1, n) << " ";
  }
  cout << "\n";
}

int main() {
  int tests;
  cin >> tests;

  while (tests-- > 0) 
    run_case();
}

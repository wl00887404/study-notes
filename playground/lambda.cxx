#include <functional>
#include <iostream>

using namespace std;

int main() {
  function<int(int)> fib = [&](int n) {
    if (n == 0 || n == 1) return 1;

    return fib(n - 1) + fib(n - 2);
  };

  cout << fib(2) << endl;
  return 0;
}
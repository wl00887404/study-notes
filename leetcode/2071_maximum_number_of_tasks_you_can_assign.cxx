#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * tasks 表示任務， tasks[i] 有最低力量要求
 * workers 是勞工， workers[i] 是每個勞工的力量
 * pills 是要藥丸數量，吃下藥丸可以成長 strength，strength >= tasks[i]
 * 就可以承接該任務
 */

/**
 * 感覺解法是貪婪演算法
 * 不用吃藥就可以做，吃了藥才能做，吃了藥也做不了
 * 假設以吃了藥才要做為優先，最強的 worker 打藥
 *
 * 1. 最強 worker 不用吃藥就可以打工
 * 2. 吃藥打不了工，那吃藥看看吧
 * 3. 吃了藥也做不了，只好降低任務難度了
 */

/**
 * testcase 28 爆開
 * pills = 1, strength = 5
 * tasks = [5, 5, 8, 9, 9]
 * workers = [1, 2, 4, 6, 6]
 *
 * 最佳的結果不是最強的 worker 吃藥，應該是符合標準最弱的 worker 吃
 * 9 要吃藥的話，應該是 4 的 worker 就可以做了，不需要用到 9 的 worker
 *
 * 本來就可以分配到任務的 worker，吃了藥也是沒用的吧
 *
 * 6 6 可以配 5 5
 * 6 吃了藥去配 9 也沒有幫助，但是 4 可以吃藥去配 9
 *
 * pills = 1, strength = 5
 * tasks = [5, 5, 11]
 * workers = [5, 5, 6]
 *
 * 6 可以配 5， 5 也可以配 5
 *
 */

/**
 * 能力足夠的 worker，吃了藥去做更難的工作，不要搶較弱的 worker 工作
 * 能力不足的 worker，吃了藥可以能配對到工作
 */

/**
 * TODO: 每日一題偷抄作業，下次補
 */

class Solution {
 public:
  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                    int strength) {
    int m = workers.size();
    int n = tasks.size();

    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int i = m - 1;
    int j = n - 1;

    queue<int> q;

    int result = 0;
    while (i >= 0 && j >= 0) {
      if (workers[i] >= tasks[j]) {
        cout << workers[i] << " 匹配了 " << tasks[j] << endl;
        i--;
        j--;
        result++;
      } else {
        cout << workers[i] << " 做不了 " << tasks[j] << endl;

        q.push(tasks[j]);
        j--;  // 這任務做不了，只能降級
      }
    }

    cout << i << endl;

    while (i >= 0 && !q.empty() && pills > 0) {
      int& task = q.front();
      if (workers[i] + strength >= task) {
        i--;
        pills--;
        result++;
      }

      q.pop();
    }

    return result;
  }
};
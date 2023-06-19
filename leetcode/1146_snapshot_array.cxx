#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 寫是寫出來了
 * 不過有夠慢，實在不確定哪邊可以更快
 * 
 * TODO: 研究一下怎麼樣可以更快
 */

class SnapshotArrayInterface {
 public:
  virtual void set(int index, int val) = 0;
  virtual int snap() = 0;
  virtual int get(int index, int snap_id) = 0;
};

/**
 * 如果我 snapshot 是儲存每個 index 的值
 * 那我乾脆每個 snapshot 都直接存成一個 array 就好
 * 這樣 snapshot 的時間複雜度就是 O(length)
 * get 的時間複雜度是 O(1)
 */

class TimeCaredSnapshotArray : public SnapshotArrayInterface {
 public:
  vector<int> array;
  vector<vector<int>*> snapshots;
  bool hasChanged = false;

  TimeCaredSnapshotArray(int length) { array.resize(length, 0); }

  void set(int index, int val) {
    hasChanged = true;
    array[index] = val;
  }

  int snap() {
    int size = snapshots.size();

    if (!hasChanged && size > 0) {
      snapshots.push_back(snapshots[size - 1]);

      return size;
    }

    vector<int>* snapshot = new vector<int>(array);
    snapshots.push_back(snapshot);
    hasChanged = false;
    return size;
  }

  int get(int index, int snap_id) { return (*snapshots[snap_id])[index]; }
};

/**
 * 假設 values 是 [{0, 0}, {1, 3}, {2, 5}]
 * 直接 binary search
 * get(0) get(3) get(5) 沒問題
 * get(1) 其實是 get(0)
 */

class ValueWithSnapId {
  int value;
  // value, snap_id
  vector<pair<int, int>> values;

 public:
  ValueWithSnapId(int val) { value = val; }

  void snap(int version) {
    if (value == -1) return;
    if (!values.empty() && values.back().first == value) return;
    values.push_back({value, version});
    value = -1;
  }

  void set(int val) { value = val; }

  int get(int snapId) {
    int left = 0;
    int right = values.size();

    while (left < right) {
      int mid = (left + right) / 2;

      if (values[mid].second == snapId) {
        return values[mid].first;
      } else if (values[mid].second < snapId) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return values[left - 1].first;
  }
};

class MemoryCaredSnapshotArray : public SnapshotArrayInterface {
 public:
  vector<ValueWithSnapId*> snapshots;
  int length;
  int version;
  unordered_set<int> changedIndex;

  MemoryCaredSnapshotArray(int length) {
    this->length = length;
    version = 0;
    snapshots.resize(length);
    int& i = length;
    while (i--) {
      changedIndex.insert(i);
      snapshots[i] = new ValueWithSnapId(0);
    }
  }

  void set(int index, int val) {
    changedIndex.insert(index);
    snapshots[index]->set(val);
  }

  int snap() {
    int version = this->version;

    for (const int& i : changedIndex) {
      snapshots[i]->snap(version);
    }

    this->version++;
    changedIndex.clear();

    return version;
  }

  int get(int index, int snap_id) { return snapshots[index]->get(snap_id); }
};

class SnapshotArray {
 public:
  SnapshotArrayInterface* pointer;

  SnapshotArray(int length) {
    if (length > 100) {
      pointer = new MemoryCaredSnapshotArray(length);

    } else {
      pointer = new TimeCaredSnapshotArray(length);
    }
  };

  void set(int index, int val) { pointer->set(index, val); }
  int snap() { pointer->snap(); }
  int get(int index, int snap_id) { pointer->get(index, snap_id); }
};
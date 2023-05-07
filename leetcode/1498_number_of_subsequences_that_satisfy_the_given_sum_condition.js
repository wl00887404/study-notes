var numSubseq = function (nums, target) {
  nums.sort((a, b) => a - b);
  let result = 0n;
  const size = nums.length;

  let left = 0;
  let right = size - 1;

  while (left <= right) {
    while (left <= right && nums[left] + nums[right] > target) {
      right--;
    }
    if (left > right) break;

    // 找到 left 最極限的尾
    // [left, right] 之間的數字都可以跟 left 組合
    const length = BigInt(Math.max(0, right - left));
    result += 2n ** length;
    left++;
  }

  return result % 1000000007n;
};

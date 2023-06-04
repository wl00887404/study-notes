var ArrayWrapper = function (nums) {
  this.nums = nums;
};

ArrayWrapper.prototype.valueOf = function () {
  if (this.sum) return this.sum;

  this.sum = 0;
  this.nums.forEach(n => (this.sum += n));

  return this.sum;
};

ArrayWrapper.prototype.toString = function () {
  if (this.string) return this.string;

  this.string = '[' + this.nums.join(',') + ']';

  return this.string;
};

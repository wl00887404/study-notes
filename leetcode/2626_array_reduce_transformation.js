var reduce = function (nums, fn, init) {
  let result = init;

  nums.forEach((...args) => {
    result = fn(result, ...args);
  });

  return result;
};

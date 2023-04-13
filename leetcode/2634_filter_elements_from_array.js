var filter = function (arr, fn) {
  const result = [];

  arr.forEach((...args) => {
    if (fn(...args)) result.push(args[0]);
  });

  return result;
};

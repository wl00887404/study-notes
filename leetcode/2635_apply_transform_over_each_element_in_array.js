var map = function (arr, fn) {
  const result = [];

  arr.forEach((...args) => {
    result.push(fn(...args));
  });

  return result;
};

var flat = function (arr, n) {
  if (n == 0) return arr;
  if (!Array.isArray(arr)) return arr;

  const result = [];

  arr.forEach(value => {
    const flatten = flat(value, n - 1);

    if (!Array.isArray(flatten)) return result.push(value);

    result.push(...flatten);
  });

  return result;
};

var chunk = function (arr, size) {
  const result = [];
  let i = 0;
  for (; i < arr.length; i += size) {
    result.push(arr.slice(i, i + size));
  }

  return result;
};

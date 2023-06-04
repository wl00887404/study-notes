var inorderTraversal = function* (arr) {
  let index = 0;
  let pointer = arr;
  const stackArray = [];
  const stackIndex = [];

  while (true) {
    if (typeof pointer[index] === 'object') {
      stackArray.push(pointer);
      stackIndex.push(index + 1);
      pointer = pointer[index];
      index = 0;
      continue;
    }
    if (pointer[index] === undefined) {
      if (stackArray.length === 0) break;
      pointer = stackArray.pop();
      index = stackIndex.pop();
    } else {
      yield pointer[index];
      index++;
    }
  }

  return undefined;
};

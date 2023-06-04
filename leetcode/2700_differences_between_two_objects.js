const isObject = target => typeof target === 'object' && target !== null;

function objDiff(obj1, obj2) {
  const result = helper(obj1, obj2);
  if (result) return result;

  return {};
}

function helper(obj1, obj2) {
  if (!isObject(obj1) || !isObject(obj2)) {
    return obj1 !== obj2 ? [obj1, obj2] : undefined;
  }

  const isArray1 = Array.isArray(obj1);
  const isArray2 = Array.isArray(obj2);
  if ((isArray1 && !isArray2) || (!isArray1 && isArray2)) {
    return [obj1, obj2];
  }

  //  都是 array 或是都是 object
  const result = {};
  Object.entries(obj1).forEach(([key, value1]) => {
    const value2 = obj2[key];
    if (value2 === undefined) return;

    const resultValue = helper(value1, obj2[key]);
    if (resultValue) result[key] = resultValue;
  });

  return Object.keys(result).length ? result : undefined;
}

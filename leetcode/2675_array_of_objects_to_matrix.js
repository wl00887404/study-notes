const flatObject = obj => {
  const result = {};

  const helper = (target, path) => {
    if (typeof target !== 'object' || target === null) {
      return (result[path] = target);
    }

    Object.entries(target).forEach(([key, value]) => {
      helper(value, path ? `${path}.${key}` : key);
    });
  };

  helper(obj);
  return result;
};

var jsonToMatrix = function (arr) {
  const keySet = new Set();

  const flattenArr = arr.map(obj => {
    const flattenObject = flatObject(obj);
    Object.keys(flattenObject).forEach(key => keySet.add(key));

    return flattenObject;
  });

  const keys = Array.from(keySet).sort();
  const result = [keys];
  flattenArr.forEach(obj => {
    result.push(keys.map(key => (obj[key] === undefined ? '' : obj[key])));
  });

  return result;
};

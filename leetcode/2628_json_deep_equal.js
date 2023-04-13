var areDeeplyEqual = function (o1, o2) {
  const isObject1 = o1 !== null && typeof o1 === 'object';
  const isObject2 = o2 !== null && typeof o2 === 'object';

  // 其中一方不是 Object
  if (!isObject1 || !isObject2) return o1 === o2;

  if (Array.isArray(o1) && !Array.isArray(o2)) return false;
  if (!Array.isArray(o1) && Array.isArray(o2)) return false;

  const keys = Array.from(new Set([...Object.keys(o1), ...Object.keys(o2)]));

  for (const key of keys) {
    if (!areDeeplyEqual(o1[key], o2[key])) return false;
  }

  return true;
};

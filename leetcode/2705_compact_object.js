var compactObject = function (obj) {
  if (Array.isArray(obj)) {
    return obj.map(compactObject).filter(x => x);
  }

  if (typeof obj === 'object' && obj !== null) {
    const result = {};

    Object.entries(obj).forEach(([key, value]) => {
      const compactedValue = compactObject(value);
      if (!compactedValue) return;
      result[key] = compactedValue;
    });

    return result
  }

  return obj;
};

var jsonStringify = function (object) {
  if (typeof object === "string") return `"${object}"`;
  if (object === null || typeof object !== 'object') return String(object);

  if (Array.isArray(object)) {
    const inner = object.map(item => jsonStringify(item)).join(',');
    return `[${inner}]`;
  }

  const inner = Object.entries(object)
    .map(([key, value]) => {
      return `"${key}":${jsonStringify(value)}`;
    })
    .join(',');

  return `{${inner}}`;
};

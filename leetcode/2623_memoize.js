function memoize(fn) {
  const cache = {};
  const getKey = args => {
    return args.reduce((key, value, index) => {
      return key + value * 100000 ** index;
    });
  };

  return function (...args) {
    const key = getKey(args);

    if (cache[key] !== undefined) return cache[key];

    cache[key] = fn(...args);

    return cache[key];
  };
}

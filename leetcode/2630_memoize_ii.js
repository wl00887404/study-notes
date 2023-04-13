function memoize(fn) {
  const cacheMap = new Map();
  const last = array => array[array.length - 1];
  const set = (keys, value) => {
    let pointer = cacheMap;
    for (key of keys.slice(0, -1)) {
      if (!pointer.has(key)) pointer.set(key, new Map());

      pointer = pointer.get(key);
    }

    pointer.set(last(keys), value);
  };

  const get = keys => {
    let pointer = cacheMap;
    for (arg of args.slice(0, -1)) {
      if (!pointer.has(arg)) return undefined;

      pointer = pointer.get(arg);
    }

    return pointer.get(last(keys));
  };

  return function (...args) {
    const keys = [args.length, ...args]; // 避免 [1, 2] 和 [1, 2, 3] 產生相同的 key
    const cachedValue = get(keys);
    if (cachedValue !== undefined) return cachedValue;

    const value = fn(...args);
    set(keys, value);

    return value;
  };
}

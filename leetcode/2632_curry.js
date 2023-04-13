var curry = function (fn) {
  return function curried(...args) {
    const nextFn = fn.bind(null, ...args);

    if (nextFn.length === 0) return nextFn();

    return curry(nextFn);
  };
};

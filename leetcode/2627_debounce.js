var debounce = function (fn, t) {
  let timeout = undefined;

  return function (...args) {
    // 取消上一次的 timeout
    if (timeout) clearTimeout(timeout);
    timeout = setTimeout(() => {
      fn(...args);
      timeout = undefined;
    }, t);
  };
};

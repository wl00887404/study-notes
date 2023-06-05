var cancellable = function (fn, args, t) {
  const timeout = setTimeout(fn.bind(null, ...args), t);

  return () => clearTimeout(timeout);
};

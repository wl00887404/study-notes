var compose = function (functions) {
  if (functions.length == 0) return x => x;

  return x => {
    return functions.reduceRight((previousValue, fn) => fn(previousValue), x);
  };
};

var fibGenerator = function* () {
  let i = 0;
  let prev1 = 0;
  let prev2 = 1;

  while (true) {
    if (i === 0) yield 0;
    if (i === 1) yield 1;
    if (i > 1) {
      const result = prev1 + prev2;
      yield result;

      prev1 = prev2;
      prev2 = result;
    }
    i++;
  }
};

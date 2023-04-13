Array.prototype.groupBy = function (fn) {
  const map = {};

  this.forEach(value => {
    const key = fn(value);
    if (map[key] == undefined) map[key] = [];
    map[key].push(value);
  });

  return map;
};

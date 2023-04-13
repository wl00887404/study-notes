Array.prototype.snail = function (rowsCount, colsCount) {
  if (this.length !== rowsCount * colsCount) return [];

  const result = [];

  for (let i = 0; i < colsCount; i++) {
    result.push(this.slice(i * rowsCount, (i + 1) * rowsCount));
    if (i % 2 === 1) result[i].reverse();
  }

  const transported = [];
  for (let i = 0; i < rowsCount; i++) {
    transported.push([]);
    for (let j = 0; j < colsCount; j++) {
      transported[i].push(result[j][i]);
    }
  }

  return transported;
};

// 同時只能有 n 個 promise 在執行
var promisePool = async function (functions, n) {
  if (functions.length === 0) return;

  return new Promise(resolve => {
    let finishedTaskCount = 0;
    let nextTaskIndex = n;

    functions.slice(0, n).forEach(fn => {
      const callNextTask = () => {
        finishedTaskCount++;
        // 大家都執行完成了！
        if (finishedTaskCount === functions.length) return resolve();

        const nextTask = functions[nextTaskIndex];
        if (!nextTask) return;
        nextTaskIndex++;
        nextTask().then(callNextTask);
      };
      fn().then(callNextTask);
    });
  });
};

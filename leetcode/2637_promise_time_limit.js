var timeLimit = function (fn, t) {
  return async function (...args) {
    return await new Promise((resolve, reject) => {
      setTimeout(() => reject('Time Limit Exceeded'), t);

      fn(...args)
        .then(result => resolve(result))
        .catch(error => reject(error));
    });
  };
};

/**
 * 這個 throttle 比較特別
 * 是如果休息期間再次觸發 fn
 * 會把參數 hold 住，等到休息結束後再執行
 * 如果休息期間多次觸發，只會執行一個 fn
 */ 

var throttle = function (fn, t) {
  let lastTimestamp = 0;
  let timeoutId;

  return function helper(...args) {
    const duration = Date.now() - lastTimestamp;
    if (duration < t) {
      if (timeoutId) clearTimeout(timeoutId);

      timeoutId = setTimeout(() => {
        lastTimestamp = Date.now();
        fn(...args);
      }, t - duration);
      return;
    }

    lastTimestamp = Date.now();
    fn(...args);
  };
};

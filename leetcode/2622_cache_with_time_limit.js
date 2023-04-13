var TimeLimitedCache = function () {
  this.valueMap = {};
  this.timeoutCallbackMap = {};
};

TimeLimitedCache.prototype.set = function (key, value, duration) {
  const prevTimeoutCallback = this.timeoutCallbackMap[key];

  this.valueMap[key] = value;
  this.timeoutCallbackMap[key] = setTimeout(() => {
    delete this.valueMap[key];
    delete this.timeoutCallbackMap[key];
  }, duration);

  if (prevTimeoutCallback) clearTimeout(prevTimeoutCallback);

  return prevTimeoutCallback !== undefined;
};

TimeLimitedCache.prototype.get = function (key) {
  return this.valueMap[key] ?? -1;
};

TimeLimitedCache.prototype.count = function () {
  return Object.values(this.valueMap).length;
};

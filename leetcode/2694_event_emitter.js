class EventEmitter {
  subscriberMap = {};
  subscribe(event, cb) {
    if (!this.subscriberMap[event]) this.subscriberMap[event] = [];
    this.subscriberMap[event].push(cb);

    return {
      unsubscribe: () => {
        const index = this.subscriberMap[event].indexOf(cb);
        this.subscriberMap[event].splice(index, 1);
      },
    };
  }

  emit(event, args = []) {
    const subscribers = this.subscriberMap[event];
    const result = [];

    if (!subscribers) return result;

    subscribers.forEach(cb => {
      result.push(cb(...args));
    });

    return result;
  }
}

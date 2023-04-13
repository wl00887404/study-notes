/**
 * 其實我也不知道這題是要幹嘛
 */
var checkIfInstanceOf = function (obj, classFunction) {
  if (obj === null || obj === undefined) return false;
  if (typeof classFunction != 'function') return false;
  if (classFunction == Object) return true;
  if (classFunction === Symbol) return typeof obj == 'symbol';
  if (classFunction === Boolean) return typeof obj == 'boolean';
  if (classFunction === Number) return typeof obj == 'number';
  if (classFunction === String) return typeof obj == 'string';

  return obj instanceof classFunction;
};


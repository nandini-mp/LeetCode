/**
 * @param {Array} arr
 * @param {Function} fn //returns a number for each item in arr
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    return [...arr].sort((a,b)=>fn(a)-fn(b));
};
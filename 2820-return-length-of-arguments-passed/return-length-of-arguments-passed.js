/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    return args.length;
};

/*
var argumentsLength = function(...args) {
    let count=0;
    for (let key in args)
        if (args.hasOwnProperty(key))
            count++;
    return count;
};
*/

/**
 * argumentsLength(1, 2, 3); // 3
 */
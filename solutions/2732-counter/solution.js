/**
 * @param {number} n
 * @return {Function} counter
 */

var createCounter = function(n) {
    
    //n is captured by the closure
    //each call to createCounter gets its own n
    
    return function() {

        //return curr value, then increment for next call
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */

/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {

    //store original value using closure
    return {

        toBe: function(other) {

            //check if both values are strictly equal
            if (val === other) return true;
            //throw error if values are not equal
            throw new Error("Not Equal");

        },

        notToBe: function(other) {

            //check if both values are strictly not equal
            if (val !== other) return true;
            //throw error if values are equal
            throw new Error("Equal");

        }
    }
    
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */


/**
 * @param {number[]} input
 * @return {number[]}
 */
var sortByBits = function (input) {
    const MAX_INPUT_VALUE = Math.pow(10, 4);
    const size = input.length;
    for (let i = 0; i < size; i++) {
        input[i] = input[i] + (MAX_INPUT_VALUE + 1) * countBitsOfOne(input[i]);
    }

    let comparatorAscendingOrder = (x, y) => x - y;
    input.sort((x, y) => comparatorAscendingOrder(x, y));

    for (let i = 0; i < size; i++) {
        input[i] = input[i] % (MAX_INPUT_VALUE + 1);
    }
    return input;
};

/**
 * @param {number} intValue
 * @return {number}
 */
function countBitsOfOne(intValue) {
    let totalBitsOfOne = 0;
    while (intValue > 0) {
        totalBitsOfOne += intValue & 1;
        intValue >>= 1;
    }
    return totalBitsOfOne;
}

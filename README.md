# LeetCode Questions CPP and Python
<br>

## Question 224: Basic Calculator
Given a string `s` representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
**Note:** You are **not** allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

Examples:
- `
Input: s = "1 + 1"
Output: 2
`<br>
- `
Input: s = " 2-1 + 2 "
Output: 3
`<br>
- `
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
`

<br>

## Question 432: All O'one Data Structure
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:
* `AllOne()` Initializes the object of the data structure.
* `inc(String key)` Increments the count of the string `key` by `1`. If `key` does not exist in the data structure, insert it with count `1`.
* `dec(String key)` Decrements the count of the string `key` by `1`. If the count of `key` is `0` after the decrement, remove it from the data structure. It is guaranteed that `key` exists in the data structure before the decrement.
* `getMaxKey()` Returns one of the keys with the maximal count. If no element exists, return an empty string `""`.
* `getMinKey()` Returns one of the keys with the minimum count. If no element exists, return an empty string `""`.

// Returns the first character of the string str
var firstCharacter = function (str) {
  return str.slice(0, 1);
};

// Returns the last character of a string str
var lastCharacter = function (str) {
  return str.slice(-1);
};

// Returns the string that results from removing the first
//  and last characters from str
var middleCharacters = function (str) {
  return str.slice(1, -1);
};

var isPalindrome = function (str) {
  // base case #1
  if (str.length <= 1) {
    return true;
  }
  // base case #2
  if (firstCharacter(str) !== lastCharacter(str)) {
    return false;
  }
  // recursive case
  return isPalindrome(middleCharacters(str));
};

var checkPalindrome = function (str) {
  console.log("Is this word a palindrome? " + str);
  console.log(isPalindrome(str));
};
// Case #1
checkPalindrome("a");
// Case #2
checkPalindrome("motor");
// Case #3
checkPalindrome("rotor");
checkPalindrome("adaada");
checkPalindrome("aaaa");
checkPalindrome("addakdkl");

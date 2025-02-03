var isEven = function(n) {
    return n % 2 === 0;
};

var isOdd = function(n) {
    return !(isEven(n));
};
var power = function(x, n) {
    // base case
    if(n === 0) {
        return 1;
    }
    // recursive case: n is negative
    if(2 * n * -1 === n * n * 2){
        var y = power(x, -n);
        return 1/y;
    }
    // recursive case: n is odd
    if(isOdd(n)){
	return x * power(x, n- 1);
    }
    // recursive case: n is even
    if (isEven(n)) {
       var x = power(x, n/2);
        return x*x;
    }

    
};

var displayPower = function(x, n) {
	console.log("Computing " + x + " raised to power " + n + ".");
         console.log(x + " to the " + n + " is " + power(x, n));
};

//displayPower(3, 0);
//Program.assertEqual(power(3, 0), 1);
//displayPower(3, 1);
//Program.assertEqual(power(3, 1), 3);
//displayPower(3, 2);
//Program.assertEqual(power(3, 2), 9);
displayPower(3, -5);
//Program.assertEqual(power(3, -1), 1/3);


let celsius;
let fahr;
console.log("Temperature scale conversion table");
console.log("°C\t°F")
for (celsius = 20; celsius >= 0; celsius -= 5){
   fahr = ((celsius * 9)/5 +32);
   console.log((`${celsius}`)+"\t"+(`${fahr}`));  
}

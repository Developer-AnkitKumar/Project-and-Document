//java scripe using the first code for Variable:

//Automatically var
// x = 5;
// y = 6;
// z = x + y;
// console.log(z);

//using var
// var x = 5;
// var y = 6;
// var z = x + y;
// // console.log(x + y);
// console.log(z);

//using let
// let x = 5;
// let y = 6;
// let z = x + y;
// console.log(z);

//usin Const
// const price1 = 5;
// const price2 = 4;
// const total = price1 + price2;  //print function 
// // let total = price1 + price2;  //print function
// console.log(total);  //output variable.

const accountId = 122345   //does not change the value:fixed value
var accountName = "Ankit kumar"
let accountEmail = "apal66860@gmaill.com"
var accountPassword = "221204"
accountCity = "varanasi"

// accountId = 122345  // type error: Assignment to constant variable;
// console.log(accountId);

accountEmail = "apal66860@gmaill.com"
accountName = "Ankit kumar"
accountPassword = "2212204"
accountCity = "varanasi"
let accountState  // ydi variable ko define nhi kiya jaye to javaSript ise (undefine) declare kr deta hai

console.table([accountEmail, accountName, accountPassword, accountCity, accountState]);


/*
Prefer not to use Var(Variable);
because of issue in block scope and functional scope;
onlY using Let and Const:
*/
var cpp = require('./build/Release/nQueens');
var js = require('./nQueens');

var n = process.argv[2];

console.time('C++');
console.log(cpp.nQueens(n));
console.timeEnd('C++');

console.time('JavaScript');
console.log(js.nQueens(n));
console.timeEnd('JavaScript');

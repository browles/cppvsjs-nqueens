var cpp = require('./build/Release/nQueens');
var js = require('./js/nQueens');

var n = process.argv[2];

console.time('C++');
console.log(cpp.nQueens(n));
console.timeEnd('C++');

console.time('js');
console.log(js.nQueens(n));
console.timeEnd('js');

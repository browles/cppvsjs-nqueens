function sub_nQueens(left, center, right, nMask) {
  var count = 0;
  if (nMask == center) return 1;
  var open = ~(left | center | right) & nMask;
  var next;
  while (open) {
    next = open & -open;
    open ^= next;
    count += sub_nQueens((left | next) << 1, center | next, (right | next) >> 1, nMask);
  }

  return count;
}

function nQueens(n) {
  var nMask = (1 << n) - 1;

  var count = 0;

  var open = nMask;
  var half = (1 << (n >> 1)) - 1;
  var next;

  while (open & half) {
    next = open & -open;
    open ^= next;
    count += sub_nQueens(next << 1, next, next >> 1, nMask);
  }

  next = 1 << (n >> 1);
  return n % 2 == 0 ? 2 * count : 2 * count + sub_nQueens(next << 1, next, next >> 1, nMask);
}

module.exports = {nQueens: nQueens};

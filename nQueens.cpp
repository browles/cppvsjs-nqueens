// #include <iostream>
#include <node.h>

using v8::FunctionCallbackInfo;
using v8::HandleScope;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::Number;
using v8::Value;

long sub_nQueens(long left, long center, long right, int nMask) {
    long count = 0;
    if (nMask == center) return 1;
    long open = ~(left | center | right) & nMask;
    long next;
    while (open) {
        next = open & -open;
        open ^= next;
        count += sub_nQueens((left | next) << 1, center | next, (right | next) >> 1, nMask);
    }

    return count;
}

long nQueens(int n) {
    long nMask = (1 << n) - 1;

    long count = 0;

    long open = nMask;
    long half = (1 << (n >> 1)) - 1;
    long next;

    while (open & half) {
        next = open & -open;
        open ^= next;
        count += sub_nQueens(next << 1, next, next >> 1, nMask);
    }

    next = 1 << (n >> 1);
    return n % 2 == 0 ? 2 * count : 2 * count + sub_nQueens(next << 1, next, next >> 1, nMask);
}

void Method(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    int n = args[0]->NumberValue();
    args.GetReturnValue().Set(Number::New(isolate, nQueens(n)));
}

void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "nQueens", Method);
}

NODE_MODULE(nQueens, init)

// int main() {
//     using namespace std;
//     cout << nQueens(13) << endl;
//     return 0;
// }
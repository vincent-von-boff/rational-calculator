Rational Calculator
---------------------
Terminal calculator that uses arbitrary precision rational numbers for exact calculations.

**Features:**

- it doesn't use floats. Slower, but precise
- numbers only limited in size by the machine

Status
-------
Not a working app yet, but you can get a taste of what it can do by running:

```Bash
>> make run-test
```

The following output shows the 1000th Fibonacci number, calculated by the app, which is much larger than the largest possible number using uint64. The largest 64bit unsigned integer is 18446744073709551615, or approximately 18 quintillion, and hence the largest Fibonacci number that can be held in a 64bit register is the 93th (approximately 12 quintillion).

```Bash
>> make run-test
./decimal_integer_test.c

test_sum_dec_int
--PASS: 185936927 == 185936927

fib_test
fib(100)
--PASS: 354224848179261915075 == 354224848179261915075
fib(1000)
--PASS: 4346655768693745643568852767504062580256466051737178040248172908953655541794905189040387984007925516929592259308
0322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875 == 4346655768693745643
568852767504062580256466051737178040248172908953655541794905189040387984007925516929592259308032263477520968962323987332
2471161642996440906533187938298969649928516003704476137795166849228875
```

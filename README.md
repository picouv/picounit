PicoUnit
========

PicoUnit is a minimal, yet powerful unit testing framework written in C99. Due to its small footprint, PicoUnit is suitable for embedded as well as general development.

API
--------

#### PICO_ASSERT(expr)

Asserts that the given expression evaluates to `true`. If the expression evalutes to `false`, execution of the current test and containing test suite aborts.

- expr - The expression to evaluate

#### PICO_ASSERT_EQ(left_expr, right_expr)

Asserts that the given expressions evaluates are equal. If the expressions are not equal, execution of the current test and containing test suite aborts.

- left_expr  An expression to compare
- right_expr An expression to compare

#### PICO_ASSERT_STR_EQ(left_str, right_str)

- left_str  A string to compare
- right_str A string to compare

#### PICO_RUN_TEST(p_test)

Runs a unit test function.

- p_test The test function to execute

#### PICO_RUN_TEST_ST(p_test, p_setup, p_teardown)

Runs a unit test function with setup and teardown functions.

- p_test The test function to execute
- p_setup Setup function that is run before the test function
- p_teardown Teardown function that is run after the test function

#### PICO_RUN_SUITE(p_suite)

- p_suite The test suite functionto run

Example
--------

```c
#include <picounit.h>

// Passing test.
bool 
test1 ()
{
    PICO_ASSERT(2 + 2 == 4);                // Simple boolean assertion (ok)
    PICO_ASSERT_EQ(2 + 2, 4);               // Equivalent to the above (ok)
    PICO_ASSERT_EQ_STR("apples", "apples"); // String equality assertion (ok)
    return true;
}

// Failing test.
bool 
test2 ()
{
    PICO_ASSERT(1 == 0);                     // Simple boolean assertion (fails)
    PICO_ASSERT_EQ_STR("apples", "oranges"); // String equality assertion 
                                             // (fails but never called)
    return true;
}

// Mixed results.
bool 
test3 ()
{
    PICO_ASSERT(2 + 2 == 4);                 // Simple boolean assertion (ok)
    PICO_ASSERT_EQ_STR("apples", "oranges"); // String equality assertion 
                                             // (fails)
    return true;
}

// Test suite container function (multiple test suits can be specified.
void
test_suite()
{
    PICO_RUN_TEST(test1);
    PICO_RUN_TEST(test2);
    PICO_RUN_TEST(test3);
}

int
main (int argc, char* argv[])
{
    PICO_RUN_SUITE(test_suite);
    PICO_PRINT_STATS();
    return 0;
}
```

## License
Copyright (c) 2019 James McLean  
Licensed under the MIT license

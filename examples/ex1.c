/*=============================================================================
 * MIT License
 *
 * Copyright (c) 2019 James McLean
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
=============================================================================*/

/**
 * For a more complete demonstration, see ex2.c
 */

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

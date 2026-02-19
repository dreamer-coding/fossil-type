/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * performance, cross-platform applications and libraries. The code contained
 * This file is part of the Fossil Logic project, which aims to develop high-
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include <fossil/pizza/framework.h>

#include "fossil/type/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define the test suite and add test cases
FOSSIL_SUITE(cpp_types_suite);

// Setup function for the test suite
FOSSIL_SETUP(cpp_types_suite) {
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(cpp_types_suite) {
    // Teardown code here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test: fossil::type::I8 class
FOSSIL_TEST(cpp_test_class_I8) {
    using fossil::type::I8;
    I8 a(-128), b(127), c;
    c = a + b;
    ASSUME_ITS_EQUAL_I32((int8_t)c, -1);
    c = b - a;
    ASSUME_ITS_EQUAL_I32((int8_t)c, 255); // overflow, but int8_t wraps
    c = a * I8(2);
    ASSUME_ITS_EQUAL_I32((int8_t)c, 0);
    c = b / I8(2);
    ASSUME_ITS_EQUAL_I32((int8_t)c, 63);
    c += I8(1);
    ASSUME_ITS_EQUAL_I32((int8_t)c, 64);
    c -= I8(2);
    ASSUME_ITS_EQUAL_I32((int8_t)c, 62);
    c *= I8(2);
    ASSUME_ITS_EQUAL_I32((int8_t)c, 124);
    c /= I8(2);
    ASSUME_ITS_EQUAL_I32((int8_t)c, 62);
    ASSUME_ITS_TRUE(a < b);
    ASSUME_ITS_TRUE(b > a);
    ASSUME_ITS_TRUE(a <= b);
    ASSUME_ITS_TRUE(b >= a);
    ASSUME_ITS_TRUE(a != b);
    ASSUME_ITS_TRUE(a == I8(-128));
}

// Test: fossil::type::U16 class
FOSSIL_TEST(cpp_test_class_U16) {
    using fossil::type::U16;
    U16 a(1000), b(2000), c;
    c = a + b;
    ASSUME_ITS_EQUAL_I32((uint16_t)c, 3000);
    c = b - a;
    ASSUME_ITS_EQUAL_I32((uint16_t)c, 1000);
    c = a * U16(2);
    ASSUME_ITS_EQUAL_I32((uint16_t)c, 2000);
    c = b / U16(2);
    ASSUME_ITS_EQUAL_I32((uint16_t)c, 1000);
    c += U16(24);
    ASSUME_ITS_EQUAL_I32((uint16_t)c, 1024);
    c -= U16(24);
    ASSUME_ITS_EQUAL_I32((uint16_t)c, 1000);
    c *= U16(3);
    ASSUME_ITS_EQUAL_I32((uint16_t)c, 3000);
    c /= U16(3);
    ASSUME_ITS_EQUAL_I32((uint16_t)c, 1000);
    ASSUME_ITS_TRUE(a < b);
    ASSUME_ITS_TRUE(b > a);
    ASSUME_ITS_TRUE(a <= b);
    ASSUME_ITS_TRUE(b >= a);
    ASSUME_ITS_TRUE(a != b);
    ASSUME_ITS_TRUE(a == U16(1000));
}

// Test: fossil::type::H32, O16, B8 classes
FOSSIL_TEST(cpp_test_class_HOB_types) {
    using fossil::type::H32;
    using fossil::type::O16;
    using fossil::type::B8;
    H32 h(0xDEADBEEF);
    ASSUME_ITS_TRUE((uint32_t)h == 0xDEADBEEF);
    H32 h2 = h + H32(1);
    ASSUME_ITS_TRUE((uint32_t)h2 == 0xDEADBEF0);
    O16 o(0777);
    ASSUME_ITS_TRUE((uint16_t)o == 511);
    O16 o2 = o * O16(2);
    ASSUME_ITS_TRUE((uint16_t)o2 == 1022);
    B8 b(0b10101010);
    ASSUME_ITS_TRUE((uint8_t)b == 170);
    B8 b2 = b ^ B8(0b11110000);
    ASSUME_ITS_TRUE((uint8_t)b2 == (170 ^ 0b11110000));
}

// Test: fossil::type::F32 and F64 classes
FOSSIL_TEST(cpp_test_class_F32_F64) {
    using fossil::type::F32;
    using fossil::type::F64;
    F32 a(0.5f), b(0.25f), c;
    c = a + b;
    ASSUME_ITS_TRUE((float)c > 0.74f && (float)c < 0.76f);
    c = a - b;
    ASSUME_ITS_TRUE((float)c > 0.24f && (float)c < 0.26f);
    c = a * b;
    ASSUME_ITS_TRUE((float)c > 0.124f && (float)c < 0.126f);
    c = a / b;
    ASSUME_ITS_TRUE((float)c > 1.99f && (float)c < 2.01f);
    c += F32(0.25f);
    ASSUME_ITS_TRUE((float)c > 2.24f && (float)c < 2.26f);
    c -= F32(0.25f);
    ASSUME_ITS_TRUE((float)c > 1.99f && (float)c < 2.01f);
    c *= F32(2.0f);
    ASSUME_ITS_TRUE((float)c > 3.99f && (float)c < 4.01f);
    c /= F32(2.0f);
    ASSUME_ITS_TRUE((float)c > 1.99f && (float)c < 2.01f);

    F64 d(3.14), e(2.0), f;
    f = d + e;
    ASSUME_ITS_TRUE((double)f > 5.13 && (double)f < 5.15);
    f = d - e;
    ASSUME_ITS_TRUE((double)f > 1.13 && (double)f < 1.15);
    f = d * e;
    ASSUME_ITS_TRUE((double)f > 6.27 && (double)f < 6.29);
    f = d / e;
    ASSUME_ITS_TRUE((double)f > 1.56 && (double)f < 1.58);
}

// Test: fossil::type::Usize and Isize classes
FOSSIL_TEST(cpp_test_class_Usize_Isize) {
    using fossil::type::Usize;
    using fossil::type::Isize;
    Usize ua(100), ub(200), uc;
    uc = ua + ub;
    ASSUME_ITS_TRUE((size_t)uc == 300);
    uc = ub - ua;
    ASSUME_ITS_TRUE((size_t)uc == 100);
    uc = ua * Usize(2);
    ASSUME_ITS_TRUE((size_t)uc == 200);
    uc = ub / Usize(2);
    ASSUME_ITS_TRUE((size_t)uc == 100);

    Isize ia(-100), ib(200), ic;
    ic = ia + ib;
    ASSUME_ITS_TRUE((ptrdiff_t)ic == 100);
    ic = ib - ia;
    ASSUME_ITS_TRUE((ptrdiff_t)ic == 300);
    ic = ia * Isize(-2);
    ASSUME_ITS_TRUE((ptrdiff_t)ic == 200);
    ic = ib / Isize(2);
    ASSUME_ITS_TRUE((ptrdiff_t)ic == 100);
}

// Test: fossil::type::Char_t and Cstr classes
FOSSIL_TEST(cpp_test_class_Char_t_Cstr) {
    using fossil::type::Char_t;
    using fossil::type::Cstr;
    Char_t c('Z');
    ASSUME_ITS_EQUAL_I32((char)c, 'Z');
    Char_t c2;
    c2 = 'A';
    ASSUME_ITS_EQUAL_I32((char)c2, 'A');
    ASSUME_ITS_TRUE(c != c2);
    ASSUME_ITS_TRUE(c > c2);

    Cstr s("fossil");
    ASSUME_ITS_EQUAL_CSTR((const char*)s, "fossil");
    Cstr s2;
    s2 = "logic";
    ASSUME_ITS_EQUAL_CSTR((const char*)s2, "logic");
    ASSUME_ITS_TRUE(s != s2);
}

// Test: fossil::type::Ptr, Cptr, Handle, Ref
FOSSIL_TEST(cpp_test_class_Ptr_Cptr_Handle_Ref) {
    using fossil::type::Ptr;
    using fossil::type::Cptr;
    using fossil::type::Handle;
    using fossil::type::Ref;
    int x = 123;
    Ptr p(&x);
    ASSUME_ITS_TRUE(*(int*)(void*)p == 123);
    Ptr p2;
    p2 = &x;
    ASSUME_ITS_TRUE(*(int*)(void*)p2 == 123);
    ASSUME_ITS_TRUE(p == p2);

    Cptr cp(&x);
    ASSUME_ITS_TRUE(*(const int*)(const void*)cp == 123);
    cp = &x;
    ASSUME_ITS_TRUE(*(const int*)(const void*)cp == 123);

    Handle h(&x);
    ASSUME_ITS_TRUE(*(int*)(void*)h == 123);
    h = &x;
    ASSUME_ITS_TRUE(*(int*)(void*)h == 123);

    Ref r(&x);
    ASSUME_ITS_TRUE(*(int*)(void*)r == 123);
    r = &x;
    ASSUME_ITS_TRUE(*(int*)(void*)r == 123);
}

// Test: fossil::type::Atom, Type_id, Symbol
FOSSIL_TEST(cpp_test_class_Atom_TypeId_Symbol) {
    using fossil::type::Atom;
    using fossil::type::Type_id;
    using fossil::type::Symbol;
    Atom a("foo");
    Atom b("foo");
    ASSUME_ITS_TRUE(a == b || strcmp((const char*)a, (const char*)b) == 0);

    Type_id t("bar");
    Symbol s("baz");
    ASSUME_ITS_EQUAL_CSTR((const char*)t, "bar");
    ASSUME_ITS_EQUAL_CSTR((const char*)s, "baz");
    Type_id t2;
    t2 = "bar";
    ASSUME_ITS_EQUAL_CSTR((const char*)t2, "bar");
    ASSUME_ITS_TRUE(t == t2);
}

// Test: fossil::type::Flags
FOSSIL_TEST(cpp_test_class_Flags) {
    using fossil::type::Flags;
    Flags f1(0b1010), f2(0b1100);
    Flags f3 = f1 | f2;
    ASSUME_ITS_TRUE((uint64_t)f3 == 0b1110);
    Flags f4 = f1 & f2;
    ASSUME_ITS_TRUE((uint64_t)f4 == 0b1000);
    Flags f5 = f1 ^ f2;
    ASSUME_ITS_TRUE((uint64_t)f5 == 0b0110);
    Flags f6 = ~f1;
    ASSUME_ITS_TRUE((uint64_t)f6 == ~0b1010ULL);
    f1 |= f2;
    ASSUME_ITS_TRUE((uint64_t)f1 == 0b1110);
    f1 &= Flags(0b0100);
    ASSUME_ITS_TRUE((uint64_t)f1 == 0b0100);
    f1 ^= Flags(0b0010);
    ASSUME_ITS_TRUE((uint64_t)f1 == 0b0110);
}

// Test: fossil::type::Node_id and Entropy
FOSSIL_TEST(cpp_test_class_NodeId_Entropy) {
    using fossil::type::Node_id;
    using fossil::type::Entropy;
    Node_id n1(123), n2(456);
    ASSUME_ITS_TRUE(n1 < n2);
    ASSUME_ITS_TRUE(n2 > n1);
    ASSUME_ITS_TRUE(n1 != n2);
    Node_id n3 = n1;
    ASSUME_ITS_TRUE(n3 == n1);

    Entropy e1(0.5), e2(0.25), e3;
    e3 = e1 + e2;
    ASSUME_ITS_TRUE((double)e3 > 0.74 && (double)e3 < 0.76);
    e3 = e1 - e2;
    ASSUME_ITS_TRUE((double)e3 > 0.24 && (double)e3 < 0.26);
    e3 = e1 * e2;
    ASSUME_ITS_TRUE((double)e3 > 0.124 && (double)e3 < 0.126);
    e3 = e1 / e2;
    ASSUME_ITS_TRUE((double)e3 > 1.99 && (double)e3 < 2.01);
    e3 += Entropy(0.25);
    ASSUME_ITS_TRUE((double)e3 > 2.24 && (double)e3 < 2.26);
    e3 -= Entropy(0.25);
    ASSUME_ITS_TRUE((double)e3 > 1.99 && (double)e3 < 2.01);
    e3 *= Entropy(2.0);
    ASSUME_ITS_TRUE((double)e3 > 3.99 && (double)e3 < 4.01);
    e3 /= Entropy(2.0);
    ASSUME_ITS_TRUE((double)e3 > 1.99 && (double)e3 < 2.01);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_types_tests) {
    FOSSIL_TEST_ADD(cpp_types_suite, cpp_test_class_I8);
    FOSSIL_TEST_ADD(cpp_types_suite, cpp_test_class_U16);
    FOSSIL_TEST_ADD(cpp_types_suite, cpp_test_class_HOB_types);
    FOSSIL_TEST_ADD(cpp_types_suite, cpp_test_class_F32_F64);
    FOSSIL_TEST_ADD(cpp_types_suite, cpp_test_class_Usize_Isize);
    FOSSIL_TEST_ADD(cpp_types_suite, cpp_test_class_Char_t_Cstr);
    FOSSIL_TEST_ADD(cpp_types_suite, cpp_test_class_Ptr_Cptr_Handle_Ref);
    FOSSIL_TEST_ADD(cpp_types_suite, cpp_test_class_Atom_TypeId_Symbol);
    FOSSIL_TEST_ADD(cpp_types_suite, cpp_test_class_Flags);
    FOSSIL_TEST_ADD(cpp_types_suite, cpp_test_class_NodeId_Entropy);

    FOSSIL_TEST_REGISTER(cpp_types_suite);
}

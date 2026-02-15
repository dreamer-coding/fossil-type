/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#ifndef FOSSIL_TYPE_TRIBOOL_H
#define FOSSIL_TYPE_TRIBOOL_H

#ifdef __cplusplus
extern "C" {
#endif

/* ======================================================
 * Type Definition
 * ====================================================== */

typedef enum fossil_type_tribool {
    FOSSIL_TYPE_TRIBOOL_FALSE = 0,
    FOSSIL_TYPE_TRIBOOL_TRUE  = 1,
    FOSSIL_TYPE_TRIBOOL_UNKNOWN = 2
} fossil_type_tribool;

typedef fossil_type_tribool tribool;

/* ======================================================
 * Constructors
 * ====================================================== */

tribool fossil_type_tribool_make_true(void);
tribool fossil_type_tribool_make_false(void);
tribool fossil_type_tribool_make_unknown(void);

/* ======================================================
 * Predicates
 * ====================================================== */

int fossil_type_tribool_is_true(tribool t);
int fossil_type_tribool_is_false(tribool t);
int fossil_type_tribool_is_unknown(tribool t);

/* ======================================================
 * Logic
 * ====================================================== */

tribool fossil_type_tribool_and(tribool a, tribool b);
tribool fossil_type_tribool_or (tribool a, tribool b);
tribool fossil_type_tribool_not(tribool t);

#ifdef __cplusplus
}
#endif


/* ======================================================
 * C++ Wrapper
 * ====================================================== */
#ifdef __cplusplus

namespace fossil::type {

class Tribool {
    tribool value;

public:
    Tribool() : value(fossil_type_tribool_make_unknown()) {}
    explicit Tribool(tribool v) : value(v) {}

    bool is_true() const    { return fossil_type_tribool_is_true(value); }
    bool is_false() const   { return fossil_type_tribool_is_false(value); }
    bool is_unknown() const { return fossil_type_tribool_is_unknown(value); }

    Tribool operator!() const {
        return Tribool(fossil_type_tribool_not(value));
    }

    Tribool operator&&(const Tribool& rhs) const {
        return Tribool(fossil_type_tribool_and(value, rhs.value));
    }

    Tribool operator||(const Tribool& rhs) const {
        return Tribool(fossil_type_tribool_or(value, rhs.value));
    }

    operator tribool() const { return value; }
};

} // namespace fossil::type

#endif

#endif

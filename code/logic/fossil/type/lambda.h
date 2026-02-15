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
#ifndef FOSSIL_TYPE_LAMBDA_H
#define FOSSIL_TYPE_LAMBDA_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*fossil_type_lambda_fn)(void* context);

typedef struct fossil_type_lambda {
    fossil_type_lambda_fn fn;
    void* context;
} fossil_type_lambda;

typedef fossil_type_lambda lambda;

/* Construction */
lambda fossil_type_lambda_make(fossil_type_lambda_fn fn, void* ctx);

/* Execution */
void fossil_type_lambda_call(const lambda* l);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
namespace fossil::type {

class Lambda {
    lambda l;
public:
    Lambda(fossil_type_lambda_fn fn, void* ctx=nullptr){
        l=fossil_type_lambda_make(fn,ctx);
    }
    void operator()() const { fossil_type_lambda_call(&l); }
};

}
#endif

#endif

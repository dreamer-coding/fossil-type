
#ifndef FOSSIL_TYPE_ATTRIBUTES_H
#define FOSSIL_TYPE_ATTRIBUTES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/* ======================================================
 * Attribute Value
 * ====================================================== */

typedef enum fossil_type_attribute_kind {
    FOSSIL_TYPE_ATTRIBUTE_NONE = 0,
    FOSSIL_TYPE_ATTRIBUTE_INT,
    FOSSIL_TYPE_ATTRIBUTE_FLOAT,
    FOSSIL_TYPE_ATTRIBUTE_STRING,
    FOSSIL_TYPE_ATTRIBUTE_PTR
} fossil_type_attribute_kind;

typedef struct fossil_type_attribute_value {
    fossil_type_attribute_kind kind;
    union {
        long long   i;
        long double f;
        const char* s;
        void*       p;
    } data;
} fossil_type_attribute_value;

/* ======================================================
 * Attribute Entry
 * ====================================================== */

typedef struct fossil_type_attribute {
    const char* key;
    fossil_type_attribute_value value;
} fossil_type_attribute;

typedef fossil_type_attribute attribute;

/* ======================================================
 * Attribute Table
 * ====================================================== */

typedef struct fossil_type_attribute_table {
    const char* type_id;
    attribute*  attributes;
    size_t      count;
} fossil_type_attribute_table;

/* ======================================================
 * Registration
 * ====================================================== */

int fossil_type_attributes_register(
    fossil_type_attribute_table* table);

/* ======================================================
 * Queries
 * ====================================================== */

const attribute*
fossil_type_attributes_get(
    const char* type_id,
    const char* key);

int fossil_type_attributes_has(
    const char* type_id,
    const char* key);

#ifdef __cplusplus
}
#endif


/* ======================================================
 * C++ Wrapper
 * ====================================================== */
#ifdef __cplusplus

namespace fossil::type {

class AttributeValue {
    fossil_type_attribute_value v;
public:
    AttributeValue(){ v.kind=FOSSIL_TYPE_ATTRIBUTE_NONE; }

    static AttributeValue from_int(long long x){
        AttributeValue r; r.v.kind=FOSSIL_TYPE_ATTRIBUTE_INT; r.v.data.i=x; return r;
    }

    static AttributeValue from_float(long double x){
        AttributeValue r; r.v.kind=FOSSIL_TYPE_ATTRIBUTE_FLOAT; r.v.data.f=x; return r;
    }

    static AttributeValue from_string(const char* x){
        AttributeValue r; r.v.kind=FOSSIL_TYPE_ATTRIBUTE_STRING; r.v.data.s=x; return r;
    }

    static AttributeValue from_ptr(void* x){
        AttributeValue r; r.v.kind=FOSSIL_TYPE_ATTRIBUTE_PTR; r.v.data.p=x; return r;
    }

    const fossil_type_attribute_value* raw() const { return &v; }
};

class Attributes {
public:
    static const attribute* get(const char* type,const char* key){
        return fossil_type_attributes_get(type,key);
    }

    static bool has(const char* type,const char* key){
        return fossil_type_attributes_has(type,key)!=0;
    }
};

} // namespace fossil::type

#endif

#endif

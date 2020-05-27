#include "register_types.h"

#include "core/class_db.h"
#include "parsecgd.h"

void register_parsec_types() {
    ClassDB::register_class<ParsecGD>();
    ClassDB::register_class<ParsecGDHostConfig>();
}

void unregister_parsec_types() {

}
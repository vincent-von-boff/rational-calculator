#ifndef BOOLEAN_H
#define BOOLEAN_H

typedef enum{
    FALSE = 0,
    TRUE = 1
} Boolean;

Boolean and_bool(Boolean, Boolean);

Boolean or_bool(Boolean, Boolean);

char* boolean_to_str(Boolean);

#endif

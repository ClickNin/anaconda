#ifndef ALTERABLES_H
#define ALTERABLES_H

// for size_t
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

#define ALT_VALUES 26
#define ALT_STRINGS 10

class AlterableValues
{
public:
    double values[ALT_VALUES];

    AlterableValues()
    {
        for (int i = 0; i < ALT_VALUES; i++) {
            values[i] = 0.0;
        }
    }

    double get(size_t index)
    {
        if (index >= ALT_VALUES)
            return 0.0;
        return values[index];
    }

    int get_int(size_t index)
    {
        return int(get(index));
    }

    void set(size_t index, double value)
    {
        if (index >= ALT_VALUES)
            return;
        values[index] = value;
    }

    void add(size_t index, double value)
    {
        set(index, get(index) + value);
    }

    void sub(size_t index, double value)
    {
        set(index, get(index) - value);
    }

    void set(const AlterableValues & v)
    {
        memcpy(values, v.values, ALT_VALUES*sizeof(double));
    }
};

class AlterableStrings
{
public:
    std::string values[ALT_STRINGS];

    AlterableStrings()
    {
    }

    const std::string & get(size_t index)
    {
        if (index >= ALT_STRINGS) {
            static std::string empty;
            return empty;
        }
        return values[index];
    }

    void set(size_t index, const std::string & value)
    {
        if (index >= ALT_STRINGS)
            return;
        values[index] = value;
    }

    void set(const AlterableStrings & v)
    {
        for (int i = 0; i < ALT_STRINGS; i++) {
            values[i] = v.values[i];
        }
    }
};

class AlterableFlags
{
public:
    unsigned int flags;

    AlterableFlags()
    : flags(0)
    {
    }

    void enable(int index)
    {
        flags |= 1 << index;
    }

    void disable(int index)
    {
        flags &= ~(1 << index);
    }

    void toggle(int index)
    {
        flags ^= 1 << index;
    }

    bool is_on(int index)
    {
        return (flags & (1 << index)) != 0;
    }

    bool is_off(int index)
    {
        return (flags & (1 << index)) == 0;
    }

    int get(int index)
    {
        return int(is_on(index));
    }
};

class Alterables
{
public:
    AlterableStrings strings;
    AlterableValues values;
    AlterableFlags flags;
};

#endif // ALTERABLES_H

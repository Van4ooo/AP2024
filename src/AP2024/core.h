#ifndef AP2024_CORE_H
#define AP2024_CORE_H

#include <ctime>
#include <string>
#include <cstddef>

class SortsCore{
public:
    size_t swap_counter=0;
    size_t set_counter=0;
    size_t array_access=0;
    size_t memory_req=0;
    float sort_t=0;

    static void rand_array(int *, size_t&);

    void swap(int *, int *);
    void set(int *, int);
    int get(int *, size_t);
    int* create_array(size_t);

    virtual void cpp_run(int *, size_t);
    void cpp_mode_run(size_t, std::string);

    void new_measurement();
};

#endif
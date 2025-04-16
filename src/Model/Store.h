#ifndef ANTHILL_SIMULATION_STORE_H
#define ANTHILL_SIMULATION_STORE_H

namespace Model {
    class Store {
    private:
        size_t capacity;
        size_t supplies;
    public:
        explicit Store(int capacity, int supplies);
        Store() = delete;
        void increase(size_t val);

        void decrease(size_t val);

        void update_capacity(size_t new_capacity);

        size_t get_supplies() const;

        size_t get_capacity() const;

        bool is_empty() const;
    };

}


#endif //ANTHILL_SIMULATION_STORE_H

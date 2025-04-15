#ifndef ANTHILL_SIMULATION_STORE_H
#define ANTHILL_SIMULATION_STORE_H

namespace Model {
    class Store {
    private:
        int capacity;
        int supplies;
    public:
        explicit Store(int capacity);
        Store() = delete;
        void increase(int val);

        void decrease(int val);

        void update_capacity(int val);

        int get_supplies() const;

        bool is_empty() const;
    };

}


#endif //ANTHILL_SIMULATION_STORE_H

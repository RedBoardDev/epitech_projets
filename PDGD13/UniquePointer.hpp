/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD13-thomas.ott
** File description:
** UniquePointer.hpp
*/

template <typename T>
class UniquePointer
{
    public:
        UniquePointer() { _ptr = nullptr; };
        UniquePointer(T *ptdr) { _ptr = ptdr; };
        ~UniquePointer() {_ptr != nullptr ? delete _ptr : void(); };
        void reset() { _ptr = (_ptr != nullptr ? delete _ptr, nullptr : nullptr); };
        T *get() { return _ptr; };
        T *operator->() { return _ptr; };
        void operator=(T *ptdr) { _ptr = (_ptr != nullptr ? delete _ptr, ptdr : ptdr);  };
    private:
        T *_ptr;
};

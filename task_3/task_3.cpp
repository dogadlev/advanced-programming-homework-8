#include <iostream>

template <class T>
class u_ptr
{
public:
    u_ptr() = default;
    u_ptr(T *ptr_) : ptr(ptr_) {}
    u_ptr(const u_ptr &other) = delete;
    ~u_ptr() { delete ptr; }

    const T &operator*() const { return *ptr; }

    T &operator*() { return *ptr; }

    u_ptr &operator=(const u_ptr &other) = delete;

    T *release()
    {
        T *tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

private:
    T *ptr = nullptr;
};

int main(int argc, char **argv)
{
    //u_ptr<T> class test.
    std::string *inPtr = new std::string("bar");
    std::cout << inPtr << std::endl;
    
    u_ptr<std::string> ptr(inPtr);
    std::cout << *ptr << std::endl;
    
    std::string *otherPtr = ptr.release();
    std::cout << otherPtr << std::endl;

    return 0;
}
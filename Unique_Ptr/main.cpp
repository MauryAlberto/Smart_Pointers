#include <iostream>

template <typename T>
class UniquePtr
{
    public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}

    ~UniquePtr()
    {
        delete ptr;
    }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }

        return *this;
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    T* get() const { return ptr; }

    T* release()
    {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T* p = nullptr)
    {
        delete ptr;
        ptr = p;
    }

    private:
    T* ptr;
};

int main()
{
    UniquePtr<int> up1(new int(42));
    UniquePtr<int> up2 = std::move(up1);

    if(up1.get() == nullptr)
    {
        std::cout <<"up1 is null\n";
    }
    
    std::cout << "up2 value: " << *up2 << "\n";

    return 0;
}
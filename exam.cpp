template <typename T, typename Iter = std::vector<T>::iterator>

class Container {
public:
    template <typename I = Iter>
    class Iterator {
    public:
        I iter;
    };
};
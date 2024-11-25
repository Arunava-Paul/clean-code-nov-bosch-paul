class ILoggerInterface {
public:
    template <typename T>
    virtual void write(const T& message) = 0;
};

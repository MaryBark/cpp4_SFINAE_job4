#include "libSfinae.h"

//libSfinae::libSfinae()
//{

//}

template <typename T>
static std::enable_if_t<std::is_integral_v<T>, void> PrintIp(T value)
{
    static const size_t constexpr SizeInOctets = sizeof(T);
    for (size_t i = SizeInOctets; i--;)
    {
        std::cout << (value >> (i << 3) & 0xFF);
        if (i > 0)
            std::cout << OctetSeparator;
    }
    std::cout << std::endl;
}

static void PrintIp(const std::string& value)
{
    std::cout << value << std::endl;
}

template <typename T>
static void PrintIp(std::enable_if_t<is_std_vector_or_list<T>::value, const T&> container)
{
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it;
        if (it != std::prev(container.end()))
            std::cout << OctetSeparator;
    }
    std::cout << std::endl;
}

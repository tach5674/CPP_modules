#include "ScalarConverter.hpp"

enum LiteralType
{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_SPECIAL,
    TYPE_INVALID
};

static bool char_check(const std::string &str)
{
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return true;
    return false;
}

static bool int_check(const std::string &str)
{
    errno = 0;
    char *end;
    long val = strtol(str.c_str(), &end, 10);

    if (errno == ERANGE)
        return false;

    if (end == str.c_str())
        return false;

    while (*end)
    {
        if (!isspace(static_cast<unsigned char>(*end)))
            return false;
        end++;
    }

    return val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

static bool float_check(const std::string &str)
{

    if (str.find('f') == std::string::npos)
        return false;

    const char *cstr = str.c_str();
    char *end;
    errno = 0;

    strtof(cstr, &end);

    if (errno == ERANGE)
        return false;

    if (end == cstr)
        return false;

    if (*end == 'f')
        end++;

    while (*end)
    {
        if (!isspace(static_cast<unsigned char>(*end)))
            return false;
        end++;
    }

    return true;
}

static bool double_check(const std::string &str)
{
    const char *cstr = str.c_str();
    char *end;
    errno = 0;

    strtod(cstr, &end);

    if (errno == ERANGE)
        return false;

    if (end == cstr)
        return false;

    while (*end)
    {
        if (!isspace(static_cast<unsigned char>(*end)))
            return false;
        end++;
    }

    return true;
}

static LiteralType detectType(const std::string &str)
{
    if (str.empty())
        return TYPE_INVALID;

    if (char_check(str))
        return TYPE_CHAR;

    if (int_check(str))
        return TYPE_INT;

    if (float_check(str))
        return TYPE_FLOAT;

    if (double_check(str))
        return TYPE_DOUBLE;

    return TYPE_INVALID;
}

void ScalarConverter::convert(const std::string &str)
{
    char c;
    int i;
    float f;
    double d;
    const LiteralType type = detectType(str);
    char *end;

    std::cout << std::fixed << std::setprecision(1);
    switch (type)
    {
    case TYPE_CHAR:
        c = static_cast<char>(str[0]);
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        break;
    case TYPE_INT:

        i = std::strtol(str.c_str(), &end, 10);

        // Char
        std::cout << "char: ";
        if (i < 0 || i > 127)
            std::cout << "impossible";
        else if (!isprint(static_cast<char>(i)))
            std::cout << "Non displayable";
        else
            std::cout << "'" << static_cast<char>(i) << "'";
        std::cout << std::endl;

        // Int
        std::cout << "int: " << i << std::endl;

        // Float
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;

        // Double
        std::cout << "double: " << static_cast<double>(i) << std::endl;
        break;
    case TYPE_FLOAT:

        f = std::strtod((str.substr(0, str.length() - 1)).c_str(), &end);

        // Char
        std::cout << "char: ";
        if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
            std::cout << "impossible";
        else if (!isprint(static_cast<char>(f)))
            std::cout << "Non displayable";
        else
            std::cout << "'" << static_cast<char>(f) << "'";
        std::cout << std::endl;

        // Int
        std::cout << "int: ";
        if (std::isnan(f) || std::isinf(f) ||
            f < std::numeric_limits<int>::min() ||
            f > std::numeric_limits<int>::max())
            std::cout << "impossible";
        else
            std::cout << static_cast<int>(f);
        std::cout << std::endl;

        // Float
        std::cout << "float: " << f << "f" << std::endl;

        // Double
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        break;
    case TYPE_DOUBLE:

        d = std::strtod(str.c_str(), &end);

        // Char
        std::cout << "char: ";
        if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
            std::cout << "impossible";
        else if (!isprint(static_cast<char>(d)))
            std::cout << "Non displayable";
        else
            std::cout << "'" << static_cast<char>(d) << "'";
        std::cout << std::endl;

        // Int
        std::cout << "int: ";
        if (std::isnan(d) || std::isinf(d) ||
            d < std::numeric_limits<int>::min() ||
            d > std::numeric_limits<int>::max())
            std::cout << "impossible";
        else
            std::cout << static_cast<int>(d);
        std::cout << std::endl;

        // Float
        std::cout << "float: ";
        if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
            std::cout << "impossible";
        else
            std::cout << static_cast<float>(d) << "f";
        std::cout << std::endl;

        // Double
        std::cout << "double: " << d << std::endl;

        break;
    default:
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "impossible" << std::endl;
        std::cout << "double: " << "impossible" << std::endl;
        break;
    }
}

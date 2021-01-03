#ifndef CPP2CLIENT_ERRORCHECKHELPERS_H
#define CPP2CLIENT_ERRORCHECKHELPERS_H

#include <string>

namespace cpp2 {
    class ErrorCheckHelpers {
    public:
        static void throwServerError(const std::string &response);
    };
}

#endif //CPP2CLIENT_ERRORCHECKHELPERS_H

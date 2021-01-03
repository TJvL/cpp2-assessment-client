#include <stdexcept>
#include "../../include/helpers/ErrorCheckHelpers.h"
#include "../../include/Constants.h"

namespace cpp2 {

    void ErrorCheckHelpers::throwServerError(const std::string &response) {
        if (response == ERROR_NO_SUCH_DIRECTORY) {
            throw std::logic_error{"no such directory present remotely"};
        } else if (response == ERROR_NO_SUCH_FILE) {
            throw std::logic_error{"no such file present remotely"};
        } else if (response == ERROR_NO_SUCH_PATH) {
            throw std::logic_error{"no such file or directory present remotely"};
        } else if (response == ERROR_INVALID_PATH) {
            throw std::logic_error{"remote reports invalid path"};
        } else if (response == ERROR_NOT_ENOUGH_DISK_SPACE) {
            throw std::logic_error{"not enough disk space available remotely"};
        } else if (response == ERROR_NO_PERMISSION) {
            throw std::logic_error{"no permission remotely"};
        } else {
            throw std::logic_error{"unknown server response"};
        }
    }
}

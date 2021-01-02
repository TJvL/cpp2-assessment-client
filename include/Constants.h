#ifndef CPP2CLIENT_CONSTANTS_H
#define CPP2CLIENT_CONSTANTS_H

// new lines
#define NEW_LINE "\n"
#define RETURN_NEW_LINE "\r\n"

// user prompts
#define ENTER_CHOICE_PROMPT "enter choice: "
#define ENTER_TO_CONTINUE_PROMPT "press enter to continue..."
#define ENTER_DIRECTORY_PROMPT "enter path starting from root sync directory: "

// server commands
#define INFO_COMMAND "INFO"
#define DIRECTORY_LIST_COMMAND "DIR"
#define GET_COMMAND "GET"
#define PUT_COMMAND "PUT"
#define RENAME_COMMAND "REN"
#define DELETE_COMMAND "DEL"
#define MAKE_DIRECTORY_COMMAND "MKDIR"
#define QUIT_COMMAND "QUIT"

// server responses
#define OK_RESPONSE "OK"
#define ERROR_NO_SUCH_FILE "Error: no such file"
#define ERROR_NO_SUCH_DIRECTORY "Error: no such directory"
#define ERROR_NO_PERMISSION "Error: no permission"
#define ERROR_INVALID_PATH "Error: invalid path"
#define ERROR_NOT_ENOUGH_DISK_SPACE "Error: not enough disk space"

#endif //CPP2CLIENT_CONSTANTS_H

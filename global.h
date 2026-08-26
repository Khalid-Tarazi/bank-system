#pragma once
#include <iostream>
#include "clsUser.h"

inline clsUser& getCurrentUser() {
    //this is dummy object when we start the application, beacuse I can't keep the currentUser empty
    static clsUser currentUser = clsUser::find("", "");
    return currentUser;
}

// Optional: Define a macro for convenience
#define currentUser getCurrentUser()
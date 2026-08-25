#pragma once
#include <iostream>
#include "clsUser.h"

clsUser currentUser = clsUser::find("", "");  //this is dummy object when we start the application, beacuse I can't keep the currentUser empty
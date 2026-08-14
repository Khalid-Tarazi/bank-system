#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
using namespace std;

int main() {
     
    //I need to find the client without creating object using find(), if I found it I return object (client card) with client info, if not I return empty (client card) object.
    clsBankClient client1 = clsBankClient::find("A101");
    client1.print();

    clsBankClient client2 = clsBankClient::find("A101", "1234");

    system("pause>0");
    return 0;
}
#include <a_samp>
#include <sscanf2>

#define ZDC_DEFAULT_CHANNEL     "792453468581396512"
#define ZDC_PREFIX              "!"

#include "z_dccmd.inc"

main(){
    print("Test File Initiated...");
}

public OnDCCommandPerformed(args[], success)
{
    if(!success) return SendDC(Z_Discord_Channel, "You have entered a wrong command, use !help to seee the list of commands.");
    return 1;
}

ZDCCMD:test(DCC_User:user, args){
    SendDC(Z_Discord_Channel, "Test");
    return 1;
}
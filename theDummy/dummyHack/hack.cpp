#include <iostream>
#include <string>

#include "remote.h"

#define endit(s) printf("%s\n",s); exit(-1)
 
 
int main() 
{
    remote::Handle handle;
    uintptr_t memoryAddress;

    //*/// root

    if (getuid() != 0)
    {
        endit("Cannot start as NON ROOT user.");
    }

    //*/// pid

    printf("Finding process ID: \n");

    while (true)
    {
        if (remote::FindProcessByName("dummy.run", &handle)) break;
        usleep(1000);
    }

    printf("Discovered with PID: %d \n",handle.GetPid());

    //*/// reading memory

    std::cin >> std::hex >> memoryAddress;

    int varInt(0);
    if( handle.Read( (void*)memoryAddress, &varInt, sizeof(varInt) ) )
    {
        printf("varInt: %d \n",varInt);
    }
    else 
    {
        endit("varInt: FAIL");
    }

    //*/// region

    
    remote::MapModuleMemoryRegion *varInt_region = NULL;
    while (varInt_region==NULL) 
    {
        if (!handle.IsRunning())
        {
            endit("regions");
        }

        handle.ParseMaps();

        
        varInt_region = handle.GetRegionOfAddress((void*)memoryAddress);

        usleep(500);
        
    }
    varInt_region->print(handle);

    printf("OK\n");
    return 0;
}